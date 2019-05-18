#include "Submultimi.h"



Submultimi::Submultimi()
{
	std::cout << "n= ";
	std::cin >> n;
	bk(0);
	std::cout << "Numarul de submultimi este: " << k << '\n';
}

void Submultimi::bk(int pas) 
{
	if (pas == n) {
		if (!st.empty()) {
			for (int i = 0; i < st.size(); i++) {
				std::cout << st[i] << " ";
			}
			std::cout << "\n";
			k++;
		}
		return;
	}
	bk(pas + 1);
	st.push_back(pas + 1);
	bk(pas + 1);
	st.pop_back();
}


Submultimi::~Submultimi()
{
}
