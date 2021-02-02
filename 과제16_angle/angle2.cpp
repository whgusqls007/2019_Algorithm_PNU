#define _CRT_SECURE_NO_WARNINGS 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

FILE* inp = fopen("sampleData/1.inp", "r");
FILE* out = fopen("angle.out", "w");

struct point {
	int index = 0, length = 0;
	float slope = 0, Case = 0;
};
int N;
vector<point*> P;

void slope(int x, int y, point* temp) {
	if (x > 0 && y > 0) { temp->Case = 1.0; }
	else if (x < 0 && y > 0) { temp->Case = 2.0; }
	else if (x < 0 && y < 0) { temp->Case = 3.0; }
	else { temp->Case = 4.0; }
	temp->slope = (float)y / (float)x;
}

bool sorting(point* A, point* B) {
	if (A->Case < B->Case) { return true; }
	else if (A->Case > B->Case) { return false; }
	else {
		if (A->slope < B->slope) { return true; }
		else if (A->slope > B->slope) { return false; }
		else { return A->length < B->length; }
	}
}

int main() {
	fscanf(inp, "%d", &N);
	for (int i = 1; i < N + 1; i++) {
		point* temp = new point;
		int x, y;
		fscanf(inp, "%d", &x);
		fscanf(inp, "%d", &y);
		if (x > 0 && y == 0) { temp->Case = 0.5; }
		else if (x == 0 && y > 0) { temp->Case = 1.5; }
		else if (x < 0 && y == 0) { temp->Case = 2.5; }
		else if (x == 0 && y < 0) { temp->Case = 3.5; }
		else { slope(x, y, temp); }
		temp->length = abs(x) + abs(y);
		temp->index = i;
		P.push_back(temp);
	}
	sort(P.begin(), P.end(), sorting);
	for (int i = 0; i < N; i++) {
		fprintf(out, "%d\n", P[i]->index);
		//printf("%d\n", P[i]->index);
	}
	return 0;
}