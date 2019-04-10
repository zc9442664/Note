#include <iostream>
using namespace std;

int sub_set[100][1000];

int rec_subset(int arr[],int i,int S)
{
    if(S==0)return 1;
    else if(i==0) return arr[i] == S ? 1 : 0;
    else if(arr[i]>S)return rec_subset(arr,i-1,S);
    else {
        if(rec_subset(arr,i-1,S-arr[i])==1){
            return 1;
        }
        else{
            rec_subset(arr,i-1,S);
        }
    }
    return 0;
}

int main()
{
    int S;
    int n;
    int arr[100];
    cin>>S>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec_subset(arr,n,S)<<endl;


    return 0;
}
