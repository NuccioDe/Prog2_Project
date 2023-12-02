//
//  Cliente.cpp
//  Progetto 1 Nunzio Depetro
//
//  Created by Nuccio Depetro on 08/07/21.
//
#include "Cliente.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& out,const Cliente& c){
    out<<"("<<c.cognome<<")\t"<<c.pizza<<"\tQuantità :"<<c.quantita<<"\t Prezzo: €"<<c.prezzo_unitario<<endl;
    return out;
}

string Cliente::getCognome()const{return cognome;}
void Cliente::setCognome(string cogn){cognome=cogn;}
string Cliente::getPizza()const{return pizza;}
double Cliente::getPrezzo()const{return prezzo_unitario;}
int Cliente::getQuantita()const{return quantita;}


Cliente::Cliente(){};
Cliente::Cliente(string _cognome,string _pizza,int _quantita, double _prezzo_unitario):cognome(_cognome),pizza(_pizza),quantita(_quantita),prezzo_unitario(_prezzo_unitario){}

bool Cliente::operator>(const Cliente& r)const{
    return prezzo_unitario>r.getPrezzo();
}

bool Cliente::operator==(const Cliente& r)const{
    return cognome==r.getCognome();
}

bool Cliente::operator!=(const Cliente& r)const{
    return cognome!=r.getCognome();
}
//
