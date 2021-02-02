#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF int(1e9)
using namespace std;

typedef struct{ //�� ������ ��ȣ, ����, ��ǥ�� �����ϴ� ����ü
	int h = 0, w = 0, x = 0, y = 0;
	bool visit = 0;
}Set;

int N, startweight = 1, minprice = INF; //���۹��Դ� 1�� �д�(��й���), �ּҰ��� ���Ѵ�� ����

Set* point[21];	// ����ü Set�� �迭, �ִ� 20�̹Ƿ� 21�� �ΰ� 0�� ���� �ʴ´�.

bool sorting_h(Set *a, Set *b) {
	return a->h < b->h ? true : false; // ��ȣ����� ����, ��������.
}

bool sorting_w(Set *a, Set *b) {
	return a->w > b->w ? true : false; // ���Լ���� ����, ��������(���ſ� �� ���� ������ ����)
}

void inputdata() {
	FILE* inp = fopen("sampleData/1.inp", "r");
	fscanf(inp, "%d", &N);
	for (int i = 1; i <= N; i++) {
		point[i] = new Set;
		fscanf(inp, "%d", &point[i]->h);
		fscanf(inp, "%d", &point[i]->w);
		fscanf(inp, "%d", &point[i]->x);
		fscanf(inp, "%d", &point[i]->y);
		startweight += point[i]->w; // �� ���� ���( ���۹��� 1�̹Ƿ� �� ���԰� 20�̸� 21�� ������, ���� �� ������ ���ƿö��� ����)
	}

	fclose(inp);
	sort(point + 1, point + N + 1, sorting_h); // ��ȣ����� ����
	sort(point + 2, point + N + 1, sorting_w); // h�� 2���� ���Լ���� ����(������ ������ 1�̹Ƿ�)
}

void outputdata() {
	FILE* out = fopen("drone.out", "w");
	fprintf(out, "%d", minprice);
	printf("%d\n", minprice);
	fclose(out);
	return;
}

void delivery(int index, int price, int depth) {
	int current_price;
	if (depth == 1) {
		current_price = price + (abs(point[index]->x - point[1]->x) + abs(point[index]->y - point[1]->y));
		minprice = current_price < minprice ? current_price : minprice;
		return;
	}
	startweight = startweight - point[index]->w; // �� ���Կ��� �湮�� ���� ���Ը� �� (�������϶��� ���԰� 1�̳���)
	point[index]->visit = 1; // �湮 ǥ��
	for (int i = 2; i <= N; i++) {
		if (point[i]->visit != 1) {
			current_price = price + startweight * (abs(point[index]->x - point[i]->x) + abs(point[index]->y - point[i]->y));
			if (minprice > current_price) {
				delivery(i, current_price, depth - 1);
			}
		}
	}
	point[index]->visit = 0; // �������� �湮ǥ�ø� ������.
	startweight = startweight + point[index]->w; // �������� ���Ը� �ٽ� ������.
	return;
}

int main() {
	//clock_t start, end;
	//start = clock();
	inputdata();
	delivery(1, 0, N);
	outputdata();
	//end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC;
	return 0;
}