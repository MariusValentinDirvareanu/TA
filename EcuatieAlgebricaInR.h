#ifndef ECUATIEALGEBRICAINR_H
#define ECUATIEALGEBRICAINR_H

#include <iostream>
#include <cstdio>
#include <cmath>



class EcuatieAlgebricaInR
{
    public:
        EcuatieAlgebricaInR();
        ~EcuatieAlgebricaInR();
        void rezolvare_ecuatie();
		double f(double);
    protected:
    private:
        double df(double);
        double a,b,eps,a0,b0,m;
        double x0,x1,ert;
        double x2,alfa,beta;
        int nrit=0;
};

#endif // ECUATIEALGEBRICAINR_H
