#include <bits/stdc++.h> 
int solveRec(vector<int> &num,int x,vector<int> &dp)
{
    if(x==0)
    return 0;
    if(x<0)
    return INT_MAX;
    int mini=INT_MAX;
    if(dp[x]!=-1)
    return dp[x];
    for(int i=0;i<num.size();i++)
    {
      int ans=solveRec(num,x-num[i],dp);
        if(ans!=INT_MAX)
        mini=min(mini,ans+1);
    }
    dp[x]=mini;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans=solveRec(num,x,dp);
    if(ans==INT_MAX)
    return -1;
    return ans;
}
