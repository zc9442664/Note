// Project1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
	string str;
	while (getline(cin, str)) {
		map<string, int> m;
		string temp_str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ' || str[i] != ',' || str[i] != '.') {
				temp_str += tolower(str[i]);
			}
			else {
				if (temp_str != "")m[temp_str]++;
				temp_str = "";
			}
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			cout << it->first << ":" << it->second << endl;
		}
	}

	return 0;
}


 //运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
 //调试程序: F5 或调试 >“开始调试”菜单

