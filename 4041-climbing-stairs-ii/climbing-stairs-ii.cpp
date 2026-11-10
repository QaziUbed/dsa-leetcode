class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int i = 0 ;
        while(i<n)
        {
            for(int j = 1 ; j<=3;j++)
            {
                int nextstep = i+j;
                if(nextstep>n)
                    break;
                int step = costs[nextstep-1]+(nextstep-i)*(nextstep-i);
                dp[nextstep]=min(dp[nextstep],dp[i]+step);
            }
            i++;
        }
        return dp[n];
    }
};