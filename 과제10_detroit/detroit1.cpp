#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

struct Set {
	int a = 0, b = 0, v = 0, p = 0, nums[9] = { 1,1,1,1,1,1,1,1,1 };
	Set* next, * hor, * ver;
};
int pizza[9][9], N, cases;
vector<Set*> vec1, vec2;

void inputdata() {
	FILE* inp = fopen("sampleData/4.inp", "r");
	fscanf(inp, "%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(inp, "%d", &pizza[i][j]);
		}
	}
	fclose(inp);
	return;
}
void outputdata(int a) {
	FILE* out = fopen("detroit.out", "w");
	if (a == -1) {
		fprintf(out, "%d", 0);
		//printf("%d\n", 0);
	}
	else if (a == 1) {
		fprintf(out, "%d", 1);
		//printf("%d\n", 1);
	}
	else {
		fprintf(out, "%d", cases);
		//printf("%d\n", cases);
	}
	fclose(out);
}

bool sorting(Set* A, Set* B) {
	if (A->v > B->v) {
		return true;
	}
	else {
		return A->p < B->p ? true : false;
	}
}
int makefirstpizza() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pizza[i][j] == 0) {
				int temp[9] = { 1,1,1,1,1,1,1,1,1 };
				for (int k = 0; k < N; k++) {
					if (pizza[i][k] != 0) {
						temp[pizza[i][k] - 1] = 0;
					}
					if (pizza[k][j] != 0) {
						temp[pizza[k][j] - 1] = 0;
					}
				}
				int cnt = 0, index = 0;
				for (int k = 0; k < N; k++) {
					if (temp[k] == 1) {
						cnt++;
						index = k;
					}
				}
				if (cnt == 0) {
					return -1;
				}
				if (cnt == 1) {
					pizza[i][j] = index + 1;
					i = 0;
					j = 0;
				}
			}
			else if (pizza[i][j] != 0) {
				for (int k = 0; k < N; k++) {
					if (pizza[i][j] != 0 && j != k && pizza[i][j] == pizza[i][k]) {
						return -1;
					}
					if (pizza[i][j] != 0 && i != k && pizza[i][j] == pizza[k][j]) {
						return -1;
					}
				}
			}
		}
	}
}

int makeset() {
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Set* set = new Set;
			set->a = i;
			set->b = j;
			if (pizza[i][j] == 0) {
				flag = 1;
				for (int k = 0; k < N; k++) {
					if (pizza[i][k] != 0) {
						set->nums[pizza[i][k] - 1] = 0;
					}
					if (pizza[k][j] != 0) {
						set->nums[pizza[k][j] - 1] = 0;
					}
				}
				for (int k = 0; k < N; k++) {
					if (set->nums[k] == 1) {
						set->p++;
					}
				}
			}
			else if (pizza[i][j] != 0) {
				set->v = pizza[i][j];
				set->p = 1;
				for (int k = 0; k < N; k++) {
					if (k != pizza[i][j] - 1)
						set->nums[k] = 0;
				}
			}
			vec1.push_back(set);
		}
	}
	if (flag == 0) {
		return 1;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((N * i + j) % N == N - 1) {
					vec1[N * i + j]->hor = vec1[N * i];
				}
				else {
					vec1[N * i + j]->hor = vec1[N * i + j + 1];
				}
				if ((N * i + j) < vec1.size() && (N * i + j) >= vec1.size() - N) {
					vec1[N * i + j]->ver = vec1[j];
				}
				else {
					vec1[N * i + j]->ver = vec1[(N * i) + N + j];
				}
			}
		}
		for (int i = 0; i < vec1.size(); i++) {
			if (vec1[i]->v == 0) {
				vec2.push_back(vec1[i]);
			}
		}
		sort(vec2.begin(), vec2.end(), sorting);
		for (int i = 0; i < vec2.size(); i++) {
			if (i == vec2.size() - 1) {
				vec2[i]->next = nullptr;
			}
			else {
				vec2[i]->next = vec2[i + 1];
			}
		}
		return 0;
	}
}

void put_topping(Set* key) {
	if (key->next == nullptr) {
		cases++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (key->nums[i] == 1) {
			int flag = 0;
			for (auto it = key->hor; it != key; it = it->hor) {
				if (it->v == i + 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				for (auto it = key->ver; it != key; it = it->ver) {
					if (it->v == i + 1) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				key->v = i + 1;
				put_topping(key->next);
				key->v = 0;
			}
		}
	}
}

int main() {
	clock_t start, end;
	start = clock();
	inputdata();
	int flag = makefirstpizza();
	if (flag == -1) {
		outputdata(-1);
	}
	else {
		flag = makeset();
	}
	if (flag == 1) {
		outputdata(1);
	}
	else if (flag == 0) {
		put_topping(vec2[0]);
		outputdata(0);
	}
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC;
}