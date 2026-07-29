class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        
        std::array<int, 2000> counts{};
        for(auto& x: nums) counts[x + 1000]++; 
        
        
        using Item = std::pair<int, int>;
        auto cmp = [](const Item& a, const Item& b) {return a.first < b.first; };
        std::vector<Item> items;

        for (int i = 0; i < counts.size(); i++) {
            if(counts[i] <= 0) continue;
            items.push_back({counts[i], i - 1000});
        }

        std::priority_queue<Item, std::vector<Item>, decltype(cmp)> heap(cmp, std::move(items));

        vector<int> ret(k);
        for(int i=0; i < k; i++){
            ret[i]= heap.top().second;
            heap.pop();
        }
        return ret;
    }
};
