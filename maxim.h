#include <iostream>

using namespace std;


class Maxim_vector{
    private:

    int maxim;
    int pozitie;

    public:

    Maxim_vector(){}

    Maxim_vector(int max, int poz){
        maxim = max;
        pozitie = poz;
    }

    int get_poz(){
        return pozitie;
    }

    int get_maxim(){
        return maxim;
    }

    void set_max(int max, int poz){
        maxim = max;
        pozitie = poz;
    }

    void operator=(Maxim_vector max){
        maxim = max.get_maxim();
        pozitie = max.get_poz();
    }
};

void operator<<(ostream& out, Maxim_vector max){
    cout<<"Maxim: "<<max.get_maxim()<<"\n";
    cout<<"Pozitie: "<<max.get_poz()<<"\n";
}
