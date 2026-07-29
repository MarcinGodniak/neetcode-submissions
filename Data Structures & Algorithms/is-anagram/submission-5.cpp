class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;

        std::array<short, ('z'-'a' +1)> counts = {};

        for(auto& c: s) {
            counts[c - 'a']++;
        }

        for(auto& c: t) {
            counts[c- 'a']--;
        }

        for(int i =0; i < counts.size(); ++i) if(counts[i] != 0) return false;
        
        return true;
    }
};
