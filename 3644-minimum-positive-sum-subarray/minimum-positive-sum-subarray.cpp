class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;  
        for(int k = l ; k<=r ; k++)
        {
            int sum = 0 ;
            for(int i = 0 ;i<k;i++)
            {
                sum+=nums[i];
            }
            if(sum>0)
                ans=min(sum,ans);
            for(int i = k ;i<n;i++)
            {
                sum = sum- nums[i-k]+nums[i];
                if(sum>0)
                    ans=min(sum,ans);

            }
            
        } 
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};