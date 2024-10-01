// basic recursion & memoization

#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>> &matrix, int n, int m,vector<vector<int>>&dp){

    if(j <0 || j>=m){

        return -1e9;

    }

    if(i == 0){

        return matrix[i][j];

    }

    if(dp[i][j] != -1){

        return dp[i][j];

    }

    int d=matrix[i][j]+solve(i-1,j,matrix,n,m,dp);

    int ld=matrix[i][j]+solve(i-1,j-1,matrix,n,m,dp);

    int rd=matrix[i][j]+solve(i-1,j+1,matrix,n,m,dp);

 

    return dp[i][j]= max(d,max(ld,rd));

}

int getMaxPathSum(vector<vector<int>> &matrix){

    //  Write your code here.

    int n=matrix.size();

    int m=matrix[0].size();

     vector<vector<int>>dp(n,vector<int>(m,-1));

     int ans=-1e9;

    for(int i=0;i<m;i++){

        ans=max(ans,solve(n-1,i,matrix,n,m,dp));

    }

    return ans;

} 
