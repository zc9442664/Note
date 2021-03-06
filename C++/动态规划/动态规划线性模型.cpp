#include <bits/stdc++.h>

// 在一个夜黑风高的晚上，有n（n <= 50）个小朋友在桥的这边，现在他们需要过桥，但是由于桥很窄，
// 每次只允许不大于两人通过，他们只有一个手电筒，所以每次过桥的两个人需要把手电筒带回来，
// i号小朋友过桥的时间为T[i]，两个人过桥的总时间为二者中时间长者。
// 问所有小朋友过桥的总时间最短是多少。
// 每次过桥的时候最多两个人，如果桥这边还有人，那么还得回来一个人（送手电筒），也就是说N个人过桥的次数为2*N-3
// （倒推，当桥这边只剩两个人时只需要一次，三个人的情况为来回一次后加上两个人的情况…）。
// 有一个人需要来回跑，将手电筒送回来（也许不是同一个人，realy？！）这个回来的时间是没办法省去的，并且回来的次数也是确定的，
// 为N-2，如果是我，我会选择让跑的最快的人来干这件事情，但是我错了…如果总是跑得最快的人跑回来的话，
// 那么他在每次别人过桥的时候一定得跟过去，于是就变成就是很简单的问题了，花费的总时间：
// T = minPTime * (N-2) + (totalSum-minPTime)
// 来看一组数据 四个人过桥花费的时间分别为 1 2 5 10，按照上面的公式答案是19，但是实际答案应该是17。
// 具体步骤是这样的：
// 第一步：1和2过去，花费时间2，然后1回来（花费时间1）；
// 第二歩：3和4过去，花费时间10，然后2回来（花费时间2）；
// 第三部：1和2过去，花费时间2，总耗时17。
// 所以之前的贪心想法是不对的。我们先将所有人按花费时间递增进行排序，假设前i个人过河花费的最少时间为opt[i]，
// 那么考虑前i-1个人过河的情况，即河这边还有1个人，河那边有i-1个人，并且这时候手电筒肯定在对岸，
// 所以opt[i] = opt[i-1] + a[1] + a[i] (让花费时间最少的人把手电筒送过来，然后和第i个人一起过河)
// 如果河这边还有两个人，一个是第i号，另外一个无所谓，河那边有i-2个人，并且手电筒肯定在对岸，
// 所以opt[i] = opt[i-2] + a[1] + a[i] + 2*a[2] (让花费时间最少的人把电筒送过来，然后第i个人和另外一个人一起过河，
// 由于花费时间最少的人在这边，所以下一次送手电筒过来的一定是花费次少的，送过来后花费最少的和花费次少的一起过河，解决问题)
// 所以 opt[i] = min{opt[i-1] + a[1] + a[i] , opt[i-2] + a[1] + a[i] + 2*a[2] }

using namespace std;
int dynamic_line(int *p,int n){
	int q=0;
	int *r=new int[4];
	r[0]=1;
	r[1]=2;
	for(int i=2;i<n;i++){
		r[i]=min(r[i-1]+p[0]+p[i],r[i-2]+p[0]+p[i]+2*p[1]);
		printf("%d\n", r[i]);
	}

	return r[n-1];
}
int main(int argc, char const *argv[])
{
	int n;
	int p[11]={1,2,5,10};
	n=4;
	cout<<dynamic_line(p,n)<<endl;

	return 0;
}