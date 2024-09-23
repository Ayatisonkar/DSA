//Memoisation
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long bool_evaluate(string &exp, int i, int j, bool isTrue, vector<vector<vector<long long>>> &dp) {
    if (i > j) return 0;
    
    // Base case: when there's only one symbol (either 'T' or 'F')
    if (i == j) {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    
    // Check if result is already computed
    if (dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }

    long long ways = 0;

    // Try every operator between i and j
    for (int k = i + 1; k < j; k += 2) {
        long long LT = bool_evaluate(exp, i, k - 1, true, dp) % MOD;
        long long LF = bool_evaluate(exp, i, k - 1, false, dp) % MOD;
        long long RT = bool_evaluate(exp, k + 1, j, true, dp) % MOD;
        long long RF = bool_evaluate(exp, k + 1, j, false, dp) % MOD;

        if (exp[k] == '^') {
            if (isTrue)
                ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
            else
                ways = (ways + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
        } else if (exp[k] == '&') {
            if (isTrue)
                ways = (ways + (LT * RT) % MOD) % MOD;
            else
                ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
        } else if (exp[k] == '|') {
            if (isTrue)
                ways = (ways + (LT * RT) % MOD + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
            else
                ways = (ways + (LF * RF) % MOD) % MOD;
        }
    }

    
    return dp[i][j][isTrue] = ways % MOD;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return (int)bool_evaluate(exp, 0, n - 1, true, dp);
}
/************************************************************************************************************/
//Tabulation
int evaluateExp(string &exp) {
    int n = exp.size();
  
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<=n-1;j++)
        {
             if (i > j) continue;
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character.
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }
            
            long long ways = 0;
            for (int k = i + 1; k < j; k += 2) {
                long long LT = dp[i][k-1][1] % MOD;
                long long LF = dp[i][k-1][0] % MOD;
                long long RT = dp[k+1][j][1] % MOD;
                long long RF = dp[k+1][j][0] % MOD;

                if (exp[k] == '^') {
                    if (isTrue)
                        ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
                    else
                        ways = (ways + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
                } else if (exp[k] == '&') {
                    if (isTrue)
                        ways = (ways + (LT * RT) % MOD) % MOD;
                    else
                        ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
                } else if (exp[k] == '|') {
                    if (isTrue)
                        ways = (ways + (LT * RT) % MOD + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
                    else
                        ways = (ways + (LF * RF) % MOD) % MOD;
                }
            }
            dp[i][j][isTrue] = ways;
            }
        }
    }
    return (int)dp[0][n-1][1];
}
