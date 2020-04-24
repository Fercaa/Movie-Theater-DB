#include "Funcion.h"
#include <string>
using namespace std;
Funcion::Funcion()
{
    numPeli=0;
    sala=0;
    cveFuncion="";
}

Funcion::Funcion(int numPelicula, string cve, Hora horaPeli, int salaPeli){
    setcveFuncion(cve);
    setnumPeli(numPelicula);
    setHora(horaPeli);
    setSala(salaPeli);
}
void Funcion:: setcveFuncion(string cve){
    cveFuncion= cve;
}
string Funcion:: getcveFuncion(){
    return cveFuncion;
}
void Funcion:: setnumPeli(int numPelicula){
    numPeli=numPelicula;
}
int Funcion:: getnumPeli(){
    return numPeli;
}
void Funcion:: setHora(Hora horaPeli){
    hora= horaPeli;
}
Hora Funcion:: getHora(){
    return hora;
}
void Funcion:: setSala(int salaPeli){
    sala=salaPeli;
}
int Funcion::getSala(){
    return sala;
}
