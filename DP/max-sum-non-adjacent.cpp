/*
Given an array of positive numbers, 
find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array.

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Explanation:

1.> bottom-top approach
-----------------------------------
take two elements prev and pprev (prev-prev)  =  arr[0] and 0
For each element 1 to n in array
    > prev = pprev + arr[i]
    > pprev = max(prev, pprev)

eg: 100, 5, 10, 100, 10, 5
> initially : prev=100 , pprev = 0
> i=1: prev = 5, pprev = max(100,0) = 100
> i=2: prev = 100+10 = 110, pprev = max(100,5)=100
> i=3: prev = 100+110 = 210, pprev = max(110,100)=110
and so on
result = max(prev, pprev)


2.> top-bottom approach
-------------------------------------
here we consider a array of length n
result till n is based on its n-1 and n-2 elements

so as
fn dp(arr, i)
{
    // non dp solution (recursive)
    // if(i==0) return arr[0]
    // if(i==1) return max(arr[0],arr[1])
    // return max ( dp(arr,i-1), arr[i]+dp(arr,i-2) )

    // dp solution
    if(i==0) return 0;
    if(visited[i]) return p[i];
    visited[i]=1;

    p[i] = max( ( dp(arr,i-1), arr[i]+dp(arr,i-2) )
    return p[i];
}

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pprev = 0, prev = arr[0];
    int temp;
    for(int i=1;i<n;i++)
    {
        temp = prev;
        prev = pprev + arr[i];
        pprev = max(temp, pprev);
    }
    cout<<max(prev, pprev)<<endl;
    return 0;
}