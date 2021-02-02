#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	ifstream in("sampledata/4.inp");
	in.tie(NULL);
	int Ax, Ay, Az, Bx, By, Bz, Px, Py, Pz;
	double i = 0, Sx, Sy, Sz, max = 999999, L;
	vector<double> vec;
	in >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Px >> Py >> Pz;
	in.close();
	while (i <= 1) {
		Sx = i * Bx + (1 - i) * Ax;
		Sy = i * By + (1 - i) * Ay;
		Sz = i * Bz + (1 - i) * Az;
		L = sqrt(pow(Px - Sx, 2) + pow(Py - Sy, 2) + pow(Pz - Sz, 2));
		if (max > L) {
			max = L;
		}
		if (max < L) {
			break;
		}
		i += 0.00005;
	}
	ofstream out("1.out");
	out.tie(NULL);
	out << ceil(L);
	return 0;
}