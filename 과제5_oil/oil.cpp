#include "oil.h"
int i, j;
void oilwell_beg(int start, int finish, int flag) {
    int observation = observe(start, finish);
    if (observation == 2)
        oilwell_beg(start, (start + finish) / 2, flag / 2);
    else if (observation == 0)
        oilwell_beg(finish + 1, finish + flag, flag);
    else
        i = start;
}
void oilwell_end(int start, int finish, int flag) {
    int observation = observe(start, finish);
    if (observation == 2)
        oilwell_end(start, (start + finish) / 2, flag / 2);
    else if (observation == 1)
        oilwell_end(finish + 1, finish + flag, flag);
    else
        j = --start;
}
int main() {
	initial();
    int N = oil_size() - 1;
    oilwell_beg(0, N, N);
	oilwell_end(i, N, N - i - 1);
    oil_report(i, j);
}