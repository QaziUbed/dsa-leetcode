class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum =0;
        int move = 0;
        for(int i = 0 ; i<nums.size();i++)
        {
           
            sum +=maxi-nums[i];
        }
        return sum;
    }
};