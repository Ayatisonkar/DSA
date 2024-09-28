//brute-app
int maximumProfit(vector<int> &Arr){
    // Write your code here.
	int maxProfit = 0;
	int mini = Arr[0];
	
	for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
	return maxProfit;
}
//Recursion
long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp) {
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n) {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n) {
    // Create a DP table to memoize results
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}
//Memoisation
long getMaximumProfit(long *Arr, int n) {
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}
//Tabulation
long getMaximumProfit(long *Arr, int n) {
    // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = ahead[1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    // The maximum profit is stored in cur[0] after all calculations
    return cur[0];
}
