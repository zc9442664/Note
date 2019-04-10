#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str)){
        map<string,int> m;
        string temp_str;
        for(int i=0;i<str.size();i++){
            if(str[i]!=' '||str[i]!=','||str[i]!='.'){
                temp_str+=tolower(str[i]);
            }
            else{
                if(temp_str!="")m[temp_str]++;
                temp_str="";
            }
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            cout<<it->first<<":"<<it->second<<endl;
        }
    }

    return 0;
}
//A blockhouse is (a small castle that has four openings through which to shoot.
