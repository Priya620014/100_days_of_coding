class Solution {
public:
   const int MOD = 1337;
    
    int modPow(int a, int b) {
        int result = 1;
        a %= MOD;
        while (b > 0) {
            if (b % 2 == 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }
    
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int i = 0; i < b.size(); i++) {
            result = modPow(result, 10) * modPow(a, b[i]) % MOD;
        }
        return result;
    }
};