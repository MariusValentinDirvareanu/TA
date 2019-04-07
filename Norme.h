#ifndef NORME_H
#define NORME_H


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Norme
{
    public:
        Norme();
        ~Norme();
        void normaUnuMatrici(vector<vector<double>>);
        void normaInfinitMatrici(vector<vector<double>>);
        void normaDoiMatrici(vector<vector<double>>);
    private:
        double norm,sum;
};

#endif // NORME_H
