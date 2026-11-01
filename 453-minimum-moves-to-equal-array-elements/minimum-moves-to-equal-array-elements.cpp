class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        
        int mini = *min_element(nums.begin(), nums.end());
        int diff = 0 ;
        int sum= 0 ;
        for(int i = 0 ; i< n ; i++)
        {
            diff = nums[i] - mini;
            sum+=diff;

        }

        return sum;
    }
};