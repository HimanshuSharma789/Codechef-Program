/*
The Maximum Sum Increasing Subsequence problem is to find the maximum sum subsequence of a given sequence
such that all elements of the subsequence are sorted in increasing order.

or 

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array 
such that the integers in the subsequence are sorted in increasing order. 
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and 
if the input array is {10, 5, 4, 3}, then output should be 10

Explanation:
To calculate the max_sum(0...n) we need to calculate max_sum(0...n-1)
And add it to 'n' if arr[n-1] <= arr[n] 

Each max_sum() is calculated as max( max_sum[n],  arr[n]+max_sum[n-1]  )

1   101   2   3   100    4   5  ----> given
-------------------------------
0     0   0   0     0    0   0  ----> initial max_sum (dp)
-------------------------------
1   102   3   4   101    5   6
    102   3   4   101    5   6
          3   6   103    8   9
              6   106   10  11
                  106   10  11
                        10  15
-------------------------------
1   102   3   6   106   10  15 ----> finally

*/

#include<bits/stdc++.h>
#define forall(i,z,n) for(int i=z;i<n;i++)
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    forall(i,0,n)
    {
        cin>>arr[i];
    }
    int dp[n]={0};
    int maxx=0, ind;
    forall(i,0,n)
    {
        dp[i] = max(dp[i], arr[i]);
        forall(j,i+1,n)
        {
            if(arr[j]>=arr[i])
            {
                dp[j] = max(dp[j], dp[i]+arr[j]);
            }
        }
        if(dp[i]>=maxx) {maxx=dp[i]; ind=i;}
        // maxx = max(maxx, dp[i]);
    }
    cout<<maxx<<endl;
    //generated the max result

    //code for the numbers - involved to generate largest sum
    vector<int> v;
    for(int i=ind;i>=0;i--)
    {
        if(dp[i]==maxx)
        {
            v.push_back(arr[i]);
            maxx-=arr[i];
        }
    }
    for(auto it=v.rbegin();it!=v.rend();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}