#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
       cin>>v[i];
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<v.size();i++)
       pq.push(v[i]);
    int ans=0;
    while(!pq.empty())
    {
        int best=pq.top();
        pq.pop();
        ans+=best;
        k--;
        if(!k)  break;
    }
    cout<<ans<<endl;
    return 0;
}