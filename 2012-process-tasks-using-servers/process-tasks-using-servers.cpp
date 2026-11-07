
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> free;

        // {finishTime, weight, index}
        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        vector<int> ans;

        // Initially all servers are free
        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            // Release all servers that have finished
            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finishTime, weight, idx] = busy.top();
                busy.pop();

                free.push({weight, idx});
            }

            // If no server is free, move time forward
            if(free.empty()) {
                time = get<0>(busy.top());

                // Release all servers finishing at this time
                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finishTime, weight, idx] = busy.top();
                    busy.pop();

                    free.push({weight, idx});
                }
            }

            // Select the best available server
            auto [weight, idx] = free.top();
            free.pop();

            ans.push_back(idx);

            // Assign task and calculate finishing time
            busy.push({time + tasks[j], weight, idx});
        }

        return ans;
    }
};
