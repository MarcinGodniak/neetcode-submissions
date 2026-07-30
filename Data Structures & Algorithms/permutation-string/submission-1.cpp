class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size()> s2.size()) return false;

        std::unordered_map<char, uint16_t> s1_counts;

        int non_zeros = 0;
        for(auto&c: s1)
        {
            if(!s1_counts.contains(c)) non_zeros++;
            s1_counts[c]++;
        }


        for(int i = 0; i< s1.size(); i++) {
            if(s1_counts.contains(s2[i])) {
                s1_counts[s2[i]]--;
                if(s1_counts[s2[i]] == 0) non_zeros--;
            }
        }

        if(non_zeros == 0) return true;

        for(int i = s1.size(); i< s2.size(); i++) {
            if(s1_counts.contains(s2[i])) {
                s1_counts[s2[i]]--;
                if(s1_counts[s2[i]] == 0) non_zeros--;
            }
            if(s1_counts.contains(s2[i-s1.size()])) {
                if(s1_counts[s2[i-s1.size()]] == 0) non_zeros++;
                s1_counts[s2[i-s1.size()]]++;
            }
            if(non_zeros == 0) return true;
        }

        return false;
    }
};
