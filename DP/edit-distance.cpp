/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
1. Insert
2. Remove
3. Replace

input:
str1 = "geek", str2 = "gesek"
Output:  1

Explanation:
The given problem can be solved by breaking down into smaller subproblem where
the string is divided and follow bottom-up approach to solve the problem.

> if at any point 2 char are same then the value is copied from its previous element
{denoting number of operation performed} thus no extra operation performed

> if the two character are not equal then minimum of previous combination is to be taken + 1
    
    eg: cat, dog (3,3)
    {
        minimum of ( [ca,dog], [cat,do], [ca,do] ) + 1 
    }
    to give minimum operation. 


............
it compares like
#-> #, #-> d, #->do, #->dog
#-> #, c-> d, c->do, c->dog
#-> #, ca-> d, ca->do, ca->dog
#-> #, cat-> d, cat->do, cat->dog
............

similar to lcs *

Reference:
<<<watch video>>>
https://www.geeksforgeeks.org/edit-distance-dp-5/

*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.length(), m=str2.length();
    int dp[n+1][m+1]={0};
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0) {dp[i][j]=j;}
            else if(j==0) {dp[i][j]=i;}

            else if(str1[i-1]==str2[j-1]) {dp[i][j]=dp[i-1][j-1];}
            else {
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[n][m]<<endl;
    return 0;
}