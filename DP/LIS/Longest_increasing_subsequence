//Memoisation
#include <vector>
int longest_subsequence(int arr[], int n, int ind, int prev_ind, vector<vector<int>>& dp){
    if(ind==n) return 0;
    int len;
    if(dp[ind][prev_ind+1]!=-1)
    return dp[ind][prev_ind+1];
    len=0+longest_subsequence(arr, n, ind+1, prev_ind, dp);

    if(prev_ind == -1 || arr[ind]>arr[prev_ind])
        len=max(len,1+longest_subsequence(arr, n, ind+1, ind, dp));
    return dp[ind][prev_ind+1]=len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    int i=0; 
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
  return longest_subsequence(arr,n,i,-1,dp);  
    
}
/***********************************************************************************************************/
//Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    int i=0; 
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        int len;
    
       for( int prev_ind=i-1;prev_ind>=-1;prev_ind--) 
        {
         len=0+dp[i+1][prev_ind+1];

        if(prev_ind == -1 || arr[i]>arr[prev_ind])
            len=max(len,1+dp[i+1][i+1]);
        dp[i][prev_ind+1]=len;
        }
        
    }
    return dp[0][0];
}
