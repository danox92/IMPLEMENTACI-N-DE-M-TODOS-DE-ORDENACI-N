#pragma once

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

template<class T>
class Bubblesort{

    private:

        void swap(T *xp, T *yp)
        {
            T temp = *xp;
            *xp = *yp;
            *yp = temp;
        }


    public:

        void bubbleSort(vector<T>& v, int n)
        {
           int i, j;
           for (i = 0; i < n-1; i++)
               for (j = 0; j < n-i-1; j++)
                   if (v[j] > v[j+1])
                      swap(&v[j], &v[j+1]);
        }

         void bubbleSort_Debug(vector<T>& v, int n)
        {
           int i, j;
           for (i = 0; i < n-1; i++){
               for (j = 0; j < n-i-1; j++){
                   if (v[j] > v[j+1]){

                        cout << "izquierda "<< v[j] << " derecha "<< v[j+1] << endl;
                        for(int i = 0; i < v.size();i++)
                            cout << v[i] << " ";
                        cout << endl << endl;
                        swap(&v[j], &v[j+1]);
                   }
              }
           }//del for
        }
};
