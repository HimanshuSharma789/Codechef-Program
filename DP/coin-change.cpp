/*
Given a number of coins n  where coin change are {a1,a2,a3.....an}'
we have to calculate number of permutation of coin require to make total of 'm'
input :
3 4
1 2 3
output :
4 (as  {1,1,1,1},{1,1,2},{2,2},{1,3})

Explanation:
Each result of 'm' depends on previous value 'm-1'
thus we create an array arr[0...m]-->j

Here we iterate through each coin change {a1,a2,a3...an}
> if the value of 'j'(m) is less than ai move {skip}
> else arr[j] = arr[j] + arr[j-ai]

resource :
https://www.geeksforgeeks.org/understanding-the-coin-change-problem-with-dynamic-programming/

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int coin[n];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    //input completed

    //create an array to store the number of ways total can be created
    int arr[m+1]={0};
    arr[0]=1; // as 0 coins can be made by 0 number of coins thus result is 1
    
    for(int i=0;i<n;i++)
    {
        for(int j=coin[i];j<m+1;j++)
        {
            // >>  ways  = ways + (m - (change $))
            arr[j] += arr[j-coin[i]];
        }
    }
    cout<<arr[m]<<endl;

    return 0;
}