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

vector<char>s1;

void ReplaceAllPi(string s,int index)
{
    if(index==s.length())
        return;
    if(s[index]=='p'&&s[index+1]=='i'){
        s1.pb(3+'0');
        s1.pb('.');
        s1.pb(1+'0');
        s1.pb(4+'0');
        ReplaceAllPi(s,index+2);
    }
    else{
        s1.pb(s[index]);
        ReplaceAllPi(s,index+1);
    }
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ReplaceAllPi(s,0);
        for(int i=0;i<s1.size();i++)
            cout<<s1[i];
        cout<<endl;
        s1.clear();
    }
    return 0;
}

