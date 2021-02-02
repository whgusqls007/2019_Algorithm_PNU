#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

FILE* inp = fopen("sampleData/3.inp", "r"), * out = fopen("lock.out", "w");
struct Index { int i, j; };
Index start_index;
int N, M;
char roadview[31][31];
vector<Index> ans;

void outputData(bool Case) {
	if (Case == 0) {
		//printf("%d", 0);
		fprintf(out, "%d", 0);
	}
	else {
		//printf("%d\n", ans.size());
		fprintf(out, "%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			//printf("%d %d\n", ans[i].i, ans[i].j);
			fprintf(out, "%d %d\n", ans[i].i, ans[i].j);
		}
	}
	fclose(out);
}

void inputData() {
	fscanf(inp, "%d", &N);
	fscanf(inp, "%d", &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			fscanf(inp, " %c", &temp);
			roadview[j][N - 1 - i] = temp;
			if (temp == 'S') {
				start_index.i = j;
				start_index.j = N - 1 - i;
			}
		}
	}
	fclose(inp);
}

bool LockDown() {
	bool visit[31][31] = { 0, }, check = 0;
	queue<Index> Q;
	Q.push(start_index);
	while (!Q.empty()) {
		Index cur = Q.front();
		Q.pop();
		if (cur.i - 1 > -1 && roadview[cur.i - 1][cur.j] != '#') {
			Index next = cur;
			next.i = cur.i - 1;
			if (visit[next.i][next.j] != 1) {
				if (roadview[next.i][next.j] == 'T') {
					check = 1;
					break;
				}
				visit[next.i][next.j] = 1;
				Q.push(next);
			}
		}
		if (cur.i + 1 < M && roadview[cur.i + 1][cur.j] != '#') {
			Index next = cur;
			next.i = cur.i + 1;
			if (visit[next.i][next.j] != 1) {
				if (roadview[next.i][next.j] == 'T') {
					check = 1;
					break;
				}
				visit[next.i][next.j] = 1;
				Q.push(next);
			}
		}
		if (cur.j - 1 > -1 && roadview[cur.i][cur.j - 1] != '#') {
			Index next = cur;
			next.j = cur.j - 1;
			if (visit[next.i][next.j] != 1) {
				if (roadview[next.i][next.j] == 'T') {
					check = 1;
					break;
				}
				visit[next.i][next.j] = 1;
				Q.push(next);
			}
		}
		if (cur.j + 1 < N && roadview[cur.i][cur.j + 1] != '#') {
			Index next = cur;
			next.j = cur.j + 1;
			if (visit[next.i][next.j] != 1) {
				if (roadview[next.i][next.j] == 'T') {
					check = 1;
					break;
				}
				visit[next.i][next.j] = 1;
				Q.push(next);
			}
		}
	}
	return check == 1 ? 1 : 0;
}

int main() {
	clock_t start, end;
	start = clock();
	inputData();
	LockDown();
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	if (LockDown()) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (roadview[i][j] == '_') {
					roadview[i][j] = '#';
					if (!LockDown()) {
						Index temp;
						temp.i = i + 1; temp.j = j + 1;
						ans.push_back(temp);
					}
					roadview[i][j] = '_';
				}
			}
		}
		outputData(1);
	}
	else {
		outputData(0);
	}
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC;
	return 0;
}