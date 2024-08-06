class Solution {
public:
    int solve(int n,int dp[])
    {
        if(n<=1)
        return 1;
         if(dp[n]!=-1)
         {
            return dp[n];
         }
         
        dp[n]= solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int solve_tabular(int n)
    {
        int dp[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<n+1;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solve_tabular(n);
    }
};