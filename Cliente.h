//
//  Cliente.h
//  Progetto 1 Nunzio Depetro
//
//  Created by Nuccio Depetro on 08/07/21.
//

#ifndef Cliente_h
#define Cliente_h

#include <iostream>
#include <string>

using namespace std;

class Cliente{
private:
    string cognome,pizza;
    double prezzo_unitario;
    int quantita;
    
public:
    Cliente();
    Cliente(string _cognome, string _pizza, int _quantita, double _prezzo_unitario);
    
    string getCognome()const;
    void setCognome(string);
    string getPizza()const;
    int getQuantita()const;
    double getPrezzo()const;
    
    bool operator>(const Cliente&)const;
    bool operator==(const Cliente&)const;
    bool operator!=(const Cliente&)const;
    
    friend ostream& operator<<(ostream& out, const Cliente& c);
    
    
    
};



#endif /* Cliente_h */
