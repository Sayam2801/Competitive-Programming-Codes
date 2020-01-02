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

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    vector<int> sum;
    int i=n-1,j=m-1;
    int rem=0;
    int net=0;
    while(i>=0||j>=0)
    {
        if(i>=0&&j>=0)
            net=a[i]+b[j]+rem;
        else if(i<0)
            net=b[j]+rem;
        else
            net=a[i]+rem;
        if(net>9)
        {
            if(i==0&&j<0)
            {
                sum.pb(net);
            }
            else if(i==0&&j==0)
            {
                sum.pb(net);
            }
            else if(j==0&&i<0)
            {
                sum.pb(net);
            }
            else
            {
                sum.pb(net%10);
                rem=1;
            }
        }
        else
        { 
            sum.pb(net);
            rem=0;
        }  
        i--;
        j--;  
    }
    int cnt=1;
    int k=sum[sum.size()-cnt];
    while(k==0)
    {
        cnt++;
        k=sum[sum.size()-cnt];
    }
    for(int i=sum.size()-cnt;i>=0;i--)
    {
        cout<<sum[i]<<", ";
    }
    cout<<"END"<<endl;
    return 0;
}

