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

int s;
char ch[1000000];
int a[10]={2,3,5,7,11,13,17,19,23,29};

bool isValid(bool *visited,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

bool isCBNUmber(int left,int right)
{
    int no=0;
    for(int i=left;i<=right;i++)
    {
        int x=ch[i]-'0';
        no=no*10+x;
    }
    for(int i=0;i<10;i++)
    {
        if(no==a[i])
            return true;
    }
    if(no==0||no==1)
        return false;
    else
    {
        for(int i=0;i<10;i++)
        {
            if(no%a[i]==0)
                return false;
        }
    }
    return true;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    cin>>s;
    cin>>ch;
    bool visited[s]={false};
    int cnt=0;
    for(int i=0;i<s;i++)
    {
        for(int j=i;j<s;j++)
        {
            if(isCBNUmber(i,j)&&isValid(visited,i,j))
            {    
                cnt++;
                for(int k=i;k<=j;k++)
                    visited[k]=true;
            }    
        }
    }
    cout<<cnt<<endl;
    return 0;
}

