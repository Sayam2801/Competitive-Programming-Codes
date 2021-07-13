#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll ans[100005];
void precompute() {
   ans[0]=0;
   ans[1]=1;
   for(ll i=2;i<100005;i++) 
       ans[i]=(ans[i-1]+ans[i-2])%mod;
   return;
}
int main()
{
    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}