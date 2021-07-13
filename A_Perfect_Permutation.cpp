#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<-1<<endl;
        return 0;
    }
    int temp=2;
    for(int i=0;i<n/2;i++)
    {
        cout<<temp<<" "<<temp-1<<" ";
        temp+=2;
    }
    return 0;
}