class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
           {
            open++;
           }
           if(s[i]==')'){
            close++;
           }
           if(open<close)
           {
            open=0;
            close=0;
           }
           else if(close==open){
                ans=max(ans,2*open);
           }
        }
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                open++;
            }
            if(s[i]=='(')
            {
                close++;
            }
            if(open<close)
           {
            open=0;
            close=0;
           }
           else if(close==open){
                ans=max(ans,2*open);
           }
        }
        return ans;
    }


};