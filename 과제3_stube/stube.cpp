/*#include <bits/stdc++.h>

using namespace std;

class Coordinate {
public:
	long double x = 0, y = 0, z = 0;
};

long double distance(Coordinate A, Coordinate B, Coordinate P, long double t) {
	if (t >= 1) {
		return sqrt(pow(B.x - P.x, 2) + pow(B.y - P.y, 2) + pow(B.z - P.z, 2));
	}
	else if (0 < t && t < 1) {
		return (long double)sqrt((-1 * pow(((A.x - P.x) * (B.x - A.x) + (A.y - P.y) * (B.y - A.y) + (A.z - P.z) * (B.z - A.z)), 2)
			/ ((pow(B.x - A.x, 2) + pow(B.y - A.y, 2) + pow(B.z - A.z, 2)))) + pow(A.x - P.x, 2) + pow(A.y - P.y, 2) + pow(A.z - P.z, 2));
	}
	else {
		return sqrt(pow(A.x - P.x, 2) + pow(A.y - P.y, 2) + pow(A.z - P.z, 2));
	}
}

long double solve(Coordinate A, Coordinate B, Coordinate P) {
	long double location;
	location = (long double)(-1 * ((A.x - P.x) * (B.x - A.x) + (A.y - P.y) * (B.y - A.y) + (A.z - P.z) * (B.z - A.z)) / ((pow(B.x - A.x, 2) + pow(B.y - A.y, 2) + pow(B.z - A.z, 2))));
	return distance(A, B, P, location);
}

long double pickSP(Coordinate A, Coordinate B, Coordinate C, Coordinate D) {
	long double i = 0, l = 0, least = 10000000000;
	Coordinate P, Pt, T;
	vector<long double> vec;
	while (i < 1.01) {
		Pt.x = i * A.x + (1 - i) * B.x;
		Pt.y = i * A.y + (1 - i) * B.y;
		Pt.z = i * A.z + (1 - i) * B.z;
		long double d = solve(C, D, Pt);
		vec.push_back(d);
		if (least > d) {
			least = d;
			P.x = Pt.x;
			P.y = Pt.y;
			P.z = Pt.z;
			l = i;
		}
		i += 0.25;
	}
	long double min = *min_element(vec.begin(), vec.end());
	long double max = *max_element(vec.begin(), vec.end());
	if (min == 0) {
		return 0;
	}
	if (round(min * 100000000) / 100000000 == round(max * 100000000) / 100000000) {
		return least;
	}
	if (l == 1) {
		T.x = 0.75 * A.x + 0.25 * B.x;
		T.y = 0.75 * A.y + 0.25 * B.y;
		T.z = 0.75 * A.z + 0.25 * B.z;
		return pickSP(T, P, C, D);
	}
	else if (1 > l&& l >= 0.75) {
		T.x = 0.5 * A.x + 0.5 * B.x;
		T.y = 0.5 * A.y + 0.5 * B.y;
		T.z = 0.5 * A.z + 0.5 * B.z;
		return pickSP(T, A, C, D);
	}
	else if (0.25 < l && l < 0.75) {
		T.x = 0.25 * A.x + 0.75 * B.x;
		T.y = 0.25 * A.y + 0.75 * B.y;
		T.z = 0.25 * A.z + 0.75 * B.z;
		Pt.x = 0.75 * A.x + 0.25 * B.x;
		Pt.y = 0.75 * A.y + 0.25 * B.y;
		Pt.z = 0.75 * A.z + 0.25 * B.z;
		return pickSP(T, Pt, C, D);
	}
	else if (0 < l && l <= 0.25) {
		T.x = 0.5 * A.x + 0.5 * B.x;
		T.y = 0.5 * A.y + 0.5 * B.y;
		T.z = 0.5 * A.z + 0.5 * B.z;
		return pickSP(B, T, C, D);
	}
	else if (l == 0) {
		T.x = 0.25 * A.x + 0.75 * B.x;
		T.y = 0.25 * A.y + 0.75 * B.y;
		T.z = 0.25 * A.z + 0.75 * B.z;
		return pickSP(P, T, C, D);
	}
}

int main() {
	fstream inp("stube.inp");
	ofstream out("stube.out");
	Coordinate A, B, C, D;
	inp >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z >> D.x >> D.y >> D.z;
	inp.close();
	long double ab_to_cd, cd_to_ab, result;
	ab_to_cd = pickSP(A, B, C, D);
	cd_to_ab = pickSP(C, D, A, B);
	out << ceil(min(ab_to_cd, cd_to_ab)) << endl;
	out.close();
}*/

#include <iostream>

int main() {
	for (int i : {2, 3, 5, 7, 9}) { std::cout << i << std::endl; }
}