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

void triplet_target(vector<int>a,int target)		//Better Than Brute Force
{
	int i=0;
	while(i<a.size())
	{
		int r=a.size()-1;
		int l=i+1;
		while(l<r)
		{
			if(a[l]+a[i]+a[r]==target){
				cout<<a[i]<<", "<<a[l]<<" and "<<a[r]<<endl;
				l++;
			}
			else if(a[l]+a[i]+a[r]>target)
				r--;
			else
				l++;
		}
		i++;
	}
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
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.pb(x);
	}
	int target;
	cin>>target;
	sort(a.begin(),a.end());
	triplet_target(a,target);
	return 0;
}
