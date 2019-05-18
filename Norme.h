#ifndef NORME_H
#define NORME_H


#include <iostream>
#include <cmath>
#include <vector>



class Norme
{
    public:
        Norme();
        ~Norme();
        void normaUnuMatrici(std::vector<std::vector<double>>);
        void normaInfinitMatrici(std::vector<std::vector<double>>);
        void normaDoiMatrici(std::vector<std::vector<double>>);
    private:
        double norm,sum;
};

#endif // NORME_H
