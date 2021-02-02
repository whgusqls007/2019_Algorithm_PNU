#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int S, D, T, W, N, date, times, arr[366] = { 0, }, price[366] = { 0, };

FILE* input_file() {
	FILE* a = fopen("ticket.inp", "r");
	return a;
}

FILE* output_file() {
	FILE* a = fopen("ticket.out", "w");
	return a;
}

void input_data(FILE* inp) {
	int remove_warning;
	remove_warning = fscanf(inp, "%d", &S);
	remove_warning = fscanf(inp, "%d", &D);
	remove_warning = fscanf(inp, "%d", &T);
	remove_warning = fscanf(inp, "%d", &W);
	remove_warning = fscanf(inp, "%d", &N);
}

void daily_count(FILE* inp) {
	int remove_warning;
	for (int i = 0; i < N; i++) {
		remove_warning = fscanf(inp, "%d", &date);
		remove_warning = fscanf(inp, "%d", &times);
		arr[date] = times;
	}
}

int least_price() {
	int min = 0;
	for (int i = 1; i < date + 1; i++) {
		min = std::min(price[i - 1] + arr[i] * S, price[i - 1] + D);
		if (i >= 3) { min = std::min(price[i - 3] + T, min); }
		if (i >= 7 && i % 7 == 0) { min = std::min(price[i - 7] + W, min); }
		price[i] = min;
	}
	return min;
}

int main() {
	FILE* inp = input_file();
	input_data(inp);
	daily_count(inp);
	fclose(inp);
	FILE* out = output_file();
	fprintf(out, "%d", least_price());
	fclose(out);
	return 0;
}