#include "Actor.h"

class Pelicula
{
    public:
        Pelicula();
        void setnumPeli(int num);
        int getnumPeli();
        void setTitulo(string titulo);
        string getTitulo();
        void setanio(int anio);
        int getanio();
        void setGenero(string genero);
        string getGenero();
        void setDuracion(int duracion);
        int getDuracion();
        void setcantActores(int cantActores);
        int getcantActores();
        void setlistaActores();
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

