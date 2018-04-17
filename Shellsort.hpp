#pragma once
#include <cstdio>
#include <cstdlib>

using namespace std;

template< class T>
class Shellsort{

    private:

    public:

        int shellSort(vector<T>& v, int n){

            for (int gap = n/2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < n; i += 1)
                {
                    T temp = v[i];
                    int j;

                    for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                        v[j] = v[j - gap];

                    v[j] = temp;
                }
            }
            return 0;
        }

        int shellSort_Debug(vector<T>& v, int n){

            for (int gap = n/2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < n; i += 1)
                {
                    T temp = v[i];
                    int j;

                    for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                        v[j] = v[j - gap];

                    cout << "swap "<< v[j] << " y "<< temp << endl;
                       for(int i = 0; i < v.size();i++)
                    cout << v[i] << " ";
                cout << endl << endl;


                    v[j] = temp;
                }
            }
            return 0;
        }
};
