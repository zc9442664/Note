#include<bits/stdc++.h>

using namespace std;

#define Len 6

void initalise(int parent[],int rank_root[]){
    for(int i=0;i<6;i++){
        parent[i]=-1;
        rank_root[i]=-1;
    }
}

int find_root(int x,int parent[]){
    int x_root=x;
    while(parent[x_root]!=-1){
        x_root=parent[x_root];
    }
    return x_root;
}
int union_vertices(int x,int y,int parent[],int rank_root[]){
    int x_root=find_root(x,parent);
    int y_root=find_root(y,parent);
    if(x_root==y_root){
        return 0;
    }else{
        if(rank_root[x_root]>rank_root[y_root]){
            parent[y_root]=x_root;
        }
        else if(rank_root[x_root]<rank_root[y_root]){
            parent[x_root]=y_root;
        }
        else{
            parent[x_root]=y_root;
            rank_root[y_root]++;
        }
        return 1;
    }
}
int main()
{
    int parent[Len]={0};
    int rank_root[Len]={0};
    int section[5][2]={
        {0,1},{1,2},{1,3},
        {3,4},{2,5}
    };
    initalise(parent,rank_root);
    for(int i=0;i<6;i++){
        int x=section[i][0];
        int y=section[i][1];
        if(union_vertices(x,y,parent,rank_root)==0){
            cout<<"Cycle round"<<endl;
            return 0;
        }
    }
    cout<<"No cycle"<<endl;
    return 0;
}
