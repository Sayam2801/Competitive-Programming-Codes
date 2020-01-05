#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

bool Compare(string s1,string s2)		//Custom Comparator
{
	if(s1.find(s2))
	{
		if(s1.length()>s2.length())
			return s2>s1;
		else
			return s1<s2;
	}
	return s1>s2;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE					//file start
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif									//file end
	int n;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	sort(str,str+n,Compare);
	for(int i=0;i<n;i++)
	{
		cout<<str[i]<<endl;
	}
	return 0;
}
