#include "PCA.h"

PCA::PCA()
{
    x.resize(100);
}

int PCA::validarep(int k){
    for(j=1;j<k;++j){
        if(x.at(k)==x.at(j)){
            return 0;
        }
    }
    return 1;
}

void PCA::permutari(int n){
    v=0;
    contor=0;
    k=1;
    x.at(1)=0;
    while(k>0){
        v=0;
        while(v==0&&x.at(k)+1<=n){
            x.at(k)++;
            if(validarep(k)){
                v=1;
            }
        }
        if(v==0){
            k--;
        }
        else{
            if(k==n){
                for(j=1;j<=n;++j){
                    cout << x.at(j) << ' ';
                }
                cout << '\n';
                contor++;
            }
            else{
                k++;
                x.at(k)=0;
            }
        }
    }
}

void PCA::combinari(int n, int m){
    v=0;
    contor=0;
    k=1;
    x.at(0)=0;
    x.at(1)=0;
    while(k>0){
        v=0;
        while(v==0&&x.at(k)+1<=n){
            x.at(k)++;
            if(x.at(k)>x.at(k-1)){
                v=1;
            }
        }
        if(v==0){
            k--;
        }
        else{
            if(k==m){
                for(j=1;j<=m;++j){
                    cout << x.at(j) << ' ';
                }
                cout << '\n';
                contor++;
            }
            else{
                k++;
                x.at(k)=0;
            }
        }
    }
}

void PCA::aranjamente(int n, int m){
    v=0;
    contor=0;
    k=1;
    x.at(0)=0;
    x.at(1)=0;
    while(k>0){
        v=0;
        while(v==0&&x.at(k)+1<=n){
            x.at(k)++;
            if(validarep(k)){
                v=1;
            }
        }
        if(v==0){
            k--;
        }
        else{
            if(k==m){
                for(j=1;j<=m;++j){
                    cout << x.at(j) << ' ';
                }
                cout << '\n';
                contor++;
            }
            else{
                k++;
                x.at(k)=0;
            }
        }
    }
}

PCA::~PCA()
{
    x.clear();
}
