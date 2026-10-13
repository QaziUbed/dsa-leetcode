class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long > temp;
        for(int i = 0 ; i<nums.size();i++)
        {
            temp.push_back(1LL *nums[i]*nums[i]);
        }   
        sort(temp.begin(),temp.end());
        long long ans = 0 ;
        int n =temp.size();
        for(int i = 0 ; i<n;i++)
        {
            if(i%2==0)
            {
                ans+=temp[n-1 - i/2];
            }
            else{
                ans-=temp[i/2];
            }
        }
        return ans;
    }
};