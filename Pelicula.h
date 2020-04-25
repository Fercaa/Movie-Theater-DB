#include "Actor.h"

class Pelicula
{
    public:
        Pelicula();
        void setnumPeli(int numv);
        int getnumPeli();
        void setTitulo(string titulov);
        string getTitulo();
        void setanio(int aniov);
        int getanio();
        void setGenero(string generov);
        string getGenero();
        void setDuracion(int duracionv);
        int getDuracion();
        int getcantActores();
        bool setlistaActores(Actor temp);
        Actor getlistaActores(int idact);
    private:
        int numPeli;
        string titulo;
        int anio;
        int duracion;
        string genero;
        int cantActores;
        Actor listaActores[10];
};

