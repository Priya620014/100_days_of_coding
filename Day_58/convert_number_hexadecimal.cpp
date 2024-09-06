class Solution {
public:
    string toHex(int num) {
         if (num == 0) return "0";
        
        string hexMap = "0123456789abcdef";
        string result = "";
        
        
        for (int i = 0; num && i < 8; ++i) {
            result = hexMap[num & 0xf] + result;  
            num >>= 4;  
        }
        
        return result;
    }
};