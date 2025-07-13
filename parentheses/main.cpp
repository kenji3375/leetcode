#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
    // int maxLength = 0;
    // const int len = s.size();
    // stack<int> p;
    // p.push(-1);
    // for (int i=0; i<len; ++i) {     //this includes last null character of string
    //     if (s[i] == '(') {
    //         p.push(i);
    //     } else {
    //         p.pop();
    //         if (p.empty()) {
    //             p.push(i);
    //         } else {
    //             maxLength = max(maxLength, i-p.top());
    //         }
    //     }
    // }
    // return maxLength;
    
    int maxLength = 0;
    const int len = s.size();
    
    int * dp = new int[len];

    for (int i=0; i<len; ++i) {
        dp[i] = 0;
    }
    for (int i=1; i<len; ++i) {
        if(s[i] == ')') {
            if (s[i-1] == '(') {
                dp[i] = ( i>1 ? dp[i-2] : 0 ) +2;
                // cout<<"meowmeow\n";
            } else if (i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '(' ) {
                dp[i] = dp[i-1]+2;
                // dp[i] += ;
                if(i - dp[i-1] >= 2) {
                    dp[i] += dp[i-dp[i-1]-2];
                }
            } 
            maxLength = max(maxLength, dp[i]);
            // else {
            //     dp[i] = dp[i-1];
            // }
        }
        // cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
    }

    return maxLength;
}

int longestValidParenthesess(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int maxLength = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }

int main(void) {
    string test = "()())))";            // 4
    cout<<test<<endl;
    cout<<longestValidParentheses(test)<<endl;
    test = "((())(())()())()))((())))))))))"; // 16
    cout<<test<<endl;
    cout<<longestValidParentheses(test)<<endl;
    // test = "()"; // 2
    // test = "()()()()"; // 8
    // test = "()()()"; // 6
    test = "((()()"; // 4
    cout<<test<<endl;
    cout<<longestValidParentheses(test)<<endl;
    test = "()(()"; // 2
    cout<<test<<endl;
    cout<<longestValidParentheses(test)<<endl;
    test = "(())("; // 4
    cout<<test<<endl;
    cout<<longestValidParentheses(test)<<endl;
    
}