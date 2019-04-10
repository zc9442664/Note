#include <bits/stdc++.h>

using namespace std;

int cut(int *p, int n){
	if(n==0) return 0;
	int q=0;
	for(int i=1;i<=n;i++){
		q=max(q,p[i-1]+cut(p,n-i));
	}
	return q;
}

int main(int argc, char const *argv[])
{
	int n;
	int p[11]={1,5,8,9,10,17,17,20,24,30};
	cin>>n;
	cout<<cut(p,n)<<endl;

	return 0;
}