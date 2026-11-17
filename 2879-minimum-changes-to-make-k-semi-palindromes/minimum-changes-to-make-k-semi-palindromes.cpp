
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                int j = i + len - 1;
                for (int d = 1; d * d <= len; d++) {
                    if (len % d != 0) continue;
                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        int l = i + r;
                        int right = i + r + ((len - 1 - r) / d) * d;
                        while (l < right) {
                            if (s[l] != s[right]) {
                                changes++;
                            }

                            l += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                    int other = len / d;
                    if (other != d && other < len) {
                        changes = 0;
                        for (int r = 0; r < other; r++) {
                            int l = i + r;
                            int right = i + r + ((len - 1 - r) / other) * other;

                            while (l < right) {
                                if (s[l] != s[right]) {
                                    changes++;
                                }

                                l += other;
                                right -= other;
                            }
                        }
                        cost[i][j] = min(cost[i][j], changes);
                    }
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int parts = 1; parts <= k; parts++) {

            for (int i = 1; i <= n; i++) {

                for (int j = 0; j < i; j++) {

                    if (cost[j][i - 1] == 1e9) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
