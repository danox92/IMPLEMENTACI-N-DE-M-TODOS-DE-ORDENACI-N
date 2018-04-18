#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

class DNI
{

private:

    long numDNI;
    char let;
    int contador;

public:

    DNI() {
        numDNI = 30000000 + (rand() % 50000000);
        let ="TRWAGMYFPDXBNJZSQVHLCKE"[numDNI % 23];
        contador =  0;
    }

    DNI(int i,char l): numDNI(i),let(l),contador(0) {}

    DNI(int i): numDNI(i),contador(0){
         let ="TRWAGMYFPDXBNJZSQVHLCKE"[numDNI % 23];

    }

    virtual ~DNI() {}

    bool operator==(const DNI& dni) {
        contador++;
        return dni.numDNI == this->numDNI;
    }

    bool operator<(const DNI& dni) {
        contador++;
        return this->numDNI < dni.numDNI;
    }

    bool operator>(const DNI& dni) {
        contador++;
        return this->numDNI > dni.numDNI;
    }

    bool operator<=(const DNI& dni) {
        contador++;
        return this->numDNI <= dni.numDNI;
    }

    bool operator>=(const DNI& dni) {
        contador++;
        return this->numDNI >= dni.numDNI;
    }

    int get_contador(void){
        return contador;
    }

    void reset_contador(void){
        contador = 0;
    }

    friend ostream& operator<<(ostream& os, const DNI& d);
};

ostream& operator<<(ostream& os, const DNI& d)
{
    os << d.numDNI << d.let;
    return os;
};
