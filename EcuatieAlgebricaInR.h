#ifndef ECUATIEALGEBRICAINR_H
#define ECUATIEALGEBRICAINR_H

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class EcuatieAlgebricaInR
{
    public:
        EcuatieAlgebricaInR();
        ~EcuatieAlgebricaInR();
        void rezolvare_ecuatie();
    protected:
    private:
        double f(double);
        double df(double);
        double a,b,eps,a0,b0,m;
        double x0,x1,ert;
        double x2,alfa,beta;
        int nrit=0;
};

#endif // ECUATIEALGEBRICAINR_H
