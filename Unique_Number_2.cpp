#include<bits/stdc++.h>
using namespace std;
int setBit(int n,int pos) 
{
    return (n&(1<<pos))!=0;
}
void unique2(int arr[],int n)
{
    int xorval=0;
    for(int i=0;i<n;i++) 
       xorval^=arr[i];
    int pos=0,setbit=0,temp=xorval,newxor=0;
    while(setbit!=1) 
    {
        setbit=temp&1;
        pos++;
        temp>>=1;
    }
    for(int i=0;i<n;i++) 
    {
        if(setBit(arr[i],pos-1)) 
           newxor=newxor^arr[i];
    }
    cout<<"First unique number:"<<newxor<<endl;
    cout<<"Second unique number:"<<(xorval^newxor)<<endl;
    return;
}
int main() 
{
    int arr[]={1,2,3,1,2,3,5,7};
    unique2(arr,8);
    return 0;
}