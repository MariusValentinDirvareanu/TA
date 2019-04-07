#include "EcuatieAlgebricaInR.h"

EcuatieAlgebricaInR::EcuatieAlgebricaInR()
{
    //ctor
}

//functia
double EcuatieAlgebricaInR::f(double x)
{
    return x*x-2;
}

//derivata functiei
double EcuatieAlgebricaInR::df(double x)
{
    return 2*x;
}

void EcuatieAlgebricaInR::rezolvare_ecuatie()
{
 // Metoda bisectiei
 cout<<" a= "; cin>>a;
 cout<<" b= "; cin>>b;
 cout<<" eps= "; cin>>eps;

 cout<<"Iteratia"<<"  Aprox. cu metoda bisectiei "<<" Metoda tangentei " << "Metoda secantei\n";
 cout<<"____________________________________________________________________________________\n";

 // initializare metoda bisectiei;
 a0=a; b0=b;
 // initializaremetoda tangentei
 x0=b;
 // initializare metoda secantei
 alfa=a;
 beta=b;
 x2=a;
 // cout<<nrit<<"   [ "<<a0<<" , "<<b0<<" ]    "<<x0<<endl;
 printf("%4d      [ %10.9f , %10.9f ]     %10.9f   %10.9f\n", nrit,a0,b0,x0,x2);


 do
 {
    // calcule pentru metoda bisectiei
    m=(a0+b0)/2;
    if (f(m)==0){
        cout<<"Solutia este "<<m;
        break;
    }
    else {
        if (f(a0)*f(m) < 0)
            b0=m;
        else
            a0=m;
        }

    //  calcule cu metoda tangentei
    x1=x0-f(x0)/df(x0);
    ert=fabs(x1-x0);
    x0=x1;

    // calcul metoda secantei
    x2=alfa-(((beta-alfa)/(f(beta)-f(alfa)))*f(alfa));
    if(f(m)*f(beta)<0)
        alfa=x2;
    else{
        if(f(m)*f(beta)>0)
            beta=x2;
        else{
            alfa=x2;
            beta=x2;
        }
    }
    x2=(alfa+beta)/2;

    nrit++;
    printf("%4d      [ %10.9f , %10.9f ]     %10.9f   %10.9f\n", nrit,a0,b0,x0,x2);
    }while(((b0-a0)>=eps) || (ert>eps) || (beta-alfa)/2>=eps);

cout<<"Solutia se afla in intervalul ["<<a0<<","<<b0<<"]\n";
cout<<" si poate fi aproximata prin valoarea "<<(a0+b0)/2;

}

EcuatieAlgebricaInR::~EcuatieAlgebricaInR()
{
    //dtor
}
