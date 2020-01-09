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
#define MOD 1000000007  //10^9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

bool MyCompare(pair<string,int> p1, pair<string,int> p2)
{
    if(p1.S==p2.S)
    {
        if(p1.F<p2.F)
            return p1.F<p2.F;
    }
    return p1.S>p2.S;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int x;
    cin>>x;
    int n;
    cin>>n;
    pair<string,int> emp[n];
    string name;
    int salary;
    for(int i=0;i<n;i++)
    {
        cin>>name;
        cin>>salary;
        emp[i].F=name;
        emp[i].S=salary;
    }
    sort(emp,emp+n,MyCompare);
    for(int i=0;i<n;i++)
    {
        if(emp[i].S>=x)
            cout<<emp[i].F<<" "<<emp[i].S<<endl;
    }
    return 0;
}

