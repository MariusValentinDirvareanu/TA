#include "ComisVoiajor.h"



ComisVoiajor::ComisVoiajor()
{
	fin.open("comis.txt");
	lgMin = INT_MAX;

	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		fin >> x >> y >> z;
		ad.at(x).at(y) = ad.at(y).at(x) = z;
	}

	vis.at(tr.at(1) = 1) = true;
	bkt(2);

	std::cout << lgMin << '\n';
	for (int i = 1; i <= n; i++)
		std::cout << trMin.at(i) << ' ';
	std::cout << '\n';
}

void ComisVoiajor::bkt(int pos) {
	if (lg >= lgMin)
		return;

	if (pos == n + 1) {
		if (!ad.at(tr.at(n)).at(1))
			return;

		lg += ad.at(tr.at(n)).at(1);
		if (lg < lgMin) {
			lgMin = lg;
			for (int i = 1; i <= n; i++)
				trMin.at(i) = tr.at(i);
		}

		lg -= ad.at(tr.at(n)).at(1);
		return;
	}

	for (int i = 2; i <= n; i++)
		if (!vis.at(i) && ad.at(tr.at(pos - 1)).at(i)) {
			vis.at(tr.at(pos) = i) = true;
			lg += ad.at(i).at(tr.at(pos - 1));

			bkt(pos + 1);

			vis.at(i) = false;
			lg -= ad.at(i).at(tr.at(pos - 1));
		}
}


ComisVoiajor::~ComisVoiajor()
{
}
