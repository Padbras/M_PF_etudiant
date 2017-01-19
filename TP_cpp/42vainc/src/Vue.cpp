
#include "Vue.hpp"

#include <algorithm>

Vue::Vue(int argc, char ** argv):
    _kit(argc, argv),
    _jeu("rouge", "bleu")
{
    // construit l'interface graphique
    _window.set_size_request(600, 600);
    _window.set_title("42 vainc");
    _window.add(_drawing);
    _window.show_all();

    // initialise quelques donnees pour gerer le jeu
    // TODO lambda, copy, back_inserter
    for (int n : _jeu.getNombresLibres())
        _nombres.push_back(n);
    for (int n : _jeu.getJoueur1()._nombres)
        _nombres.push_back(n);
    for (int n : _jeu.getJoueur2()._nombres)
        _nombres.push_back(n);
    std::sort(_nombres.begin(), _nombres.end());

    _nbX = 4;
    _nbY = 4;
    _aClic1 = false;

    // connecte les signaux de l'interface graphique
	_drawing.add_events(Gdk::BUTTON_PRESS_MASK);
    _drawing.signal_expose_event().connect( 
            sigc::mem_fun(*this, &Vue::gererExposeEvent) );
    _drawing.signal_button_press_event().connect( 
            sigc::mem_fun(*this, &Vue::gererButtonPressEvent) );
}

void Vue::executer() 
{
	_kit.run(_window);
}

void Vue::rafraichir()
{
	_ptrDrawingWindow->invalidate(false);
}

void Vue::quitter() 
{
	_kit.quit();
}

void Vue::afficherMessage(const std::string & titre, const std::string & texte) 
{
	Glib::ustring titreUnicode(titre.c_str());
	Glib::ustring messageUnicode(texte.c_str());
	Gtk::MessageDialog dialogue(_window, messageUnicode);
	dialogue.set_title(titreUnicode);
	dialogue.run();
}

bool Vue::gererExposeEvent(GdkEventExpose *)
{
    // met a jour les attributs pour l'affichage
    _ptrDrawingWindow = _drawing.get_window();
    _ptrDrawingContext = _ptrDrawingWindow->create_cairo_context();
    _width = _ptrDrawingWindow->get_width();
    _height = _ptrDrawingWindow->get_height();
    _deltaX = _width / _nbX;
    _deltaY = _height / _nbY;

    // dessine le fond
    _ptrDrawingContext->set_source_rgb(0.7, 0.7, 0.7);
    _ptrDrawingContext->rectangle(0, 0, _width, _height);
    _ptrDrawingContext->fill();
    _ptrDrawingContext->stroke();

    // dessine et entoure les nombres
    // TODO lambda, accumulate
    int minSize = std::min(_ptrDrawingWindow->get_width(), 
                           _ptrDrawingWindow->get_height());
    int radius = minSize / (4*_nbX);
    auto trouverNombre = [] (const liste_t & l, int n)
    {
        for (int nl : l)
            if (nl == n)
                return true;
        return false;
    };
    for (unsigned k=0; k<_nombres.size(); k++)
    {
        // dessine le nombre
        int n = _nombres[k];
        std::stringstream ss;
        ss << n;
        int x, y;
        k_to_xy(k, x, y);
        _ptrDrawingContext->set_source_rgb(0.0, 0.0, 0.0);
        dessinerTexte(x, y, ss.str());
        // encadre le nombre s'il appartient a un joueur
        _ptrDrawingContext->set_source_rgb(1.0, 0.0, 0.0);
        if (trouverNombre(_jeu.getJoueur1()._nombres, n))
            dessinerCercle(radius, x, y);
        _ptrDrawingContext->set_source_rgb(0.0, 0.0, 1.0);
        if (trouverNombre(_jeu.getJoueur2()._nombres, n))
            dessinerCercle(radius, x, y);
        _ptrDrawingContext->set_source_rgb(1.0, 1.0, 1.0);
        if (_aClic1 and n==_nClic1)
            dessinerCercle(radius, x, y);
    }

    // affiche le nom du joueur courant
    _ptrDrawingContext->set_source_rgb(0.0, 0.0, 0.0);
    dessinerTexte(_width/2, 15, _jeu.getInfo());

	return true;
}

bool Vue::gererButtonPressEvent(GdkEventButton * ptrEvent) 
{
    // recupere la position du clic
	int k;
	xy_to_k(ptrEvent->x, ptrEvent->y, k);
    // si premier clic, enregistre l'indice clique
    if (not _aClic1)
    {
        _nClic1 = _nombres[k];
        _aClic1 = true;
        rafraichir();
    }
    // si second clic, joue le coup
    else
    {
        // joue le coup
        _jeu.jouerCoup(_nClic1, _nombres[k]);
        _aClic1 = false;
        rafraichir();
        // teste si quelqu'un a gagne
        if (not _jeu.enCours())
        {
            std::stringstream ss;
            ss << "Fin du jeu : " << _jeu.getVainqueur() << " a gagné.";
            afficherMessage("Fin du jeu", ss.str());
            quitter();
        }
    }
	return true;
}

void Vue::dessinerTexte(int x, int y, const std::string & texte)
{
    // parametre la police
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_size(18*1024);
    font.set_weight(Pango::WEIGHT_BOLD);
    Glib::RefPtr<Pango::Layout> layout = _drawing.create_pango_layout(texte);
    layout->set_font_description(font);

    // dessine le texte
    int w, h;
    layout->get_pixel_size(w, h);
    _ptrDrawingContext->move_to(x-w/2, y-h/2);
    layout->show_in_cairo_context(_ptrDrawingContext);
    _ptrDrawingContext->stroke();
}

void Vue::dessinerCercle(int radius, int x, int y)
{
	_ptrDrawingContext->save();
	_ptrDrawingContext->translate(x, y);
    _ptrDrawingContext->set_line_width(4);
	_ptrDrawingContext->arc(0, 0, radius, 0, 2*M_PI);
	_ptrDrawingContext->stroke();
	_ptrDrawingContext->restore();
}

void Vue::k_to_xy(int k, int & x, int & y) const
{
    int i = k / _nbX;
    int j = k % _nbX;
    x = j*_deltaX + _deltaX/2;
    y = i*_deltaY + _deltaY/2;
}

void Vue::xy_to_k(int x, int y, int & k) const
{
    int j = (x - _deltaX/2) / (float)_deltaX + 0.5f;
    int i = (y - _deltaY/2) / (float)_deltaY + 0.5f;
    k = i*_nbX + j;
}

