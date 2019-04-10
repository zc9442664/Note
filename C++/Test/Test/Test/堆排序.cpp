#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return 0;
	}
	return 1;
}

int main()
{
	int n, x;
	cin >> x;
	while (x--) {
		cin >> n;
		int m = n;
		int cnt = 2;
		int a[100] = { 0 };
		while (cnt <= n) {
			if (prime(cnt) && n%cnt == 0) {
				n = n / cnt;
				a[cnt]++;
				cnt = cnt;
			}
			else cnt++;
		}
		printf("%d=", m);
		for (int i = 0; i < cnt; i++) {
			if (a[i] != 0) {
				printf("%d", i);
				if (a[i] != 1) {
					printf("^%d", a[i]);
				}
				printf("*");
			}
		}
		printf("%d", cnt);
		if (a[cnt] > 1)printf("^%d", a[cnt]);
		printf("\n");
	}
	return 0;
}