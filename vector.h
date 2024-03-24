#include <iostream>
#include <string.h>
#include <string>
#include "maxim.h"

using namespace std;


class Vector{
    private:
    int* v;
    int size;

    public:

    Vector(){
        this -> v = new int(1);
        this -> size = 0;
    }

    Vector(int size){
        this -> v = new int(size+1);
        this -> size = size;
        for(int i = 1; i<=size; i++){
            *(v+i) = 0;
        }
    }

    Vector(int* v, int size){
        this -> v = new int(size+1);
        this -> size = size;
        for(int i = 1; i<=size; i++){
            *((this -> v)+i) = *(v+i);
        }

    }

    Vector(Vector &v){
        this -> size = v.get_size();
        this -> v = new int(v.get_size()+1);
        for(int i = 1; i<=v.get_size(); i++){
            *((this -> v)+i) = *(v.get_v()+i);
        }
    }

    ~Vector(){
        try{
            delete[] this -> v;
        }
        catch(...){}
    }

    int* get_v(){
        return v;
    }

    int get_size(){
        return size;
    }

    // nu are sens sa avem un setter doar pentru v; (nu stim marimea)

    //nu are sens sa avem un setter pt size; (daca e mai mare citim memorie nealocata; daca e mai mic nu folosim tot vectorul)

    void set_v(int* v, int size){
        try{
            delete[] this -> v;
        }
        catch(...){}
        this -> v = new int(size+1);
        this -> size = size;
        for(int i = 1; i<=size; i++){
            *((this -> v)+i) = *(v+i);
        }
    }

    void actualizare(int size, int numar){
        try{
            delete[] this -> v;
        }
        catch(...){}
        this -> v = new int(size+1);
        this -> size = size;
        for(int i = 1; i<=size; i++){
            *((this -> v)+i) = numar;
        }

    }

    void set_index(int index, int numar){
        *(v + index+1) = numar;
    }

    int get_index(int index){
        return *(v + index) +1;
    }

    int get_suma(){
        int suma = 0;
        for(int i = 1;i<=size;i++){
            suma = suma + *(v+i);
        }
        return suma;
    }

    Maxim_vector get_max(){
        int max = *(v+1);
        int poz = 1;
        for(int i = 1;i<=size;i++){
            if(*(v+i)>max){
                max = *(v+i);
                poz = i;
            }
        }
        Maxim_vector maxim(max,poz-1);
        return maxim;
        
    }

    void vect_sor(){
        int min1, min2;
        int poz1, poz2;
        if(*(v+1)<*(v+2)){
            min1 = *(v+1);
            min2 = *(v+2);
            poz1 = 1;
            poz2 = 2;
        }else{
            min1 = *(v+2);
            min2 = *(v+1);
            poz1 = 2;
            poz2 = 1;
        }
        int e = 1;
        for(int y = 1; y<=size;y++){
            for(int i = e; i<=size;i++){
                if(min1 > *(v+i)){
                    min2 = min1;
                    poz2 = poz1;
                    min1 = *(v+i);
                    poz1 = i;
                }
                if(min1 == *(v+i) && i!=poz1){
                    min2 = min1;
                    poz2 = i;
                }
                if(min2 > *(v+i) && *(v+i) > min1){
                    min2 = *(v+i);
                    poz2 = i;
                }
            }
            if(e == size-1){
                *(v+e) = min1;
                *(v+e+1) = min2;
                break;
            }else{
                int copie = *(v+e);
                *(v+e) = min1;
                *(v+poz1) = copie;
                min1 = min2;
                poz1 = poz2;
                if(min1 ==*(v+e+1)){
                    min2 = *(v+e+2);
                    poz2 = e+2;
                }else{
                    min2 = *(v+e+1);
                    poz2 = e+1;
                }
                e++;
            }
        }
    }

    void copie(Vector v){
        cout<<"yep";
        try{
            delete[] this -> v;
        }
        catch(...){}
        this -> v = new int(size+1);
        this -> size = v.get_size();
        for(int i = 1; i<=v.get_size(); i++){
            *((this -> v)+i) = *(v.get_v()+i);
        }
    }

    void operator=(Vector v){
        try{
            delete[] this -> v;
        }
        catch(...){}
        this -> v = new int(size+1);
        this -> size = v.get_size();
        for(int i = 1; i<=v.get_size(); i++){
            *((this -> v)+i) = *(v.get_v()+i);
        }
    }

};

bool operator==(Vector v1, Vector v2){
    if(v1.get_size() == v2.get_size()){
        for(int i = 0; i<=v1.get_size();i++){
            if(*(v1.get_v() + i) != *(v2.get_v() + i)){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

void operator<<(ostream& out, Vector v){
    cout<<"Vector de marime: ";
    cout<<v.get_size()<<"\n";
    cout<<"Vetorul: ";
    for(int i = 1; i<=v.get_size();i++){
        cout<<*(v.get_v() + i)<<" ";
    }
    cout<<"\n";
}

void operator>>(istream& in, Vector &v){
    int size;
    char s[200];
    cin.getline(s, 100);
    char *p;
    p = strtok(s," ");
    while (p){
        try{
            size = stoi(p);
            break;
        }
        catch(...){
            p = strtok(NULL," ");
        }
    }
    int* vect = new int(size+1);
    cin.getline(s, 100);
    p = strtok(s," ");

    while (p){
        try{
            for(int i=1; i<=size;i++){
                *(vect+i) = stoi(p);
                p = strtok(NULL," ");
            }
            break;
        }
        catch(...){
            p = strtok(NULL," ");
        }
    }
    v.set_v(vect, size);
    delete[] vect;
}

