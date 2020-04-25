#include <iostream>
#include <string>
//#include "Actor.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "fstream"
#include <sstream>
#include <cmath>
using namespace std;

int extraerint(string getl){
    stringstream trans;
    trans<<getl;
    string temporal;
    int numeros;
    while (!trans.eof()){
        trans>>temporal;
        if(stringstream(temporal)>>numeros){
            return numeros;
        }
    }

}

int main()
{
    string nombreA;
    string nombreF;
    char resp,sn;
    int  x,espacio,espacio2;
    string y, substNom,z,z2,subz;
    int nPeli,anioP,duraPeli, cantA;
    Actor act;
    string cveP;
    int salaP;
    int numP;
    int idac;
    int hrsf, minsf;
    int contadora=0;
    int hrs,mins,comp=0;
    Hora horaP;
    int terminar=0;
    bool verif,comp2,comp3,continuar,subir;
    string clave;
    string generoP,tituloP;
    Pelicula pelis[20];
    int cont=0,cont2=0;
    Actor actores[20];
    Funcion funciones[20];
    cout<<"Teclea un nombre para el archivo de actores"<<endl;
    getline(cin, nombreA);
    cout<<"Teclea un nombre para el archivo de Funciones"<<endl;
    getline(cin,nombreF);

    nombreA+=".txt";
    nombreF+=".txt";
    ifstream archAct;
    archAct.open(nombreA.c_str());
    ifstream archFunc;
    archFunc.open(nombreF.c_str());
    while(getline(archAct,y)){
        x=extraerint(y);
        actores[cont].setid(x);
        espacio=y.find(" ");
        espacio++;
        substNom=y.substr(espacio);
        actores[cont].setNombre(substNom);
        cont++;

    }
    while(getline(archFunc,z)){
        espacio2=z.find(" ");
        subz=z.substr(0,espacio2);
        nPeli=extraerint(subz);
        pelis[cont2].setnumPeli(nPeli);
        z=z.substr(espacio2+1);
        espacio2=z.find(" ");
        subz=z.substr(0,espacio2);
        anioP=extraerint(subz);
        pelis[cont2].setanio(anioP);
        z=z.substr(espacio2+1);
        espacio2=z.find(" ");
        subz=z.substr(0,espacio2);
        duraPeli=extraerint(subz);
        pelis[cont2].setDuracion(duraPeli);
        espacio2=z.find(" ");
        z2=z.substr(espacio2+1);
        espacio=z2.find(" ");
        subz=z2.substr(0,espacio);
        pelis[cont2].setGenero(subz);
        espacio2=z.find(" ");
        z=z.substr(espacio2+1);
        espacio2=z.find(" ");
        subz=z.substr(0,espacio2);
        cantA=extraerint(z);
        z=z.substr(espacio2+1);
        espacio2=z.find(" ");
        z=z.substr(espacio2+1);
        for(int i=0;i<cantA;i++){
            espacio2=z.find(" ");
            subz=z.substr(0,espacio2);
            act.setid(extraerint(subz));
            for (int g=0; g<20;g++){
                if ((act.getid())==(actores[g].getid()))
                    act.setNombre(actores[g].getNombre());
            }
            subir=pelis[cont2].setlistaActores(act);
            z=z.substr(espacio2+1);
        }
        pelis[cont2].setTitulo(z);
        cont2++;

    }
    if(subir==false){
      cout<<"La lista de Funciones tiene defectos, intente con otro archivo"<<endl;
      return 0;
    }
    archAct.close();
    archFunc.close();
    do{
        do{
            cout<<"Desea insertar una funcion?(Y/N)"<<endl;
            cin>>resp;
            resp=tolower(resp);
        }while(!(resp=='y'||resp=='n'));
        if (resp=='y'){
            do{
                cout<<"Cual es la hora de la pelicula?"<<endl;
                cin>>hrs;
            }while(!(0<=hrs && hrs<24));
            do{
                cout<<hrs<<" con cuantos minutos?"<<endl;
                cin>>mins;
            }while(!(0<=mins && mins<60));
            cout<<"Cual es la sala de la funcion?"<<endl;
            cin>>salaP;
            cout<<"Cual es la clave de la funcion?"<<endl;
            cin>>cveP;
            do{
                verif=false;
                cout<<"Escribe el numero de la pelicula"<<endl;
                cin>>numP;
                for(int u=0;u<cont2;u++){
                    if (numP==pelis[u].getnumPeli())
                        verif=true;
                }
            } while(verif==false);
        }
        horaP.sethh(hrs);
        horaP.setmm(mins);
        funciones[contadora].setcveFuncion(cveP);
        funciones[contadora].setHora(horaP);
        funciones[contadora].setnumPeli(numP);
        funciones[contadora].setSala(salaP);
        contadora++;
    }while(resp=='y');
    do{
        continuar=true;
        do{
            cout<<"Bienvenido!\t Que desea consultar?\t"<<endl;
            cout<<"->Consulta de todos los actores que estan en la lista. (A)"<<endl;
            cout<<"->Consulta de todas las peliculas que estan en la lista. (B)"<<endl;
            cout<<"->Consulta de todas las funciones disponibles. (C)"<<endl;
            cout<<"->Consulta de funciones por hora. (D)"<<endl;
            cout<<"->Consulta por clave de funcion. (E)"<<endl;
            cout<<"->Consulta de peliculas en las que participa un actor. (F)"<<endl;
            cout<<"->Terminar. (T)"<<endl;
            cin>>resp;
            resp=tolower(resp);
        }while(!(resp=='a'||resp=='b'||resp=='c'||resp=='d'||resp=='e'||resp=='f'||resp=='t'));
        switch(resp){
        case 'a':
            cout<<"Lista de Actores Registrados:"<<endl;
            for(int ac=0;ac<cont;ac++){
                cout<<actores[ac].getid()<<"  "<<actores[ac].getNombre()<<endl;
            }
            break;
        case 'b':
            cout<<"Lista de Peliculas Registradas"<<endl;
            cout<<"No. Pelicula/ Anio/ Genero/ Duracion/ Nombre"<<endl;
            for(int f=0;f<cont2;f++){
                cout<<pelis[f].getnumPeli()<<"  "<<pelis[f].getanio()<<"  "<<pelis[f].getGenero()<<"  "<<pelis[f].getDuracion()<<"  "<<pelis[f].getTitulo()<<endl;
                cout<<"Actores Participantes:"<<endl;
                for(int ap=0;ap<pelis[f].getcantActores();ap++){
                    cout<<pelis[f].getlistaActores(ap).getid()<<"  "<<pelis[f].getlistaActores(ap).getNombre()<<endl;
                }
            }
            break;
        case 'c':
            cout<<"Funciones Disponibles:\t";
            cout<<"Clave/ Sala / Hora:Minutos / Nombre Pelicula"<<endl;
            for(int fu=0;fu<contadora-1;fu++){
                cout<<funciones[fu].getcveFuncion()<<"  "<<funciones[fu].getSala()<<"  "<<funciones[fu].getHora().gethh()<<":"<<funciones[fu].getHora().getmm();
                for(int func=0;func<cont2;func++){
                    if(pelis[func].getnumPeli()==funciones[fu].getnumPeli()){
                        cout<<"  "<<pelis[func].getTitulo()<<endl;
                    }
                }
            }
            break;
        case 'd':
            do{
                comp=0;
                cout<<"Escribe la hora de la funcion"<<endl;
                cin>>hrsf;
                cout<<"Escribe los minutos de la funcion"<<endl;
                cin>>minsf;
                cout<<"Funciones Disponibles:"<<endl;
                for(int fun=0;fun<contadora-1;fun++){
                    if((hrsf==funciones[fun].getHora().gethh())&&( minsf==funciones[fun].getHora().getmm())){
                        cout<<funciones[fun].getcveFuncion()<<"  "<<funciones[fun].getSala()<<"  "<<funciones[fun].getHora().gethh()<<":"<<funciones[fun].getHora().getmm();
                        for(int funct=0;funct<cont2;funct++){
                            if(pelis[funct].getnumPeli()==funciones[fun].getnumPeli()){
                            cout<<"  "<<pelis[funct].getTitulo()<<endl;
                            }
                        }
                    }
                    else{
                        comp++;
                    }
                }
        }while(comp!=0);
        break;
    case 'e':
        do{
            comp2=false;
            cout<<"Escribe una clave de funcion"<<endl;
            cin>>clave;
            cout<<"Funcion de clave:"<<endl;
            for(int cl=0;cl<contadora-1;cl++){
                if(clave==funciones[cl].getcveFuncion()){
                    comp2=true;
                    cout<<funciones[cl].getcveFuncion()<<"  "<<funciones[cl].getSala()<<"  "<<funciones[cl].getHora().gethh()<<":"<<funciones[cl].getHora().getmm();
                    for(int cl1=0;cl1<cont2;cl1++){
                        if(pelis[cl1].getnumPeli()==funciones[cl].getnumPeli()){
                        cout<<"  "<<pelis[cl1].getTitulo()<<endl;
                        }
                    }

                }
        }
        }while(comp2==false);
        break;
    case 'f':
        do{
            comp3=false;
            cout<<"Escribe un ID de actor"<<endl;
            cin>>idac;
            cout<<"Peliculas con este actor:"<<endl;
            for(int ida=0;ida<cont2;ida++){
                for(int idp=0;idp<pelis[ida].getcantActores();idp++){
                    if(idac==pelis[ida].getlistaActores(idp).getid()){
                        cout<<pelis[ida].getTitulo()<<"  "<<pelis[ida].getanio()<<endl;
                        comp3=true;
                    }
                }
            }
        }while(comp3==false);
        break;
    case 't':
        {
            terminar++;
            continuar=false;
        }
    }
    if(terminar==0){
        do{
            cout<<"Desea realizar otra consulta?(Y/N)"<<endl;
            cin>>sn;
            sn=tolower(sn);
        }while(!(sn=='y'||sn=='n'));
    }
    if(sn=='n'){
        continuar=false;
    }
    }while(continuar==true);
    return 0;
}
