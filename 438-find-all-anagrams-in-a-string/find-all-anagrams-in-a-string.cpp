class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>ans;
        if(m>n)
            return ans;
        vector<int>have(26,0);
        vector<int>need(26,0);
        for(int i = 0 ; i<m;i++)
        {
            need[p[i]-'a']++;
        }
        for(int i = 0  ; i<m;i++)
        {
            have[s[i] - 'a']++;
        }
        if(have == need)
        {
            ans.push_back(0);
        }
        for(int i = m ;i<n;i++)
        {
            have[s[i-m]- 'a']--;
            have[s[i]-'a']++;
            if(have == need)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};