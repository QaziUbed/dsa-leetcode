class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long mod1 = 1000000007;
        const long long mod2 = 1000000009;
        const long long base = 37;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = (p1[i] * base) % mod1;
            p2[i + 1] = (p2[i] * base) % mod2;
        }

        auto check = [&](int L) {
            map<pair<long long, long long>, int> cnt;

            for (int i = 0; i + L <= n; i++) {
                long long x = (h1[i + L] -
                    h1[i] * p1[L] % mod1 + mod1) % mod1;

                long long y = (h2[i + L] -
                    h2[i] * p2[L] % mod2 + mod2) % mod2;

                cnt[{x, y}]++;
            }

            for (auto &kv : cnt) {
                if (kv.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};