#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
std::string s1, s2, table[501][501];

FILE* inp_open() {
	return fopen("sampleData/2.inp", "r");
}

FILE* out_open() {
	return fopen("2.out", "w");
}

void print(FILE* out, std::string answer) {
	for (int i = 0; i < answer.size(); i++) {
		printf("%c", answer[i]);
		//fprintf(out, "%c", answer[i]);
	}
}

bool sorting(std::string& a, std::string& b) {
	if (a.length() == b.length()) { 
		return a < b; 
	}

	else { 
		return a.length() < b.length(); 
	}
}

std::string checkstring(const int a, const int b) {
	std::string s1, s2, s3, s4;
	if (a - 1 >= 0 && b - 1 >= 0) { 
		s1 = table[a - 1][b - 1]; 
	}
	if (a - 1 >= 0 && b - 2 >= 0) { 
		s2 = table[a - 1][b - 2]; 
	}
	if (a - 2 >= 0 && b - 1 >= 0) { 
		s3 = table[a - 2][b - 1]; 
	}
	if (a - 2 >= 0 && b - 2 >= 0) { 
		s4 = table[a - 2][b - 2]; 
	}
	if (s1 == "" && s2 == "" && s3 == "" && s4 == "") { 
		return ""; 
	}
	return std::max(std::max(s1, s2), std::max(s3, s4));
}

std::string LCS() {
	std::vector<std::string> vec;
	std::string answer;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] != s2[j]) { table[i][j] = ""; }
			else {
				table[i][j] = checkstring(i, j) + s1[i];
				if (table[i][j].length() == answer.length())
					answer = table[i][j];
				else if (table[i][j].length() > answer.length()) {
					answer = std::max(table[i][j], answer);
					vec.push_back(answer);
				}
			}
		}
	}
	sort(vec.begin(), vec.end(), sorting);
	return vec.back();
}

void getstring1(FILE* inp){
	/*char c1[501], c2[501];
	fscanf(inp, "%s", c1);
	fscanf(inp, "%s", c2);
	s1 = c1; s2 = c2;*/
}

int main() {
	clock_t start, end;
	start = clock();
	//FILE* inp = inp_open();
	//getstring1(inp);
	ios_base::sync_with_stdio(false);
	ifstream inp("sampleData/3.inp");
	inp.tie(NULL);
	inp >> s1 >> s2;
	//FILE* out = out_open();
	ofstream out("3.out");
	out.tie(NULL);
	out << LCS() << endl;
		//print(out, LCS());
	end = clock();
	cout << double(end - start);
	return 0;
}