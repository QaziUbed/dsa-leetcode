class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        unordered_map<string,int>mpp;
        int n=s.size();
        int wordlen = words[0].size();
        int totalword = words.size();
        for(int i = 0 ; i<totalword;i++)
        {
            mpp[words[i]]++;
        }
        for(int i = 0 ; i<wordlen;i++)
        {
            int left = i;
            int count = 0 ;
            unordered_map<string,int>curr;
            for(int right = i ; right + wordlen<=n ; right+=wordlen)
            {
                string word = s.substr(right,wordlen);
                if(mpp.find(word)==mpp.end())
                {
                    curr.clear();
                    count = 0 ;
                    left = right + wordlen;
                    continue;
                }
                curr[word]++;
                count++;
                while(curr[word]>mpp[word])
                {
                    string leftword = s.substr(left,wordlen);
                    curr[leftword]--;
                    count--;
                    left=left+wordlen;
                }
                if(count == totalword)
                {
                    ans.push_back(left);
                    string leftword = s.substr(left,wordlen);
                    curr[leftword]--;
                    count--;
                    left+=wordlen;
                }
            }
        }
        return ans;
    }
};