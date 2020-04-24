#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Funcion.h"
using namespace std;

int main()
{
    Pelicula prueba;
    cout << prueba.getlistaActores(5).getid() << endl;
    return 0;
}
