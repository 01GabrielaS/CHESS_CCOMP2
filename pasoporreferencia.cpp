#include <iostream>
using namespace std;

int cambio_sinpaso(int a){
    a=a+3;
    return a;
};

void cambio_conpaso(int &a){
    a=a+3;
}

int main(){
    int num=1;
    int nuevo=cambio_conpaso(num);
    cout<<"Función sin paso(numero+3):"<<cambio_sinpaso(num)<<endl;
    cout<<"Función con paso(numero+3):"<<nuevo<<endl;

}