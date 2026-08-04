class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int accum =1;
        int max_product = std::numeric_limits<int>::min();

        int l =0;
        int p =0;

        while(l < nums.size()){
            while(p< nums.size() && accum != 0) {
                accum *= nums[p];
                max_product= std::max(max_product, accum);
                p++;
            }

            while(l< p-1) {
                accum /= nums[l];
                max_product= std::max(max_product, accum);
                l++;
            }

            accum =1;
            l=p;
        }
        return max_product;

    }
};
