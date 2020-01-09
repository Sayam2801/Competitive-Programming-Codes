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

bool isValid(int n,int m,int x,int y,int ans)
{
    int total_coupons=m+(n-ans)*y;
    while(ans>0)
    {
        total_coupons -=x;
        ans--;
    }
    if(total_coupons<0)
        return false;
    return true;
}

int MaxStudents(int n,int m,int x,int y)
{
    int s=0,e=n;
    int ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(isValid(n,m,x,y,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<MaxStudents(n,m,x,y)<<endl;
    return 0;
}

