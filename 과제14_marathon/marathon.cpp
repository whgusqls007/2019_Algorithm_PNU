#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

FILE* inp = fopen("sampleData/1.inp", "r"), * out = fopen("marathon.out", "w");
struct node { int point, cur_dist = 0, dist[51] = { 0, }; };
int K;
node nodelst[51];

int marathon() {
	int min_dist = INF;
	for (int i = 1; i < K + 1; i++) {
		queue<node> Q;
		Q.push(nodelst[i]);
		while (!Q.empty()) {
			for (int j = 1; j < K + 1; j++) {
				if (Q.front().dist[j] == 0) { continue; }
				node next_point = nodelst[j];
				if (next_point.dist[Q.front().point] != 0) { next_point.dist[Q.front().point] = 0; }
				next_point.cur_dist = Q.front().cur_dist + Q.front().dist[j];
				if (min_dist > next_point.cur_dist) {
					if (next_point.point == nodelst[i].point) { min_dist = next_point.cur_dist; }
					else { Q.push(next_point); }
				}
			}
			Q.pop();
		}
	}
	return min_dist == INF ? 0 : min_dist;
}

int main() {
	fscanf(inp, "%d", &K);
	for (int i = 1; i < K + 1; i++) {
		int temp;
		fscanf(inp, "%d", &temp);
		nodelst[temp].point = i;
		while (1) {
			int vertex;
			fscanf(inp, "%d", &vertex);
			if (vertex == 0) { break; }
			fscanf(inp, "%d", &nodelst[i].dist[vertex]);
		}
	}
	fprintf(out, "%d", marathon());
}