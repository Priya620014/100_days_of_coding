class Solution {
public:
    string convert(string s, int numRows) {
      
        if (numRows == 1) return s;

        
        int length = s.size();
        int minRows = numRows < length ? numRows : length;
        vector<string> rows(minRows);

        int curRow = 0;
        bool goingDown = false;

      
        for (int i=0;i<length;i++) {
            rows[curRow] += s[i];

            
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }

          
            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (int i = 0; i < minRows; i++) {
            result += rows[i];
        }

        return result;
    
    }
};