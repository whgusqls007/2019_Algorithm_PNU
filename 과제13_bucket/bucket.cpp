#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

FILE* inp = fopen("sampleData/3.inp", "r");
FILE* out = fopen("bucket.out", "w");

int k, vol[6];

struct bucket {
	vector<int> water;
	int use = 0;
	bucket* af = nullptr,* bf = nullptr;
}B;
vector<int> G;
queue<bucket> Q;
bool visit[21][21][21][21][21][21];
int arr[6];
int BFS() {
	if (B.water == G) { return 0; }
	/*for (int i = 0; i < k; i++) {
		arr[i] = B.water[i];
	}
	visit[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]] = true;*/
	bucket start, end;
	start.af = &end;
	end.bf = &start;
	while (!Q.empty()) {
		bucket now = Q.front();
		now.af = nullptr;
		now.bf = nullptr;
		Q.pop();
		now.use++;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j || now.water[i] == 0) continue;
				bucket next = now;
				int cur_water = now.water[i] + now.water[j];
				if (cur_water > vol[j]) {
					next.water[j] = vol[j];
					next.water[i] = cur_water - vol[j];
				}
				else if (cur_water <= vol[j]) {
					next.water[j] = cur_water;
					next.water[i] = 0;
				}
				if (next.water == G) {
					return next.use;
				}
				bucket find = start;
				while (find.af != nullptr) {
					if (find.water == next.water) { break; }
					find = *find.af;
				}
				if (find.af == nullptr) {
					next.bf = end.bf;
					end.bf->af = &next;
					next.af = &end;
					Q.push(next);
				}
				/*for (int l = 0; l < k; l++) {
					arr[l] = next.water[l];
				}
				if (visit[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]] == false) {
					visit[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]][arr[5]] = true;
					Q.push(next);
				}*/
			}
		}
	}
	return 0;
}

int main(){
	fscanf(inp, "%d", &k);
	for (int i = 0; i < k; i++) {
		int temp;
		fscanf(inp, "%d", &vol[i]);
	}
	for (int i = 0; i < k; i++) {
		int temp;
		fscanf(inp, "%d", &temp);
		B.water.push_back(temp);
	} 
	for (int i = 0; i < k; i++) {
		int temp;
		fscanf(inp, "%d", &temp);
		G.push_back(temp);
	}
	fclose(inp);
	Q.push(B);
	//fprintf(out, "%d", BFS());
	printf("%d\n", BFS());
	fclose(out);
	return 0;
}