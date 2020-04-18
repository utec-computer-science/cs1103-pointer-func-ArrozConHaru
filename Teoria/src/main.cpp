#include <iostream>
using namespace std;

void * _bubblesort_(void * _array_,void (*_puntero_) (void *, int _i, int _k),int _tam_){
    int _k = 0;
    for (int i = 0; i < _tam_ ; i ++)
        for(int k = 0; k < _tam_-1; k++)
            _puntero_(_array_,i,k); //Arreglado (no coincidia con las variables del for)
    return _array_;
}

void  _b_int_ (void* _vector_, int _i,int _k){
int *x = (int*)_vector_; //Convertimos void a int (Casting)
if(x[_i]<x[_k]){
    swap(x[_i],x[_k]); // Usando la funcion swap() para el sort
}
}

void  _b_float_ (void * _vector_, int _i,int _k){
    float* x = (float*)_vector_;//Convertimos void a float (Casting)
    if(x[_i] < x[_k]){
        float temp = x[_i];//Forma funcional pero mas larga
        x[_i]=x[_k];
        x[_k]=temp;
}
}
void  _b_double_ (void * _vector_, int _i,int _k){
double* x = (double *)_vector_;//Convertimos void a double (Casting)
if(x[_i] < x[_k]){
    swap(x[_i],x[_k]);
}
}
void  _b_char_ (void * _vector_, int _i,int _k){
char* x = (char*)_vector_;//Convertimos void a char (Casting)
if(x[_i] < x[_k]){
    swap(x[_i],x[_k]);
}
}


int main(){
    srand(time(NULL)); //Generamos nueva semilla
    int _array_1 [5]; //Editamos el array para que sus valores sean RANDOM
    for (int i = 0; i < 5; ++i) {
        _array_1[i]=rand()%421;
    }

    float _array_2 [5] = {4.4,5.4,9.1,7.4,2.2};
    double _array_3 [5] = {3.0,8.0,2.0,4.0,15.0};
    char _array_4 [6] = {'k','a','r','l','o','s'};
    //Extra:
    char _array_5 [5] = {'c','a','z','h','p'};

    cout<<"RESULTADOS: \n";

    _bubblesort_(_array_1,_b_int_,5);
    for(auto n: _array_1) //Forma simple de recorrer el array
        cout<< n<<" ";
    cout<<endl;
    _bubblesort_(_array_2,_b_float_,5);
    for(auto n: _array_2) //Forma simple de recorrer el array
        cout<< n<<" ";
    cout<<endl;
    _bubblesort_(_array_3,_b_double_,5);
    for(auto n: _array_3) //Forma simple de recorrer el array
        cout<< n<<" ";
    cout<<endl;
    _bubblesort_(_array_4,_b_char_,6);
    for(auto n: _array_4) //Forma simple de recorrer el array
        cout<< n<<" ";
    cout<<endl;
    //Extra
    _bubblesort_(_array_5,_b_char_,5);
    cout<<"Extra:\n";
    for(auto n: _array_5) //Forma simple de recorrer el array
        cout<< n<<" ";
    cout<<endl;

    return 0;
}
