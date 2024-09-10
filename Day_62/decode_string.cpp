class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        string current_string;
        int current_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(current_num);
                strStack.push(current_string);
                current_string = "";
                current_num = 0;
            } else if (c == ']') {
                string temp = current_string;
                int repeat_count = numStack.top();
                numStack.pop();
                
                string previous_string = strStack.top();
                strStack.pop();
                
                current_string = previous_string;
                for (int i = 0; i < repeat_count; ++i) {
                    current_string += temp;
                }
            } else {
                current_string += c;
            }
        }
        
        return current_string;
    }
};