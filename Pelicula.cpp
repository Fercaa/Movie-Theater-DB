#include "Pelicula.h"

Pelicula::Pelicula()
{
    numPeli=0;
    titulo="";
    anio=0;
    duracion=0;
    genero="";
    cantActores=10;
    for(int x=0;x<10;x++){
        listaActores[x]=Actor(0,"");
    }
}
Actor Pelicula::getlistaActores(int idact){
    return listaActores[idact];
}
