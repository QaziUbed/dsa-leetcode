class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long c = 1;

        for(int j = 0; j <= rowIndex; j++)
        {
            res.push_back(c);
            c = c * (rowIndex - j) / (j + 1);
        }

        return res;
    }
};