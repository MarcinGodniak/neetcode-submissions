class Solution {
    std::array<std::uint16_t, 256> chars = {0};
public:
    int lengthOfLongestSubstring(string s) 
    {
        std::size_t max_len =0;
        std::size_t l = 0;
        std::size_t p = 0;


        while(p < s.size())  {
            while ( p < s.size() && chars[s[p]] == 0) {
                chars[s[p]]++;
                p++;
            }
            max_len = std::max(max_len, p-l);

            if(p >= s.size()) return max_len;

            do {
                chars[s[l]]--;
                l++;
            }while (s[l-1] != s[p] );
        }
        return max_len;
    }
};
