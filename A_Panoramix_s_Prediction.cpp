#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n==2 || n==3)
       return true;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
           return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=n+1;i<=55;i++)
    {
        if(isPrime(i))
        {
            if(i==m)
               cout<<"YES"<<'\n';
            else
            {
                 cout<<"NO"<<'\n';
            }
            
            return 0;
        }
    }
    return 0;
}