#include "Actor.h"

Actor::Actor()
{
    id=0;
    nombre="";
}
Actor:: Actor(int idAct, string numAct){
    setid(idAct);
    setNombre(numAct);
}
void Actor:: setid(int idAct){
    id= idAct;
}
int Actor::getid(){
    return id;
}
void Actor:: setNombre(string numAct){
    nombre=numAct;
}
string Actor:: getNombre(){
    return nombre;
}
