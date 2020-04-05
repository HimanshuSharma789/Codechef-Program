/*
find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Explanation:
take on char of string and compare with another string 
> if a match is found add 1 to the total compared
> else set the max matched character it the dp
thats all


Reference:
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/


*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int lena = a.length(), lenb=b.length();
    int k[lena+1][lenb+1];
    for(int i=0;i<=lena;i++)
    {
        for(int j=0;j<=lenb;j++)
        {
            if(i==0 || j==0) k[i][j]=0;
            else if(a[i-1] == b[j-1]) {
                k[i][j] = k[i-1][j-1] + 1;
            }
            else {
                k[i][j] = max(k[i-1][j], k[i][j-1]);
            }
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<k[lena][lenb]<<endl;
    return 0;
}