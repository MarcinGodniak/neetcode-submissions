class Solution {
public:
    int uniquePaths(int m, int n) {
        std::uint32_t* arr = new std::uint32_t[n *m];

        for(int i =0; i < n ; i++) {
            arr[i] = 1;
        }

        for(int j =0; j < m ; j++) {
            arr[j*n] = 1;
        }


        for(int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                arr[i*n + j] = arr[i*n + (j-1)] + arr[(i-1)*n + j];
            }
        }

        return arr[n*m-1];

    }
};
