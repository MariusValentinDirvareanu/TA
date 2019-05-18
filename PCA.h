#ifndef PCA_H
#define PCA_H

#include <iostream>
#include <cmath>
#include <vector>




class PCA
{
    public:
        PCA();
        ~PCA();
        void permutari(int);
        void combinari(int, int);
        void aranjamente(int, int);
    private:
        int validarep(int);
        int v,k,j,contor;
        std::vector<int> x;
        //vector<int>::iterator p;
};

#endif // PCA_H
