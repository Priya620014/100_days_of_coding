class Solution {
public:
    bool isAdditiveNumber(string num) {
         int n = num.size();
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                
                if (isValid(i, j, num)) return true;
            }
        }
        return false;
    }
     bool isValid(int i, int j, string &num) {
        int n = num.size();
        string num1 = num.substr(0, i);
        string num2 = num.substr(i, j);
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        
        long long x1 = stoll(num1);
        long long x2 = stoll(num2);
        string sum;
        for (int start = i + j; start < n; start += sum.size()) {
            x2 = x1 + x2;
            x1 = x2 - x1;
            sum = to_string(x2);
            
            if (num.substr(start, sum.size()) != sum) return false;
        }
        return true;
    }
};