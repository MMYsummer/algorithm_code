#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
#define _for(n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	vector<int> a;
	a.resize(5);
	_for(5) 
		cin>>a[i];
	vector<int>::iterator it = a.begin();
	cout<<*(it+3)<<endl;
	return 0;
}
