#include<bits/stdc++.h>
using namespace std;

void printSubstr(string str,int low,int high)
{
     for(int i=low;i<=high;i++)
        cout<<str[i];
}
int longestSubStr(string str)
{

    int n=str.size();
    bool table[n][n];
    memset(table,false,sizeof(table));
    // substring of length 1 string are itself are palindrome.
    int maxlength=1;
    for(int i=0;i<n;i++)
        table[i][i]=true;
    // substring of length  2
    int start=0;
    for(int i=0;i<n-1;i++)
    if(str[i]==str[i+1])
    {
        table[i][i+1]=true;
        start=i;
        maxlength=2;
    }
    // for lewngth greater than 3

    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {

            int k=j+i-1;
            if(table[i+1][j-1]&& str[i]==str[j])
                {
                    table[i][j]=true;
                     if(i>maxlength)
                   {
                       start=i;
                       maxlength=k;
                   }
                }
        }

    }

    cout << "Longest palindrome substring is: ";
    printSubstr(str,start,start+maxlength-1);
    return maxlength;
}
int main()
{

    string str="ipudehiihe";
    cout<<"The length is:"<<longestSubStr(str);
    return 0;
}
