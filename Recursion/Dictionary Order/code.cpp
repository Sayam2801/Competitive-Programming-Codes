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

vector<string>s;

void permute(char *in,int i,string out)
{
    if(in[i]=='\0'){
        if(out.compare(in)>0){
            s.pb(in);
        }
        return;
    }
    for(int k=i;in[k]!='\0';k++)
    {
        swap(in[i],in[k]);
        permute(in,i+1,out);
        swap(in[k],in[i]);
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
    char in[10000];
    cin>>in;
    string out;
    out.append(in);
    permute(in,0,out);
    sort(s.begin(),s.end());
    for(auto x: s)
        cout<<x<<endl;
    return 0;
}

