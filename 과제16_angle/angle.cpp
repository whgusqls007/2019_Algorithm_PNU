#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

FILE* inp = fopen("angle.inp", "r"), * out = fopen("angle.out", "w");
struct point { int index, x, y, length, quadrant; };
int N;
vector<point> pvec;

bool sorting_with_signed_area(point A, point B) {
	if (A.quadrant < B.quadrant) { return true; }
	else if (A.quadrant > B.quadrant) { return false; }
	else {
		if ((B.x * A.y) - (A.x * B.y) < 0) { return true; }
		else if ((B.x * A.y) - (A.x * B.y) > 0) { return false; }
		else { return A.length < B.length; }
	}
}
int main() {
	fscanf(inp, "%d", &N);
	for (int i = 0; i < N; i++) {
		point temp;
		temp.index = i + 1;
		fscanf(inp, "%d", &temp.x);
		fscanf(inp, "%d", &temp.y);
		temp.length = abs(temp.x) + abs(temp.y);
		if (temp.x > 0 && temp.y >= 0) { temp.quadrant = 1; }
		else if (temp.x <= 0 && temp.y > 0) { temp.quadrant = 2; }
		else if (temp.x < 0 && temp.y <= 0) { temp.quadrant = 3; }
		else if (temp.x >= 0 && temp.y < 0) { temp.quadrant = 4; }
		pvec.push_back(temp);
	}
	sort(pvec.begin(), pvec.end(), sorting_with_signed_area);
	for (int i = 0; i < pvec.size(); i++) { fprintf(out, "%d\n", pvec[i].index); }
}