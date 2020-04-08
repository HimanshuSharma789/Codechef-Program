/*
Given a string representation of the first n digits of Pi 
and a list of positive integers(all in string format),
write a function that returns the smallest number of spaces
that can be added to the n digits of Pi such that all 
resulting numbers are found in the list integers.

If no number of spaces to be added exists such that all the
resulting numbers are found in the list of integers, 
the function should return -1

Sample input:

pi="3141592653589793238462643383279"

integer list=
{
"314159265358979323846",
"26433",
"8",
"3279",
"314159265",
"35897932384626433832",
"79"
}

Sample output: 2

Explanation:
First created a hash table for each list using the first character of each string
and made a pair with '0' to denote whether this string is visited or not
(to prevent the repeatition)

Created a recursion 'totalCount(@mainstring(str), @list, @indextosearch(ind), count)' in which...... {}
{
    take the char from @mainstring to start from .....initially [3]
    iterate over all the string in list starting with that character 

    if a match is found ---> set its visited value to 1
    and call totalCount(@mainstring(str), @list, @indextosearch+'lenofmatchfound', count+1)
    get the minimum value 
    reset the visited value to 0

    base condition: if (index == length of string-1 ) then return count
}



*/


#include<bits/stdc++.h>
#define forall(i,z,n) for(int i=z;i<n;i++)
using namespace std;

int totalCount(string str, list<pair<string,int>> listt[10], int ind, int count)
{
    int ll=str.length()+1;
    if(ind==ll-1) { return count-1;}
    int start = str[ind]-'0';
    
    for(auto it = listt[start].begin();it!=listt[start].end();it++)
    {   
        if((*it).second==0) 
        {
            int len= (*it).first.length();
            if(str.compare(ind,len, (*it).first)==0)
            {
                cout<<(*it).first<<" "<<ind<<" "<<count<<endl;
                (*it).second=1;
                ll = min(ll, totalCount(str, listt, ind+len, count+1));
                (*it).second=0;
                
            }
        }
    }
    return ll;
}

int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    list<pair<string,int>> listt[10];
    string s;
    forall(i,0,n) {
        cin>>s;
        listt[s[0]-'0'].push_back(make_pair(s,0));
    }
    int count=totalCount(str,listt,0,1);
    
    //to check if it reached to the end or not
    if(count==str.length()+1) cout<<-1<<endl;
        else { cout<< count-1<<endl;}

    return 0;
}