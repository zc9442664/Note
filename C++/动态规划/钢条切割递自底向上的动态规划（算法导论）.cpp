#include <bits/stdc++.h>

using namespace std;
int buttom_up_cut(int *p,int n){
	int *r=new int[n+1];
	r[0]=0;
	for(int i=1;i<=n;i++){
		int q=-1;
		for(int j=1;j<=i;j++){
			q=max(q,p[j-1]+r[i-j]);
		}
		r[i]=q;
	}
	return r[n];
}
int main(int argc, char const *argv[])
{
	int n;
	int p[11]={1,5,8,9,10,17,17,20,24,30};
	cin>>n;
	
	cout<<buttom_up_cut(p,n)<<endl;

	return 0;
}