class Solution {
public:
    bool fun(int n )
    {
        if(n <=1)
            return false;
        for(int i = 2 ; i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int largestPrime(int n) {
        int sum =0 ;
        int ans=0;
        for(int i = 2 ; i<=n;i++)
        {
            if(fun(i))
            {
                sum+=i;
                if(sum>n)
                    break;
                if(fun(sum))
                    ans = sum;
            }

        }
        return ans;
    }
};