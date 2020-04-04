/*
Given a value V, if we want to make change for V cents, 
and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, 
what is the minimum number of coins to make the change? 

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents

Explanation :
create an array val[v+1] and val[0]=0 (as 0 coin req to reach 0) and other as MAX-or-(v+1) 
we first consider a single coin and determine the number of coins required to reach each v'i
then take another change and check for the same
and so on....

for each coin if coin is less than total (v'i)
then ...> val[j - coin[i]] + 1
    ((determine for single coin how many other coins are required))
then val[j] = MIN(above value , val[j])

result = val[v]


Resource:
https://www.youtube.com/watch?v=jgiZlGzXMBw


*/


#include<bits/stdc++.h>
#define forall(i,z,n) for(int i=z;i<n;i++)
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    forall(i,0,n) cin>>arr[i];
    int v;
    cin>>v;
    int val[v+1]={0};
    forall(i,1,v+1)
    {
        if(val[i]==0) val[i]=v+1;
        forall(j,0,n)
        {
            if(arr[j]<=i)
            {
                val[i] = min(val[i - arr[j]] + 1, val[i]);
            }
        }
    }
    cout<<val[v]<<endl;
    return 0;
}