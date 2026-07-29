class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
     {
        std::unordered_map<string, std::vector<std::string>> m;

        for(auto& s: strs)
        { 
            std::array<std::uint16_t, 26> counts = {};
            for(auto& c :s) counts[c-'a']++;
            std::string accum;
            
            for(auto&x : counts){
                auto s = std::to_string(x);
                s = std::string(3 - s.size(), '0') + s;
                accum += s; 
            }
            if(m.contains(accum)) m[accum].emplace_back(std::move(s));
            else m.emplace(std::move(accum), std::vector<string>{std::move(s)});
        }

        vector<vector<string>> ret;
        for (auto& p: m) {
            ret.emplace_back(std::move(p.second));
        }

        return ret;
    }
};
