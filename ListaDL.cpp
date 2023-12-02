//
//  ListaDL.cpp
//  Progetto 1 Nunzio Depetro
//
//  Created by Nuccio Depetro on 08/07/21.
//

#include "ListaDL.h"
#include <iostream>
#include <ostream>



using namespace std;

ListaDL::~ListaDL()    {
    Nodo* iter=this->testa;

    while(iter!=nullptr)    {
        Nodo* temp= iter->succ;
        delete iter;
        iter=temp;
    }
}

ostream& operator<<(ostream& out, const ListaDL& ls)
{
    Nodo* primo;


    for(primo=ls.testa; primo!=nullptr; primo = primo->succ)
        out << primo->valore << endl;
    
    
    return out;

}


Nodo* ListaDL::ricerca(Cliente val){
    Nodo *p;

    for(p=this->testa;p!=nullptr;p = p->succ)
        if(p->valore==val)
            return p;

    return nullptr;
}

void ListaDL::inserisci(Cliente val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    if ( testa == NULL ) {
        testa = new Nodo;
      testa->valore = val;
      testa->succ = NULL;
    }
    else {
        Nodo *q;
      for ( q = this->testa; q->succ != NULL; q = q->succ );
      q->succ = new Nodo;
      q->succ->valore = val;
        q->succ->succ = NULL;
    }

}


void ListaDL::rimuovi(Cliente val)
{
    Nodo* iter = this->testa;
    Nodo* tmp;

    if (this->testa==nullptr)
        cout << "Lista vuota: impossibile rimuovere elementi \n";
    else if (this->testa->valore==val) {
        tmp=this->testa;
        this->testa=this->testa->succ;
        this->testa->prec = nullptr;
        delete tmp;
        }
    else    {
        while ((iter->succ!=nullptr) && (iter->succ->valore!=val))
            iter=iter->succ;
       
        if (iter->succ!=nullptr)    {
           tmp = iter->succ;
           if(iter->succ->succ!=nullptr)
            iter->succ->succ->prec = iter;
           iter->succ = iter->succ->succ;
           delete tmp;

        }
        else
            cout << "Elemento non presente nella lista!" << endl;
    }
}







