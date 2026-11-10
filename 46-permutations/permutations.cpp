class Solution {
public:
    void fun(vector<int>nums,vector<int>&temp,vector<vector<int>>&ans,vector<bool>&vis)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i = 0 ; i<nums.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                temp.push_back(nums[i]);
                fun(nums,temp,ans,vis);
                temp.pop_back();
                vis[i]=false;

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>vis(nums.size(),0);
        vector<int>temp;
        vector<vector<int>>ans;
        fun(nums,temp,ans,vis);
        return ans;
        
    }
};