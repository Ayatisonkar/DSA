//Recursion
class Solution {
public:
    int partitioning(int ind, int n, vector<int>& num, int k){
      if (ind == n) return 0;
      int len = 0;
      int maxi = INT_MIN;
      int maxAns = INT_MIN;
  
      // Loop through the array starting from the current index.
      for (int j = ind; j < min(ind + k, n); j++) {
          len++;
          maxi = max(maxi, num[j]);
          int sum = len * maxi + partitioning(j + 1,n, num, k);
          maxAns = max(maxAns, sum);
      }
      return maxAns;
    }
   int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n = arr.size();
      return partitioning(0,n,arr,k);
  }
};
/***********************************************************************************************************************/
//Memoisation
class Solution {
public:
    int partitioning(int ind, int n, vector<int>& num, int k, vector<int>& dp){
        if (ind == n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + partitioning(j + 1,n, num, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
   int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return partitioning(0, n, arr, k, dp);  
  }
};
/*********************************************************************************************************************/
//Tabulation
class Solution {
public:
   int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1, 0);
    
    for(int i=n-1;i>=0;i--){
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j = i; j < min( n, i + k); j++){
            len++;
             maxi = max(maxi, arr[j]);
            int sum = len * maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[i]=maxAns;
    }
    return dp[0]; 
  }
};
