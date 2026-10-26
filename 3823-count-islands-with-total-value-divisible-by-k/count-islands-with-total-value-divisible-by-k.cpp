class Solution {
public:
    int x[4]= {-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid ( int i , int j , int n , int m)
    {
        if(i<0 || i >= n || j <0 || j >= m)
            return false;
        return true;
    }
    long long dfs(vector<vector<int>>&a, int n , int m , int i , int j , vector<vector<bool>>&vis)
    {
        vis[i][j]=1;
        long long sum = a[i][j];
        for(int c = 0 ; c<4 ; c++)
        {
            int row = i + x[c];
            int col = j+ y[c];
           
            if(valid(row,col,n,m) && a[row][col]!=0  && vis[row][col]==0)
            {
                
                sum+=dfs(a,n,m,row,col,vis);
                
            }
        }
        return sum;
        
    }

    int countIslands(vector<vector<int>>& grid, int k) {
            int n = grid.size();
            int m = grid[0].size();
            int count = 0 ; 
            vector<vector<bool>>vis(n);
            for(int i = 0 ; i<n;i++)
            {
                vector<bool>t(m,0);
                vis[i]=t;
            }
            for(int i = 0 ; i<n ;i++)
            {
                for(int j = 0  ; j<m;j++)
                {
                    if(grid[i][j]!=0 && vis[i][j]==0)
                    {
                        long long sum = dfs(grid, n ,m ,i,j, vis);
                        if(sum % k ==0)
                        {
                            count++;
                        }
                    }
                    
                }
            }
        return count ;
    }
};