//Recursion
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int minPartitions(int i, int n, string &str) {
    if (i == n) return 0;

    int minCost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int palindromePartitioning(string str)
{
     int n = str.size();
    return minPartitions(0, n, str) - 1;
}
/******************************************************************************************************************/
//Memoisation
