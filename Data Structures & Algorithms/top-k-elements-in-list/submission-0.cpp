class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        
        std::array<int, 2000> counts;
        for(auto& x: nums) counts[x + 1000]++; 
        
        
        using Item = std::pair<int, int>;
        auto cmp = [](const Item& a, const Item& b) {return a.first < b.first; };
        std::priority_queue<Item, std::vector<Item>, decltype(cmp)> heap(cmp);
        for(int i =0; i < counts.size(); i++) heap.push({counts[i], i -1000});

        vector<int> ret(k);
        for(int i=0; i < k; i++){
            ret[i]= heap.top().second;
            heap.pop();
        }
        return ret;
    }
};
