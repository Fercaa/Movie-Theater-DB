#include "Pelicula.h"

Pelicula::Pelicula()
{
    numPeli=0;
    titulo="";
    anio=0;
    duracion=0;
    genero="";
    cantActores=0;
    for(int x=0;x<10;x++){
        listaActores[x]=Actor(0,"");
    }
}
bool Pelicula::setlistaActores(Actor temp){
    bool rep=true;
    for (int x=0;x<10;x++){
        if(temp.getid()==listaActores[x].getid()){
            rep=false;
        }
        else{
            if (cantActores==10){
            rep= false;
            }
        }
    }
    if(rep==true){
        listaActores[cantActores].setid(temp.getid());
        listaActores[cantActores].setNombre(temp.getNombre());
        cantActores++;
    }
    return rep;
}
Actor Pelicula::getlistaActores(int idact){
    return listaActores[idact];
}
void Pelicula::setanio(int aniov){
    anio=aniov;
}
int Pelicula::getanio(){
    return anio;
}

void Pelicula::setTitulo(string titulov){
    titulo=titulov;
}
string Pelicula::getTitulo(){
    return titulo;
}

void Pelicula::setDuracion(int duracionv){
    duracion=duracionv;
}
int Pelicula::getDuracion(){
    return duracion;
}

void Pelicula::setGenero(string generov){
    genero=generov;
}
string Pelicula::getGenero(){
    return genero;
}

int Pelicula::getcantActores(){
    return cantActores;
}

void Pelicula::setnumPeli(int numv){
    numPeli=numv;
}
int Pelicula::getnumPeli(){
    return numPeli;
}
