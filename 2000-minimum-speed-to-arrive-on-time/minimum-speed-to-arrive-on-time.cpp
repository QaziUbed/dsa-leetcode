class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //sort(dist.begin(),dist.end());
        int left = 1 ;
        int right = 1e7;
        int ans= INT_MAX;
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            double totalTime =0;
            
            for(int i = 0 ; i<dist.size();i++)
            {
                if(i ==dist.size()-1)
                {
                    totalTime+=(double)dist[i]/mid;
                }
                else{
                    totalTime+=ceil((double)dist[i]/mid);
                }
                
            }
            if(totalTime<=hour)
            {
                ans=mid;
                right=mid-1;

            }
            else{
                left=mid+1;
            }
        }
        if(ans ==INT_MAX)
            return -1;
        return ans;
    }
};