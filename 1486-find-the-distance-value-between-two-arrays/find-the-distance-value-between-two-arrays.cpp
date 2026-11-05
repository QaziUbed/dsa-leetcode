class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int dist = 0 ;
        int count = 0;
        for(int i = 0 ; i<arr1.size();i++)
        {
            bool found = false ;
            for(int j = 0 ;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    found = true;
                    break;
                }
            }
            if(found == false)
                count ++;
        }
        return count ;
    }
};