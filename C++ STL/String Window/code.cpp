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

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE					//file start
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif									//file end
	string A,B;
    getline(cin,A);
    getline(cin,B);
    unordered_map<char,int> M;
    for(int i=0;i<B.size();i++)
      M[B[i]]++;
    unordered_map<char,int> temp;
    int start=-1,ans=1000000000;
    pair<int,int> a;
    for(int i=0;i<A.size();i++)
    {
      temp[A[i]]++;
      bool flag=true;
      for(auto it=M.begin();it!=M.end();it++)
        if(it->second>temp[it->first])
       {
         flag=false;
         break;
       }
      if(flag)
      {
        while(temp[A[start+1]]>M[A[start+1]])
         {
             temp[A[start+1]]--;
           start++;
         }
         if(ans>i-start)
        {
            ans=min(ans,i-start);
            a={start+1,i};
        }
      }
    }
    if(ans==1000000000)
        cout<<"No string";
    else
    for(int i=a.first;i<=a.second;i++)
        cout<<A[i];
	return 0;
}
