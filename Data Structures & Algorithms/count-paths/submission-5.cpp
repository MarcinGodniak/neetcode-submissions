class Solution {
public:
    int uniquePaths(int m, int n) {
        std::uint32_t* arr = new std::uint32_t[n *2];

        for(int i =0; i < n ; i++) {
            arr[i] = 1;
        }

        for(int j =0; j < 2 ; j++) {
            arr[j*n] = 1;
        }


        for(int i = 1; i < m; i++) {
            int it = i %2;
            int it2 = 1 -it ;
            it = it*n;

            for (int j = 1; j < n; j++) {
                arr[it + j] = arr[it+ (j-1)] + arr[it2*n + j];
            }
        }

        return arr[n*((m-1)%2) + (n-1)];

    }
};
