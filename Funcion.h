#include "Hora.h"
#include <string>
using namespace std;
class Funcion
{
    public:
        Funcion();
        Funcion(int numPelicula, string cve, Hora horaPeli, int salaPeli);
        void setcveFuncion(string cve);
        string getcveFuncion();
        void setnumPeli(int numPelicula);
        int getnumPeli();
        void setHora(Hora horaPeli);
        Hora getHora();
        void setSala(int salaPeli);
        int getSala();

    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
};


