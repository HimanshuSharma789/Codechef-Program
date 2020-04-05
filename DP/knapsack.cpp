#include<bits/stdc++.h>
#define forall(i,z,n) for(int i=z;i<n;i++)
using namespace std;
int main()
{
    int n;
    cin>>n;
    int val[n], wt[n];
    forall(i,0,n) cin>>val[i];
    forall(i,0,n) cin>>wt[i];
    int w;
    cin>>w;

    int k[n+1][w+1];

    forall(i,0,n+1)
    {
        forall(j,0,w+1)
        {
            if(i==0 || j==0) k[i][j]=0;
            else if(j>=wt[i-1]) {
                k[i][j] = max(k[i-1][j], k[i-1][j-wt[i-1]]+val[i-1]);
            }
            else
            {
                k[i][j] = k[i-1][j];
            }
            // cout<<k[i][j]<<" ";
        }
        // cout<<endl;
    }
    //result
    cout<<k[n][w]<<endl;
    int temp = k[n][w];
    int i=n,j=w;
    while(i>0 and j>0)
    {
        if(k[i][j]!=k[i-1][j]) 
        { 
            //weights used
            cout<<wt[i-1]<<" ";
            j = j - wt[i-1];
        }
        i--;
    }
    

    return 0;
}