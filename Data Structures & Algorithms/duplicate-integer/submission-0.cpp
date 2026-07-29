class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> m;

        for(auto& x : nums) {
            if(m.contains(x)) return true;
            m.insert(x);
        }   
        return false;
    }
};