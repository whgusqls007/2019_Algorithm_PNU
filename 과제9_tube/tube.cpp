#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> vec, l;
int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	ifstream inp("tube.inp");
	inp >> N >> K;
	vec.assign(N + 1, 100001);
	vec[0] = 0;
	for (int i = 0; i < K; i++) {
		int temp;
		inp >> temp;
		l.push_back(temp);
	}
	inp.close();
	for (int i = 0; i < K; i++) {
		for (int j = l[i]; j < N + 1; j++) {
			vec[j] = min(vec[j], vec[j - l[i]] + 1);
		}
	}
	ofstream out("tube.out");
	if (vec[N] != 100001) {
		out << vec[N];
	}
	else {
		out << 0;
	}
	out.close();
}