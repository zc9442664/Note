#include<iostream>
using namespace std;
//一个矩阵只能从上向下或者从左往右走，找猪最小的那个值
int main()
{
	int dp[4]={0};
	int arr[4][4]={
		{1,3,5,9},
		{8,1,3,4},
		{5,0,6,1},
		{8,8,4,0}
	};
	int n=4;
	dp[0]=arr[0][0];
	for(int i=1;i<n;i++){
		arr[0][i] += arr[0][i-1];
		dp[i]=arr[0][i];
	}
	for(int i=1;i<n;i++) {
		
		for(int j=0;j<n;j++) {
			if(j==0){
				dp[j]=dp[j]+arr[i][j];
			}
			else{
				int sum1=arr[i][j]+dp[j];
				int sum2=arr[i][j]+dp[j-1];
				dp[j]=sum1>sum2?sum2:sum1;
			}
		}
	}
	int minx=dp[0];
	for(int i=1;i<n;i++){
		if(minx>dp[i]) minx=dp[i];
	}
	printf("%d\n", minx);

	return 0;
}