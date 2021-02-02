#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;
struct Tup {
	int a = 0, b = 0, c = 0, temp[9] = { 1,1,1,1,1,1,1,1,1 };
	Tup* next;
};
int pizza[9][9], N, cases;
vector<Tup*> index;

bool sorting(Tup* A, Tup* B) {
	return A->c < B->c ? true : false;
}

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
		printf("%d\n", 0);
	}
	else if (a == 1) {
		fprintf(out, "%d", 1);
		printf("%d\n", 1);
	}
	else {
		fprintf(out, "%d", cases);
		printf("%d\n", cases);
	}
	fclose(out);
}

int makefirstpizza() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pizza[i][j] == 0) {
				Tup* t = new Tup;
				t->a = i;
				t->b = j;
				for (int k = 0; k < N; k++) {
					if (pizza[i][k] != 0) {
						t->temp[pizza[i][k] - 1] = 0;
					}
					if (pizza[k][j] != 0) {
						t->temp[pizza[k][j] - 1] = 0;
					}
				}
				for (int k = 0; k < N; k++) {
					if (t->temp[k] == 1) {
						t->c++;
					}
				}
				if (t->c == 0) {
					return -1;
				}
				index.push_back(t);
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
	if (index.size() == 0) {
		return 1;
	}
	sort(index.begin(), index.end(), sorting);
	for (int i = 0; i < index.size(); i++) {
		if (i == index.size() - 1) {
			index[i]->next = nullptr;
		}
		else {
			index[i]->next = index[i + 1];
		}
	}
	return 0;
}

void put_topping(Tup* key) {
	if (key->next == nullptr) {
		cases++;
		return;
	}
	int a = key->a, b = key->b;
	for (int i = 0; i < N; i++) {
		if (pizza[a][i] != 0) {
			key->temp[pizza[a][i] - 1] = 0;
		}
		if (pizza[i][b] != 0) {
			key->temp[pizza[i][b] - 1] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		if (key->temp[i] == 1) {
			pizza[a][b] = i + 1;
			put_topping(key->next);
			pizza[a][b] = 0;
		}
	}
	return;
}

int main() {
	clock_t start, end;
	start = clock();
	inputdata();
	int flag = makefirstpizza();
	if (flag == -1) {
		outputdata(-1);
	}
	else if (flag == 1) {
		outputdata(1);
	}
	else {
		put_topping(index[0]);
		outputdata(0);
	}
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC;
}