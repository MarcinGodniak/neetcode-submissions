class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        std::uint8_t graph[100*100];

        if(edges.size() > n-1) return false;
        
        for(auto& e : edges) 
        {
            if(e[0] == e[1]) return false;

            graph[n * e[0] + e[1]] = 1;
            graph[n * e[1] + e[0]] = 1;
        }

        std::uint8_t visited[100];

        //BFS
        std::queue<std::uint8_t> q;
        q.push(0);

        std::uint8_t v_c =0;

        while(!q.empty())
        {
            std::uint8_t node = q.front();
            q.pop();
            //mark visited
            visited[node]+=1;
            v_c++;
            
            std::uint16_t offset = node*n;
            for(std::uint8_t i = 1; i < n; i++ ){
                if(graph[offset + i] == 0 ) continue;

                if(visited[i] == 1) {
                    return false;
                }
                //remove the egde
                graph[offset + i] = 0;
                graph[i*n + node] = 0;

                //enqueue
                q.push(i);
            }
        }

        //all visited
        if(v_c != n) {
            return false;
        }

        return true;

    }
};
