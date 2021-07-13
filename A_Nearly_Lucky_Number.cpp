#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isLucky(ll n)
{
    if(!n)
      return false;
    while(n)
    {
        int digit=n%10;
        if(digit!=4 && digit!=7)
           return false;
        n/=10;
    }
    return true;
}
int main()
{
    long long int n;
    cin>>n;
    ll temp=n,cnt=0;
    while(temp)
    {
        int digit=temp%10;
        if(digit==4 || digit==7)
           cnt++;
        temp/=10;
    }
    if(isLucky(cnt))
       cout<<"YES"<<'\n';
    else
        cout<<"NO"<<'\n';
    return 0;
}