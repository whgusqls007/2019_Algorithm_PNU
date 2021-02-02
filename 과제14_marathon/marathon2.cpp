#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

FILE* inp = fopen("marathon.inp", "r");
FILE* out = fopen("marathon.out", "w");

struct node {
	int point, cur_dist = 0, dist[51] = { 0, };
	bool visit[51][51] = { 0, };
};

int K, min_dist = INF;
node nodelst[51];

void arrcopy(bool a[][51], bool b[][51]) {
	for (int i = 1; i < K + 1; i++) {
		for (int j = 1; j < K + 1; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void marathon() {
	for (int i = 1; i < K + 1; i++) {
		queue<node> Q;
		Q.push(nodelst[i]);
		while (!Q.empty()) {
			node current = Q.front();
			Q.pop();
			for (int j = 1; j < K + 1; j++) {
				if (current.dist[j] == 0 || current.visit[current.point][j] == 1) { continue; }
				node next = nodelst[j];
				arrcopy(current.visit, next.visit);
				next.visit[current.point][j] = next.visit[j][current.point] = 1;
				next.cur_dist = current.cur_dist + current.dist[j];
				if (next.cur_dist < min_dist) {
					if (next.point == nodelst[i].point) { min_dist = next.cur_dist; }
					else { Q.push(next); }
				}
			}
		}
	}
}

int main() {
	fscanf(inp, "%d", &K);
	for (int i = 1; i < K + 1; i++) {
		nodelst[i].point = i;
		while (1) {
			int vertex, edge;
			fscanf(inp, "%d", &vertex);
			if (vertex == 0) { break; }
			fscanf(inp, "%d", &edge);
			nodelst[i].dist[vertex] = edge;
		}
	}
	marathon();
	if (min_dist == INF) { fprintf(out, "%d", 0); }
	else { fprintf(out, "%d", min_dist); }
	return 0;
}
