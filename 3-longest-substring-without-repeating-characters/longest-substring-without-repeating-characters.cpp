class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low= 0 ;
        unordered_map<int,int>freq;
        int res = INT_MIN;
        for(int high = 0 ; high<s.size();high++)
        {
            freq[s[high]]++;
            int k = high - low +1;
            while(freq.size()<k)
            {
                freq[s[low]]--;
                if(freq[s[low]]==0)
                {
                    freq.erase(s[low]);
                }
                low++;
                k = high-low+1;
            }
            int len = high - low +1;
            res=max(res,len);
        }
        return ( res == INT_MIN)?0 : res;

    }
};