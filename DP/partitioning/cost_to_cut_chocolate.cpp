//Recursion
#include <bits/stdc++.h> 
int cut_cost(int i,int j,vector<int> &cuts)
{
    int mini=INT_MAX;
    if(i>j) return 0;
    for(int k=i;k<=j;k++)
    {
        int cut=cuts[j+1]-cuts[i-1]+cut_cost(i,k-1,cuts)+cut_cost(k+1,j,cuts);
        mini=min(mini,cut);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts){
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    int i=1;
    int j=c;
    return cut_cost(i,j,cuts);
}
/*****************************************************************************************************************/
//Memoisation
#include <bits/stdc++.h> 
int cut_cost(int i,int j,vector<int> &cuts,vector<vector<int>>& dp)
{
    int mini=INT_MAX;
    if(i>j) return dp[i][j]=0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    for(int k=i;k<=j;k++)
    {
        int cut=cuts[j+1]-cuts[i-1]+cut_cost(i,k-1,cuts,dp)+cut_cost(k+1,j,cuts,dp);
        mini=min(mini,cut);
    }
    return dp[i][j]=mini;
}
int cost(int n, int c, vector<int> &cuts){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    int i=1;
    int j=c;
    return cut_cost(i,j,cuts,dp);
}
/**********************************************************************************************************/
//Tabulation
#include <bits/stdc++.h> 

int cost(int n, int c, vector<int> &cuts){
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    for(int i=c;i>=1;i--)
    {
        for(int j=i;j<=c;j++)
        {
            int mini=INT_MAX;
            for(int k=i;k<=j;k++)
            {
                int cut=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,cut);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c];
}
