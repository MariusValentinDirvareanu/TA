#include "ComisVoiajor.h"



ComisVoiajor::ComisVoiajor()
{
	fin.open("comis.txt");
	lgMin = INT_MAX;

	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		fin >> x >> y >> z;
		ad[x][y] = ad[y][x] = z;
	}

	vis[tr[1] = 1] = true;
	bkt(2);


	std::cout << lgMin << '\n';
	for (int i = 1; i <= n; ++i)
		std::cout << trMin[i] << ' ';
	std::cout << '\n';
}

void ComisVoiajor::bkt(int pos) {
	if (lg >= lgMin)
		return;

	if (pos == n + 1) {
		if (!ad[tr[n]][1])
			return;

		lg += ad[tr[n]][1];
		if (lg < lgMin) {
			lgMin = lg;
			for (int i = 1; i <= n; i++)
				trMin[i] = tr[i];
		}

		lg -= ad[tr[n]][1];
		return;
	}

	for (int i = 2; i <= n; i++)
		if (!vis[i] && ad[tr[pos - 1]][i]) {
			vis[tr[pos] = i] = true;
			lg += ad[i][tr[pos - 1]];

			bkt(pos + 1);

			vis[i] = false;
			lg -= ad[i][tr[pos - 1]];
		}
}


ComisVoiajor::~ComisVoiajor()
{
}
