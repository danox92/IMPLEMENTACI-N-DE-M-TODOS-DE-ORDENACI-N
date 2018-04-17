#pragma once

using namespace std;

template <class T>
class Heapsort{

    private:

        void heapify(vector<T>&  v, int n, int i){
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < n && v[l] > v[largest])
                largest = l;

            if (r < n && v[r] > v[largest])
                largest = r;

            if (largest != i)
            {
                swap(v[i], v[largest]);
                heapify(v, n, largest);
            }
        }

    public:

        void heapSort(vector<T>&  v, int n){

            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(v, n, i);

            for (int i=n-1; i>=0; i--)
            {
                swap(v[0], v[i]);
                heapify(v, i, 0);
            }
        }

        void heapSort_Debug(vector<T>&  v, int n){

            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(v, n, i);

            for (int i=n-1; i>=0; i--)
            {
                cout << "swap "<< v[0] << " y "<< v[i] << endl;
                   for(int i = 0; i < v.size();i++)
                    cout << v[i] << " ";
                cout << endl << endl;

                swap(v[0], v[i]);
                heapify(v, i, 0);
            }
        }

};
