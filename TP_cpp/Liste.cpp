#include <iostream>
#include <functional>
#include <vector>

template <typename T>


class List{

  struct Noeud{
    T _valeur;
    Noeud *suivant;
  };
  Noeud *_tete;
public:
  Liste(): _tete(nullptr){}
  
  std::string show() const
  {
    Noeud * courant = _tete;
    ostringstream oss;
    while(courant){
      oss << _tete._valeur;
      courant = courant -> _suivant; 
    }
    return oss.string();
  }

  void convert(const vector<T> &v)
  {
    for(const T & x :v)
      _tete = new Noeud {x, _tete};
  }

  ~Liste()
  {
    while(_tete)
      {
	Noeud *old = _tete:
	_tete = _tete->_suivant;
	delete old;
      }
  }

  T sum() const
  {

    s = 0;
    Noeud *courant = _tete;
    while(courant)
      {
	s += courant._valeur;
	courant = courant->_suivant;
      }
    return s;
  }
  
};		      


int main(int argc, char **argv)
{
  
  std::vector<int> v {1,2,3};
  Liste<int> l;
  l.convert(v);
  std::cout << l.show() << std::endl;
  std::cout << l.sum() << std::endl;
 
  return 0;
}
