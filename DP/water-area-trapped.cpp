/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|

Explanation:
We will keep track of max bars both sides and in fill the water in minima section
For this we find out the maximum values for each side and 
and moving towards the center we fill the gap with the minimum of the two maximum bars

Reference:
https://www.geeksforgeeks.org/trapping-rain-water/

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ml=0, mr=0;
    int l=0, r=n-1;
    int result=0;
    while(l<=r)
    {
        if(arr[l]<arr[r])
        { 
            if(arr[l]>ml) {
                ml=arr[l];
            }
            else {
                result += ml-arr[l];
            }
            l++;
        }
        else
        {
            if(arr[r]>mr) {
                mr=arr[r];
            }
            else {
                result += mr - arr[r];
            }
            r--;
        }
        
    }
    cout<<result<<endl;
    return 0;
}