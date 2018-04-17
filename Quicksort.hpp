#pragma once


#include <cstdio>
#include <cstdlib>

using namespace std;

template <class T>
class Quicksort{

    private:

       int divide(vector<T>& v, int i, int d){
            T pivot = v[i];
            int izq = i;
            int dch = d;

            while (izq < dch) {

                while (v[dch] > pivot)
                    dch--;

                while ((izq < dch) && (v[izq] <= pivot))
                    izq++;

                if (izq < dch)
                    swap(v[izq], v[dch]);
            }
            swap(v[i], v[dch]);

            return dch;
        }


        void swap(T& a, T& b){
            T aux = a;
            a = b;
            b = aux;
        }


    public:

        ~Quicksort(){}


        void quicksort(vector<T>& v, int i, int d){
            if (i < d) {
                const int pivot = divide(v, i, d);

                quicksort(v, i, pivot - 1);
                quicksort(v, pivot + 1, d);
            }
        }


        void quicksort_Debug(vector<T>& v, int i, int d){

            if (i < d) {
                const int pivot = divide(v, i, d);

                cout << "izquierda "<< v[i] << " derecha "<< v[d] << " pivote "<< v[pivot] <<endl;
                for(int i = 0; i < v.size();i++)
                    cout << v[i] << " ";
                cout << endl << endl;

                quicksort_Debug(v, i, pivot - 1);
                quicksort_Debug(v, pivot + 1, d);
            }
        }

};
