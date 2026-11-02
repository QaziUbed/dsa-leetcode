class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int,char>&a,pair<int,char>&b)
        {
            return a.first<b.first;
        }
    };
    string frequencySort(string s) {
        unordered_map<char ,int>mpp;
        for(int i = 0 ; i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        string ans ="";
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        for(auto i:mpp)
        {
            char ele = i.first;
            int freq = i.second;
             pq.push({freq, ele});
        }
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            char ch = it.second;

            for(int i = 0; i < freq; i++)
            {
                ans += ch;
            }
        }
        return ans;

    }
};