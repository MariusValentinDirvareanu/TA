#include "Norme.h"

Norme::Norme()
{
    //ctor
}

void Norme::normaUnuMatrici(std::vector<std::vector<double>> mat){
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
    std::cout << "Norma 1 este : " << norm << '\n';
}

void Norme::normaInfinitMatrici(std::vector<std::vector<double>> mat){
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
    std::cout << "Norma infinit este : " << norm << '\n';
}

void Norme::normaDoiMatrici(std::vector<std::vector<double>> mat){
    norm=0,sum=0;
    for(int i=0;i<static_cast<int>(mat.size());++i){
        for(int j=0;j<static_cast<int>(mat.size());++j){
            sum+=pow(mat.at(i).at(j),2);
        }
    }
    norm=sqrt(sum);
    std::cout << "Norma doi este : " << norm << '\n';
}

Norme::~Norme()
{
    //dtor
}
