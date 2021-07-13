#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int max_ele=INT_MIN,min_ele=INT_MAX,pos1=0,pos2=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max_ele<arr[i])
        {
            max_ele=arr[i];
            pos1=i;
        }
        if(min_ele>=arr[i])
        {
            min_ele=arr[i];
            pos2=i;
        }
    }
    if(pos1>pos2)
       cout<<(pos1+n-pos2-2)<<endl;
    else
    {
        cout<<(pos1+n-pos2-1)<<endl;
    }
    
    return 0;
}