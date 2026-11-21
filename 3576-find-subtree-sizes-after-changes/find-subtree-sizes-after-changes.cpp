
class Solution {
public:
    vector<vector<int>> adj, newAdj;
    vector<int> newParent;
    vector<int> last;
    vector<int> ans;
    void dfs1(int node, string &s) {
        int ch = s[node] - 'a';
        int prev = last[ch];
        if (prev != -1) {
            newParent[node] = prev;
        }
        last[ch] = node;
        for (int child : adj[node]) {
            dfs1(child, s);
        }
        last[ch] = prev;
    }
    int dfs2(int node) {
        int size = 1;
        for (int child : newAdj[node]) {
            size += dfs2(child);
        }
        ans[node] = size;
        return size;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);
        newParent = parent;
        ans.resize(n, 0);
        last.assign(26, -1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dfs1(0, s);
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }
        dfs2(0);
        return ans;
    }
};
