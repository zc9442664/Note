#include <bits/stdc++.h>

using namespace std;

// 备忘录法也是比较好理解的，创建了一个n+1大小的数组来保存求出的斐波拉契数列中的每一个值，
// 在递归的时候如果发现前面fib（n）的值计算出来了就不再计算，如果未计算出来，
// 则计算出来后保存在Memo数组中，下次在调用fib（n）的时候就不会重新递归了。
// 比如上面的递归树中在计算fib（6）的时候先计算fib（5），调用fib（5）算出了fib（4）后，
// fib（6）再调用fib（4）就不会在递归fib（4）的子树了，
// 因为fib（4）的值已经保存在Memo[4]中。

int Fibonacci(int n);
int fib(int n,int *memo);

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	cout<<Fibonacci(n)<<endl;

    return 0;
}

int Fibonacci(int n){
	if(n<=0) return n;
	int *memo=new int[n+1];
	for(int i=0;i<=n;i++){
		memo[i]=-1;
	}
	return fib(n,memo);
}

int fib(int n,int *memo){
	if(memo[n]!=-1) return memo[n];
	if(n<=2) memo[n]=1;
	else memo[n]=fib(n-1,memo)+fib(n-2,memo);
	return memo[n];
}