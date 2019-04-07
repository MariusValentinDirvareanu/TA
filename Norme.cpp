#include "Norme.h"

Norme::Norme()
{
    //ctor
}

void Norme::normaUnuMatrici(vector<vector<double>> mat){
    norm=0,sum=0;
    for(int i=0;i<static_cast<int>(mat.size());++i){
        for(int j=0;j<static_cast<int>(mat.size());++j){
            sum+=abs(mat.at(i).at(j));
        }
        if(norm<sum){
            norm=sum;
        }
        sum=0;
    }
    cout << "Norma 1 este : " << norm << endl;
}

void Norme::normaInfinitMatrici(vector<vector<double>> mat){
    norm=0,sum=0;
    for(int i=0;i<static_cast<int>(mat.size());++i){
        for(int j=0;j<static_cast<int>(mat.size());++j){
            sum+=abs(mat.at(j).at(i));
        }
        if(norm<sum){
            norm=sum;
        }
        sum=0;
    }
    cout << "Norma infinit este : " << norm << endl;
}

void Norme::normaDoiMatrici(vector<vector<double>> mat){
    norm=0,sum=0;
    for(int i=0;i<static_cast<int>(mat.size());++i){
        for(int j=0;j<static_cast<int>(mat.size());++j){
            sum+=pow(mat.at(i).at(j),2);
        }
    }
    norm=sqrt(sum);
    cout << "Norma doi este : " << norm << endl;
}

Norme::~Norme()
{
    //dtor
}
