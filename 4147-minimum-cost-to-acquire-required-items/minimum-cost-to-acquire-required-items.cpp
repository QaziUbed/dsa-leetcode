
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = LLONG_MAX;

        long long option1 = (1LL * cost1 * need1) + (1LL * cost2 * need2);
        ans = min(option1, ans);

        int diff = abs(need1 - need2);
        long long total = 1LL * costBoth * min(need1, need2);

        int maxi = 0;
        if (need1 > need2) {
            maxi = cost1;
        }
        else {
            maxi = cost2;
        }

        long long option2 = total + 1LL * diff * maxi;
        ans = min(option2, ans);

        long long option3 = 1LL * max(need1, need2) * costBoth;
        ans = min(option3, ans);

        return ans;
    }
};
