class Solution {
public:
    bool checkString(string s) {
        int count =0;
        for(int i =1 ; i<s.size();i++)
        {
            if(s[i-1]=='b')
            {
                count++;
            }
            if(s[i]=='a'&& count>0)
            {
                return false;
            }
        }
        return true;
    }
};