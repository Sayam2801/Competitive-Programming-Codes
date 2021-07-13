#include<bits/stdc++.h>
using namespace std;
bool isSafe(int a[6][6],int x,int y)
{
    if(x>=0 and x<6 and y>=0 and y<6 and a[x][y]==0)
       return true;
    return false;
}
bool canReachMaze(int a[6][6],int i,int j)
{
    if(i==5 and j==5)
        return true;
    if(isSafe(a,i,j))
    {
        if(canReachMaze(a,i+1,j))
           return true;
        if(canReachMaze(a,i,j+1))
           return true;
        a[i][j]=1;
        return false;
    }
    return false;
}
int main()
{
    int arr[6][6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
           cin>>arr[i][j];
    }
    if(canReachMaze(arr,0,0))
       cout<<"Yes"<<endl;
    else 
       cout<<"No"<<endl;
    return 0;
}