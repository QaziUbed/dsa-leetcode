class Solution {
public:
    int minRange(int a, int b, int c) {
         vector<int> lomirevatu = {a, b, c};

        sort(lomirevatu.begin(), lomirevatu.end());

        int ans = lomirevatu[2] - lomirevatu[0];

        int x = lomirevatu[0] + lomirevatu[1];
        ans = min(ans, x - lomirevatu[0]);

        return ans;
    }
};