#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

ifstream f("input.txt");

int chk_inc(long x) {

	while (x) {
		if (x % 10 < x / 10 % 10)
			return 0;
		x /= 10;
	}
	return 1;
}
int chk_sim(long x) {
	while (x) {
		if (x % 10 == x / 10 % 10)
			return 1;
		x /= 10;
	}
	return 0;
}
int m[11];
int chk_sim_2(long x) {
	for (int i = 0; i < 10; i++)
		m[i] = 0;
	long aux = x;
	while (aux) {
		int a = 0;
		if (aux % 10 == aux / 10 % 10) {
			m[aux%10]++;
		}
		aux /= 10;
	}
	if ((sizeof(m)/sizeof(m[0])) >= 1) {
		for (int i = 0; i < 10; i++) {
			if (m[i] == 1)
				return 1;
		}
	}
	return 0;
}



int main()
{
	string s1;
	f >> s1;
	char *p = strtok((char*)s1.c_str(), "-");
	long x = atol(p);
	p = strtok(NULL, "-");
	long y = atol(p);
	int c = 0;
	for (long i = x; i <= y; i++) {
		if (chk_inc(i) && chk_sim_2(i)) { //replace with chk_sim() for part 1
			c++;
		}
	}
	cout << c << endl;
}
