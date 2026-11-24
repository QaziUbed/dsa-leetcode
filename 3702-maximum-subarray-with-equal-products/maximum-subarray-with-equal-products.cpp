class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                if (prod > LLONG_MAX / nums[j])
                    break;

                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = (l / gcd(l, nums[j])) * nums[j];

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};