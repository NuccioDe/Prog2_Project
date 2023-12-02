//
//  main.cpp
//  Progetto 1 Nunzio Depetro
//
//  Created by Nuccio Depetro on 08/07/21.
//



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaDL.h"






using namespace std;

void ComandeFile(const string& str, string cont[4])
{
    char delim = ',';
    stringstream ss(str);
    string token;
    int i = 0;
    while (getline(ss, token, delim)) {
        cont[i] = token;
        i++;
        if(i==4) break;
    }
}


//carico i dati del file .txt contenente le comande all'interno delle mie liste
static int punto1(const string filename, ListaDL& ls)
{
    ifstream file;
    string line;
    string buff[4];
Cliente g;
    file.open(filename);
    int num = 0;
    if(file.is_open())
    {
        while(getline(file, line)){
            ComandeFile(line,buff);
            g = Cliente(buff[0],buff[1],stoi(buff[2]),stod(buff[3]));
            ls.inserisci(g);
            num++;
                                }

        file.close();
    }
    else
        cout << "Non posso aprire il file!" << endl;
    return num;
}


static void punto2(ListaDL& ls){
    Nodo* iter=ls.getTesta();

    string persona="";
    string persona2="";
    
    cout<<iter->valore.getCognome()<<endl;;
    while(iter!=nullptr){
        persona=iter->valore.getCognome();
        
        if(iter->succ!=nullptr){
            persona2=iter->succ->valore.getCognome();
            if(persona==persona2){
                cout <<"Pizza: "<< iter->valore.getPizza() << "\t Quantità:"<<iter->valore.getQuantita()<<"\tPrezzo : "<<iter->valore.getPrezzo()<<"€"<<endl;;
               }
            else{
                cout <<"Pizza: "<< iter->valore.getPizza() << "\t Quantità:"<<iter->valore.getQuantita()<<"\tPrezzo : "<<iter->valore.getPrezzo()<<"€"<<endl;;
                cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
                cout<<"Stampo ordine: "<<persona2<<endl;
                cout<<endl;
                }
            }
        
        if(iter->succ==nullptr)  cout <<"Pizza: "<< iter->valore.getPizza() << "\t Quantità:"<<iter->valore.getQuantita()<<"\tPrezzo : "<<iter->valore.getPrezzo()<<"€"<<endl;;
        iter=iter->succ;
        
}
    cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

}

//Metodo che stampa unicamente il cognome con ordine annesso ricercato dall'utente
static void punto3(ListaDL& ls, string cliente){
    Cliente gg;
    gg.setCognome(cliente);
    Nodo* valore_cercato =ls.ricerca(gg);
    
    Nodo* iter;
    string persona=cliente;
    double prezzo=0;
    bool trovato=false;
    
    iter = valore_cercato;
       

   
        while(iter!=nullptr){
            if (iter->valore.getCognome()==persona){ //stampo solo il cognome cercato con i relativi ordini
                cout << iter->valore;
                prezzo+=iter->valore.getPrezzo()*iter->valore.getQuantita();
                trovato=true;
            }
            iter = iter->succ;
                
        }
    if(trovato==false)cout<<"Nessun Cliente trovato con questo cognome: "<<persona<<" !"<<endl;
    
    cout<<endl;
    cout<<"Prezzo totale speso:  "<<prezzo<<"€"<<endl;
        
    



}




static bool punto4(ListaDL& ls){

    Cliente cl;
    Nodo* iter = ls.getTesta();
    Nodo*tmp;
    
    double prezzo=0;
    double media;
    int cont=0;
     
    
    while(iter!=nullptr){
        
            prezzo+=iter->valore.getPrezzo();
        cont++;
        iter = iter->succ;
        
    }
            
    media=prezzo/cont;
    
    cout<<"La media spesa nella pizzeria è di:  "<<media<<endl;
    
    bool ret_val = false;
    iter=ls.getTesta();
    
    ofstream fout("eliminati.txt");; //creo il file txt
    while(iter!=nullptr){
        tmp=iter->succ;
        
        if((iter->valore.getPrezzo()*iter->valore.getQuantita())<media ){
            ret_val = true;
            cout << "Elimino Ordine di:\t"<< iter->valore.getCognome()<< endl;
            cout << iter->valore << endl;
            cl.setCognome(iter->valore.getCognome());
            fout<<iter->valore; //scrivo il valore nel file
            ls.rimuovi(cl);
        }
        
        iter = tmp;
        }
    
    fout.close();
    cout<<"File con gli ordini eliminati Salvato!"<<endl;
    
    
    iter=ls.getTesta();
    cout<<"Lista Aggiornata:  \t"<<endl;
    
    while(iter!=nullptr){
        cout<<iter->valore<<endl;
        iter=iter->succ;
    }
    return ret_val;
    
    
   
    
    }





int main(){
    
    int stampafile;
    ListaDL listaCliente;
    ListaDL listaClienteO;
    stampafile = punto1("Comande.txt", listaCliente);
    
    
    cout<<"---------------CARICO FILE ORDINI-----------------"<<endl;
    
    
    cout << endl <<"----------------PRIMO PUNTO--------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;
    cout << listaCliente;
    
    
    
    cout << endl <<"----------------SECONDO PUNTO--------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;
    punto2(listaCliente);
    
   
    
    
    
    cout << endl <<"----------------TERZO PUNTO-------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;
    
    string str;
    cout << "Inserisci il cognome delL Cliente da cercare:\n (si prega di inserire la prima lettera del cognome in maiuscolo)"<<endl;;
    cin >> str;
    punto3(listaCliente,str);
   
    
    
    
    
    cout << endl <<"----------------QUARTO PUNTO--------------------" << endl;
    cout << endl <<"-----------------------------------------------" << endl;

    punto4(listaCliente);
    

   
  
    return 0;

}
    
    

