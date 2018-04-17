#pragma once

#include <cstdio>
#include <cstdlib>

using namespace std;

template< class T>
class Insertionsort{

    private:

    public:

        void insertionSort(vector<T>& v, int n){
           int i,j;
           T key;
           for (i = 1; i < n; i++)
           {
               key = v[i];
               j = i-1;

               while (j >= 0 && v[j] > key)
               {
                   v[j+1] = v[j];
                   j = j-1;
               }
               v[j+1] = key;
           }
        }

         void insertionSort_Debug(vector<T>& v, int n){
           int i,j;
           T key;
           for (i = 1; i < n; i++)
           {
               key = v[i];
               j = i-1;

               while (j >= 0 && v[j] > key)
               {
                    cout << "swaps "<< v[j] << " y "<< v[j+1] << endl;
                       for(int i = 0; i < v.size();i++)
                    cout << v[i] << " ";
                    cout << endl << endl;

                   v[j+1] = v[j];
                   j = j-1;
               }
               v[j+1] = key;
           }
        }
};
