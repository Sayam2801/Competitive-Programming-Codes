#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,n;
        cin>>x>>n;
        int arr[n],ans=0;
        for(int i=0;i<n;i++){
           cin>>arr[i];
           if(arr[i]<x)
              ans++;
        }
        for(int i=0;i<n-1;i++)
        {
            int prod=arr[i];
            for(int j=i+1;j<n;j++){
              prod*=arr[j];
              if(prod<x)
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}