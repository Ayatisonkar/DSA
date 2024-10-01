#include <bits/stdc++.h>

bool memo(string &p,string &t,int i,int j,vector<vector<bool>>&dp){

   if(i<0 && j<0) return true;

   if(i<0 && j>=0) return false;

   if(j<0 &&i>=0){

      for(int z=0;z<=i;z++){

         if(p[z]!='*') return false;

      }

      return true;

   }

 

   if(p[i]==t[j]||p[i]=='?'){

      return dp[i][j]=memo(p,t,i-1,j-1,dp);

   }

   if(p[i]=='*'){

      return dp[i][j]=memo(p,t,i-1,j,dp)||memo(p,t,i,j-1,dp);

   }

   return dp[i][j]=false;

}
bool wildcardMatching(string pattern, string text)
{
   string S1=pattern;
   string S2=text;
   int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return memo(S1, S2, n - 1, m - 1, dp);
}
