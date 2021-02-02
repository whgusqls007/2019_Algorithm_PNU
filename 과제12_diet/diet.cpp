#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

FILE* inp = fopen("diet.inp", "r");
FILE* out = fopen("diet.out", "w");
struct Food {
	int p, f, s, v, c, pick;
};

int N, min_cost = 987654321, sum_cal;
vector<int> answer;
Food* lst[31];

void DIET(int p, int f, int s, int v, int cur_cost, vector<int> ans) {
	int cnt = 0, index = -1;
	cnt += p > 0;
	cnt += f > 0;
	cnt += s > 0;
	cnt += v > 0;
	if (cnt == 0){
		if (min_cost > cur_cost) {
			min_cost = cur_cost;
			sum_cal = p + f + s + v;
			answer = ans;
		}
		else if (min_cost == cur_cost) {
			if (sum_cal > p + f + s + v) { 
				sum_cal = p + f + s + v;
				answer = ans;
			}
			else if (sum_cal == p + f + s + v) { 
				if (answer.size() < ans.size()) {
					answer = ans;
				}
				else if (answer.size() == ans.size()) {
					if (answer > ans) {
						answer = ans;
					}
				}
			}
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (lst[i]->pick == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) { return; }
	lst[index]->pick++;
	DIET(p, f, s, v, cur_cost, ans);
	if (find(ans.begin(), ans.end(), index + 1) == ans.end()) { ans.push_back(index + 1); }
	p -= lst[index]->p;
	f -= lst[index]->f;
	s -= lst[index]->s;
	v -= lst[index]->v;
	DIET(p, f, s, v, cur_cost + lst[index]->c, ans);
	lst[index]->pick--;
	return;
}

int main() {
	int p, f, s, v;
	fscanf(inp, "%d", &N);
	fscanf(inp, "%d", &p);
	fscanf(inp, "%d", &f);
	fscanf(inp, "%d", &s);
	fscanf(inp, "%d", &v);
	vector<int> free_food;
	for (int i = 0; i < N; i++) {
		lst[i] = new Food;
		fscanf(inp, "%d", &lst[i]->p);
		fscanf(inp, "%d", &lst[i]->f);
		fscanf(inp, "%d", &lst[i]->s);
		fscanf(inp, "%d", &lst[i]->v);
		fscanf(inp, "%d", &lst[i]->c);
		if (lst[i]->c == 0) {
			free_food.push_back(i + 1);
		}
		lst[i]->pick = 0;
	}
	fclose(inp);
	DIET(p, f, s, v, 0, vector<int>(0));
	for (int i = 0; i < free_food.size(); i++) {
		answer.push_back(vec[i]);
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		fprintf(out, "%d ", answer[i]);
		//printf("%d ", answer[i]);
	}
	fclose(out);
	return 0;
}