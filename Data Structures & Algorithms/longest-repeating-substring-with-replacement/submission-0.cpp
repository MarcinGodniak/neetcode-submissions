class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int max_len = 0;
        for(int c = 'A'; c <='Z'; ++c) {
            std::queue<int> rep;
            int curr_len = 0;
            for(int i =0; i< s.size(); i++) {
                if(s[i] == c) {
                    curr_len++;
                    max_len= std::max(max_len, curr_len);
                    continue;
                }

                rep.push(i);

                if(rep.size() <= k) {
                    curr_len++;
                    max_len= std::max(max_len, curr_len);
                    continue;
                }

                int st = rep.front();
                rep.pop();
                curr_len = i - st;

            }
        }
        return max_len;
    }
};
