class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_product = std::numeric_limits<int>::min();

        int l =0;
        int p =0;

        while(l < nums.size()){
            int negative_count=0;

            while(p< nums.size()) {
                if(nums[p] < 0) negative_count++;
                if(nums[p] == 0) {
                    max_product = std::max(max_product, 0);
                    break;
                }
                p++;
            }

            int sum_l = l;
            int sum_p = p;
            if(negative_count %2 !=0) {
                //left
                int left_accum =1;
                int i_l = l;
                for( ;i_l < p; i_l++) {
                    left_accum *= nums[i_l];
                    if(nums[i_l] < 0) {
                        break;
                    }
                } 

                //right
                int right_accum =1;
                int i_r = p-1;
                for( ;i_r > l; i_r--) {
                    right_accum *= nums[i_r];
                    if(nums[i_r] < 0) {
                        break;
                    } 
                } 

                if(left_accum > right_accum) {
                    sum_l = i_l+1;
                    sum_p = p;
                } else {
                    sum_l = l;
                    sum_p = i_r > l? i_r: l+1;
                }
            }
            int accum =1? sum_l<sum_p: 0;
            for(int i =sum_l; i < sum_p; i++) 
            {
                accum *=nums[i];
            }

            max_product = std::max(max_product, accum);

            p++;
            l=p;
        }

        return max_product;
    }
};
