class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>free;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy;
        vector<int> count(k, 0);
        for(int i = 0 ;i<k;i++)
        {
            free.insert(i);
        }
        for(int i = 0 ; i<arrival.size();i++)
        {
            int server = i%k;
            int finishTime = arrival[i]+load[i];
            while(!busy.empty() && busy.top().first <= arrival[i])
            {
                int newid = busy.top().second;
                busy.pop();
                free.insert(newid);
            }
            if(free.empty())
            {
                continue;
            }
            auto it = free.lower_bound(server);
            if(it == free.end())
            {
                it = free.begin();
            }
            int serverId=*it;
            free.erase(it);
            busy.push({finishTime, serverId});
            count[serverId]++;

        }
        int maxi = 0 ;
        for(int i = 0 ; i<k;i++)
        {
            maxi = max(maxi,count[i]);
        }
        vector<int>ans;
        for(int i =0;i<k;i++)
        {
            if(count[i]==maxi)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};