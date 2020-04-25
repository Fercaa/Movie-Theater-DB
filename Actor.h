#include <string>
using namespace std;
class Actor
{
    public:
        Actor();
        Actor(int idAct, string numAct);
        void setid(int idAct);
        int getid();
        void setNombre(string numAct);
        string getNombre();

    private:
        int id;
        string nombre;
};

