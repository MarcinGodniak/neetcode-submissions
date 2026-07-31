class Solution {
public:
    int countSubstrings(string s) 
    {
        int count{};

        for(int i =0; i < s.size(); i++) {
            //uneven
            int p = i;
            int l= i;
            while(l >= 0 && p <s.size()) {
                if(s[l] != s[p]) break;
                count++;
                l--;
                p++;
            }

            //even 
            p = i +1;
            l= i;
            while(l >= 0 && p <s.size()) {
                if(s[l] != s[p]) break;
                count++;
                l--;
                p++;
            }

        }

        return count;
    }
};
