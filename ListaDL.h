//
//  ListaDL.h
//  Progetto 1 Nunzio Depetro
//
//  Created by Nuccio Depetro on 08/07/21.
//

#ifndef ListaDL_h
#define ListaDL_h
#include "Cliente.h"
#include <iostream>


using namespace std;

class Nodo{
public:
    Cliente valore;
    Nodo*succ;
    Nodo*prec;
};

class ListaDL{
private:
    Nodo*testa;
    
public:
    ListaDL(){testa=nullptr;}
    ~ListaDL();
    Nodo*getTesta()const{return this->testa;}
    void inserisci(Cliente val);
    Nodo*ricerca(Cliente val);
    void rimuovi(Cliente val);
  
    friend
    ostream& operator<<(ostream& out, const ListaDL& ls);
    
};

#endif /* ListaDL_h */
