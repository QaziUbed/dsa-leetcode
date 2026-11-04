
class Solution {
public:
    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;

    void balance() {
        int target = (left.size() + right.size() + 1) / 2;

        while(left.size() > target) {
            int val = *left.rbegin();
            left.erase(left.find(val));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while(left.size() < target) {
            int val = *right.begin();
            right.erase(right.find(val));
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    void add(int val) {
        if(left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        }
        else {
            right.insert(val);
            sumRight += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if(it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        }
        else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        vector<long long> cost(n - x + 1);

        // Calculate sliding window costs

        for(int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for(int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select window ending at i-1
                if(i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
