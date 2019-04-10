#include<iostream>

using namespace std;

int arr[100];
int sub_set[100];
int n;

void dp()
{
    sub_set[0]=arr[0];
    sub_set[1]=max(arr[0],arr[1]);
    for(int i=2; i<n; i++)
    {
        int a=sub_set[i-1];
        int b=sub_set[i-2]+arr[i];
        sub_set[i]=max(a,b);
    }
    cout<<sub_set[n-1]<<endl;
}
void input()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    intput();
    dp();

    return 0;
}
