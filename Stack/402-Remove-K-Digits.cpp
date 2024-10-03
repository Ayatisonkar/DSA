#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;
        for (char digit : num) {
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // Remove remaining digits from the end if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the final number from the stack
        std::string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        std::reverse(result.begin(), result.end());
        
        // Remove leading zeros
        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        
        result = result.substr(nonZeroIndex);
        
        // If the result is empty, return \0\
        if (result.empty()) {
            return \0\;
        }
        
        return result;
    }
};
