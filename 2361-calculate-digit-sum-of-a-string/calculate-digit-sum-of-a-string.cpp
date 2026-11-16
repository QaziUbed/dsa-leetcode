class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k)
        {
            string groups = "";

            for(int i = 0; i < s.size(); i += k)
            {
                int sum = 0;

                for(int j = i; j < i + k && j < s.size(); j++)
                {
                    sum += s[j] - '0';
                }

                groups += to_string(sum);
            }

            s = groups;
        }

        return s;
    }
};