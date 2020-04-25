
class Hora
{
    public:
        Hora();
        Hora(int mins,int hrs);
        void sethh(int hrs);
        int gethh();
        void setmm(int mins);
        int getmm();

    private:
        int hh;
        int mm;
};


