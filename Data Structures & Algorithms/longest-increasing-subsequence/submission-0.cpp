class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        std::array<std::uint16_t, 2002> arr = {};
        int ret = 1;
        for(int i =0 ; i < nums.size(); ++i) {
            int max_len = 1;
            for(int j =nums[i]+1000 -1; j >=0; j--){
                max_len = std::max(max_len, arr[j] +1);
            }
            arr[nums[i]+1000] = max_len;
            ret = std::max(ret, max_len);
        }

        return ret;
    }
};
