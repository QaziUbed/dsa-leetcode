
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        // Step 1: Sort logs according to time
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // Step 2: Store query with its original index
        vector<pair<int,int>> arr;

        for(int i = 0; i < q; i++)
        {
            arr.push_back({queries[i], i});
        }

        sort(arr.begin(), arr.end());

        // Step 3: Frequency array
        vector<int> freq(n+1, 0);
        vector<int> ans(q);

        int left = 0;
        int right = 0;

        int inactive = n;

        // Step 4: Process sorted queries
        for(int i = 0; i < q; i++)
        {
            int start = arr[i].first - x;
            int end = arr[i].first;

            // Add logs inside the current window
            while(right < m && logs[right][1] <= end)
            {
                int id = logs[right][0];

                if(freq[id] == 0)
                    inactive--;

                freq[id]++;
                right++;
            }

            // Remove logs outside the current window
            while(left < right && logs[left][1] < start)
            {
                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0)
                    inactive++;

                left++;
            }

            // Store answer in original query position
            ans[arr[i].second] = inactive;
        }

        return ans;
    }
};
