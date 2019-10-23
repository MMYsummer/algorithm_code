#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> s;
	string ch;
	s.resize(1000);
	while(getline(cin,ch))
	{
		stringstream ss(ch);
		int n=0;
		while(ss>>s[n++]);
		n-=1;
		while(n--)
			cout<<s[n]<<' ';
		printf("\n");	
	}	
	return 0;
}
