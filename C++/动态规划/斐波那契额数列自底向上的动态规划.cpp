#include <bits/stdc++.h>

using namespace std;

// 动态规划核心算法，先计算子问题，在由子问题计算父问题

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	int *memo=new int[n];
	memo[0]=1;
	memo[1]=1;
	for(int i=2;i<n;i++){
		memo[i]=memo[i-1]+memo[i-2];
	}

	cout<<memo[n-1]<<endl;

    return 0;
}
