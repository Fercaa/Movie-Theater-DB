#include "Hora.h"

Hora::Hora()
{
    hh=0;
    mm=0;
}
Hora::Hora(int mins,int hrs){
    sethh(hrs);
    setmm(mins);
}
void Hora::sethh(int hrs){
    hh=hrs;
}
int Hora::gethh(){
    return hh;
}
void Hora::setmm(int mins){
    mm=mins;
}
int Hora::getmm(){
    return mm;
}

