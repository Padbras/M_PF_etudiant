#ifndef _VUE_HPP_
#define _VUE_HPP_

#include "Jeu42.hpp"

#include <gtkmm.h>
#include <vector>

class Vue
{
    private:
        // widgets gtk
        Gtk::Main _kit;
        Gtk::Window _window;
        Gtk::DrawingArea _drawing;

        // donnees du jeu et de sa gestion
        Jeu42 _jeu;
        std::vector<int> _nombres;
        int _nClic1;
        bool _aClic1;

        // placement des nombres dans l'affichage
        int _nbX, _nbY;

        // gestion de l'interface
        Glib::RefPtr<Gdk::Window> _ptrDrawingWindow;
		Cairo::RefPtr<Cairo::Context> _ptrDrawingContext;
        int _width, _height;
        int _deltaX, _deltaY;

    public:
        Vue(int argc, char ** argv);
        void executer();
        void rafraichir();
        void quitter();
        void afficherMessage(const std::string & titre, const std::string & texte); 

    private:
        bool gererExposeEvent(GdkEventExpose*);
        bool gererButtonPressEvent(GdkEventButton* ptrEvent); 

        void dessinerTexte(int x, int y, const std::string & texte);
        void dessinerCercle(int radius, int x, int y);

        void k_to_xy(int k, int & x, int & y) const;
        void xy_to_k(int x, int y, int & k) const;
};

#endif
