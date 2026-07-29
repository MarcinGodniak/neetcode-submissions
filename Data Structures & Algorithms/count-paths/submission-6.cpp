class Solution {
public:
    int uniquePaths(int m, int n) {
        std::uint32_t* arr = new std::uint32_t[n *2];

        for(std::uint8_t i =0; i < n ; i++) {
            arr[i] = 1;
        }

        for(std::uint8_t j =0; j < 2 ; j++) {
            arr[j*n] = 1;
        }


        for(std::uint8_t i = 1; i < m; i++) {
            std::uint8_t it = i %2;
            std::uint8_t it2 = 1 -it ;
            it = it*n;

            for (std::uint8_t j = 1; j < n; j++) {
                arr[it + j] = arr[it+ (j-1)] + arr[it2*n + j];
            }
        }

        return arr[n*((m-1)%2) + (n-1)];

    }
};
