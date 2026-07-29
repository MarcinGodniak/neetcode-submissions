class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        using Item = std::pair<int, int>;
        auto cmp = [](const Item& a, const Item& b) {return a.first < b.first; };
        std::vector<Item> items(2000);
        for(auto& x: nums) {
            items[x+1000].first++;;
            items[x+1000].second = x;
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
