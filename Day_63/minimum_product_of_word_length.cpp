class Solution {
public:
    int maxProduct(vector<string>& words) {
          int n = words.size();
        vector<int> bitmask(n, 0);
        vector<int> wordLength(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            bitmask[i] = mask;
            wordLength[i] = words[i].size();
        }
        
        int maxProduct = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bitmask[i] & bitmask[j]) == 0) {
                    maxProduct = max(maxProduct, wordLength[i] * wordLength[j]);
                }
            }
        }
        
        return maxProduct;
    }
};