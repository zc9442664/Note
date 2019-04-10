#include <bits/stdc++.h>

using namespace std;

// 有N件物品和一个容量为V的背包。第i件物品的价格（即体积，下同）是w[i]，价值是c[i]。
// 求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
// 这是最基础的背包问题，总的来说就是：选还是不选，这是个问题<(￣ˇ￣)/
// 相当于用f[i][j]表示前i个背包装入容量为v的背包中所可以获得的最大价值。
// 对于一个物品，只有两种情况
// 　　情况一: 第i件不放进去，这时所得价值为:f[i-1][v]
// 　　情况二: 第i件放进去，这时所得价值为：f[i-1][v-c[i]]+w[i] 

int main(int argc, char const *argv[])
{
	int f[101][101]={0};
    int T, n,value[101], wight[101];
    cin>>T>>n;
    for(int i = 1; i <= n; i++){
       cin>>wight[i]>>value[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= T; j++){
        	f[i][j] = f[i-1][j];
        }
        for(int j = 0; j+wight[i] <= T; j++){
        	f[i][j] = max(f[i][j] + value[i], f[i-1][j+wight[i]]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= T; i++){
    	ans = max(ans, f[n][i]);
    }
    cout<<ans<<endl;

    return 0;  
}