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

char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
};

void Keypad(char in[],char out[],int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        for(int k=0;k<12;k++)
        {
            if(searchIn[k].find(out)<=1000){
                cout<<searchIn[k]<<endl;
            }
        }
        return;
    }
    int digit=in[i]-'0';
    for(int k=0;table[digit][k]!='\0';k++)
    {
        out[j]=table[digit][k];
        Keypad(in,out,i+1,j+1);
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
    char out[10000];
    Keypad(in,out,0,0);
    return 0;
}

