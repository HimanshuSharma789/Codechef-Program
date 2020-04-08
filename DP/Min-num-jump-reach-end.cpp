/*
Given an array of integers where each element represents
the max number of steps that can be made forward from that element. 
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then we cannot move through that element.

Input :  arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output :  3 (1-> 3 -> 8 -> 9)

Explanation:
The first element will always be reached in 1 step
I considerd the array -> steps which tell how many steps are required to reach the current position
@ind, @maxx variable to get the maximum value in each interval (with help of temp, tempind)

step[0] = 1
maxx=0

Iterate over each element arr[i-1] and determine the max position we can jump from there
and store that value in step[i]

For each element with same number of step determine the maximun among them and
store its value in @maxx and its index in @ind

When we come across position where the last jump is made we update the values for max and repeat the above procedure


arr[]:     1 3 5  9  7  2  8  9
---------------------------------------
step[]:  0 1 2 3  3  3  4  4  4  ---- result
maxx:    1 2 5 5  5 13 13 13 13
temp:    0 2 5 8 13 12 12 15 17
---------------------------------------
ind:     0 1 2 2  2  4  4  4  4
tempind: 0 1 2 3  4  5  5  7  8
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
    int step[n+1];
    int temp=0, tempind=0,ind=0;
    step[0]=0;
    int maxx=1;
    int i=1;
    while(i<=n)
    {
        step[i] = step[ind] +1;
        if(temp < arr[i-1]+i) {temp = arr[i-1]+i; tempind=i;}
        if(maxx==i)
        {
            ind=tempind;
            maxx = temp;
            temp=0;
        }
        i++;
    }
    cout<<step[n]<<endl;
    return 0;
}