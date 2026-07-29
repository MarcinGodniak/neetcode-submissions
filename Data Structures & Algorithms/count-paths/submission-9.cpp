class Solution {
public:
    int uniquePaths(int m, int n) {
        std::uint32_t* arr = new std::uint32_t[n];

        for(std::uint8_t i =0; i < n ; i++) {
            arr[i] = 1;
        }

        for(std::uint8_t i = 1; i < m; i++) {
            for (std::uint8_t j = 1; j < n; j++) {
                arr[j] = arr[(j-1)] + arr[j];
            }
        }

        return arr[(n-1)];

    }
};
