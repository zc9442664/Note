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
	int prim[1000];
	int index=0;
	for(int i=2;i<1000;i++){
		if(prime(i)==1){
			prim[index]=i;
			index++;
		}
	}
	while (x--) {
		cin >> n;
		int m = n;
		int cnt = 0;
		int a[100] = { 0 };
		while (prim[cnt] <= n) {
			if (n >= prim[cnt] && n % prim[cnt] == 0) {
				n = n / prim[cnt];
				a[prim[cnt]]++;
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