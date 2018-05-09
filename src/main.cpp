#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/Quicksort.hpp"
#include "../include/Heapsort.hpp"
#include "../include/Shellsort.hpp"
#include "../include/Bubblesort.hpp"
#include "../include/Insertionsort.hpp"

#include "../include/DNI.hpp"

using namespace std;

int main(){

    Quicksort<DNI> Q;
    Heapsort<DNI> H;
    Shellsort<DNI> S;
    Bubblesort<DNI> B;
    Insertionsort<DNI> I;

    vector<DNI> v;

    bool salir;
    int c;

    cout << "1.Modo Demostracion"<<endl;
    cout << "2.Modo Estadistico"<<endl;
    cout << "Seleccione un Modo:";
    cin >> c;
    cout << endl;

    if(c == 1){

             while(!salir){

                    v.clear();
                    cout << "Numero de DNIs a comparar:";
                    cin >> c;
                    cout << endl;

                    for(int i=0; i<c; i++){
                        v.push_back(DNI());
                        cout << v[i] << endl;
                    }

                    cout << endl;
                    cout << "----- Metodos de Ordenacion -----"<<endl;
                    cout << "1.Insercion"<<endl;
                    cout << "2.Metodo de la Burbuja"<<endl;
                    cout << "3.HeapSort"<<endl;
                    cout << "4.QuickSort"<<endl;
                    cout << "5.ShellSort"<<endl;
                    cout << "6.Salir"<<endl;
                    cout << "----------------------------------"<<endl;
                    cout << "Usar el Numero:";
                    cin >> c;
                    cout << endl;

                     switch ( c )
                      {
                         case 1:
                            I.insertionSort_Debug(v, v.size());
                            for(int i = 0;i < v.size();i++)
                                cout << v[i] << endl;
                            break;
                         case 2:
                            B.bubbleSort_Debug(v, v.size());
                            for(int i = 0;i < v.size();i++)
                                cout << v[i] << endl;
                            break;
                         case 3:
                            H.heapSort_Debug(v,v.size());
                            for(int i = 0;i < v.size();i++)
                                cout << v[i] << endl;
                            break;
                         case 4:
                            Q.quicksort_Debug(v,0,v.size()-1);
                            for(int i = 0;i < v.size();i++)
                                cout << v[i] << endl;
                            break;
                         case 5:
                            S.shellSort_Debug(v, v.size());
                            for(int i = 0;i < v.size();i++)
                                cout << v[i] << endl;
                            break;
                         case 6:
                             cout << "Hasta Luego!!" << endl;
                            salir = true;
                            break;
                      }

                }//del while

        }else if(c == 2){


            while(!salir){

                    int n_dni = 0;
                    int pruebas = 0;

                    v.clear();
                    cout << "Numero de DNIs a comparar:";
                    cin >> n_dni;
                    cout << endl;

                    cout << "Numero de Pruebas:";
                    cin >> pruebas;
                    cout << endl;

                    vector<vector<DNI>> matrix;
                    vector<vector<DNI>> matrix_copia;

                    for(int i=0; i< pruebas; i++){
                      for(int j=0; j< n_dni; j++){
                        v.push_back(DNI());
                      }
                        matrix.push_back(v);
                        v.clear();
                    }

                   cout << setw(10)<< pruebas << " Pruebas de " << n_dni <<" DNIs"<< endl;
                   for(int i=0;i< pruebas;i++){
                        cout << "|";
                        for(int j=0;j<  n_dni;j++){
                                cout << " " <<matrix[i][j] << " ";
                            }
                        cout << " |";
                        cout << endl;
                    }
                    cout << endl;

                    cout << setw(44) << "Numero de comparaciones"<< endl;
                    cout << setw(25) << "Minimo" << setw(10) << "Medio" << setw(10) << "Maximo" << endl;

                    for (int i = 1; i < 6; i++) {

                            matrix_copia = matrix;
                            cout << setw(15) ;

                        switch ( i )
                          {
                             case 1:
                                for(int j=0;j< pruebas;j++){
                                    I.insertionSort(matrix_copia[j], matrix_copia[j].size());
                                }
                                cout << "InsertionSort";
                                break;
                             case 2:
                                 for(int j=0;j< pruebas;j++){
                                    B.bubbleSort(matrix_copia[j], matrix_copia[j].size());
                                }
                                cout << "BubbleSort";
                                break;
                             case 3:
                                 for(int j=0;j< pruebas;j++){
                                    H.heapSort(matrix_copia[j], matrix_copia[j].size());
                                }
                                cout << "HeapSort";
                                break;
                             case 4:
                                 for(int j=0;j< pruebas;j++){
                                    Q.quicksort(matrix_copia[j],0,matrix_copia[j].size()-1);
                                }
                                cout << "QuickSort";
                                break;
                             case 5:
                                 for(int j=0;j< pruebas;j++){
                                    S.shellSort(matrix_copia[j], matrix_copia[j].size());
                                }
                                cout << "ShellSort";
                                break;
                          }

                        int minimo = matrix_copia[0][0].get_contador();
                        int maximo = matrix_copia[0][0].get_contador();

                        for(int k=0; k< pruebas; k++){
                            for(int j=0; j< n_dni; j++){
                                if (matrix_copia[k][j].get_contador()> maximo)
                                    maximo = matrix_copia[k][j].get_contador();

                                if (matrix_copia[k][j].get_contador()< minimo)
                                    minimo = matrix_copia[k][j].get_contador();
                            }
                        }

                        cout << setw(9) << minimo << setw(9) << maximo/pruebas << setw(9) << maximo << endl;
                        cout << endl;

                    }

                }//del while

        }//del menu 1






};
