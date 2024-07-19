#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;

        for (char ch : s) {
            if (ch == ')') {
                string temp;
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
              
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
            
                for (char c : temp) {
                    stk.push(c);
                }
            } else {
                stk.push(ch);
            }
        }

        // Join the stack to get the final result
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
};


