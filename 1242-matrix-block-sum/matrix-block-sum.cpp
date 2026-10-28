class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0 ; i<n;i++)
        {
        
            for(int j = 0 ; j<m ;j++)
            {
                int sum =0 ;
                for(int r = i-k ; r<=i+k;r++)
                {
                    for(int c = j-k ; c<=j+k;c++)
                    {
                        if(r>=0 && r<n  && c>=0 && c<m)
                        {
                            sum+=mat[r][c];
                            
                        }
                    }
                }
                ans[i][j]=sum;
            }
        }
        return ans;

    }
};