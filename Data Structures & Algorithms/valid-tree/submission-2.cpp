class Solution {
    class Node{
        public: 
         std::vector<std::pair<Node*, bool>> edges;
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        // std::vector<Node> nodes(n);

        // for(auto& e : edges) {
        //     nodes[e[0]].edges.emplace_back(e[1]);
        //     nodes[e[1]].edges = e[0];
        // }

        std::cout << "validTreev" << n <<"edges" << edges.size()<< std::endl;
        std::uint8_t* graph = new std::uint8_t[n*n]();

        for(auto& e : edges) 
        {
            if(e[0] == e[1]) return false;

            graph[n * e[0] + e[1]] = 1;
            graph[n * e[1] + e[0]] = 1;
        }

        std::vector<std::uint8_t> visited(n);

        //BFS
        std::queue<std::uint8_t> q;
        q.push(0);

        while(!q.empty())
        {
            std::uint8_t node = q.front();
            q.pop();
            //mark visited
            visited[node]+=1;
            std::cout << "v " << (int)node << std::endl;
            
            std::uint16_t offset = node*n;
            for(int i = 1; i < n; i++ ){
                if(graph[offset + i] == 0 ) continue;

                std::cout << "v "<< (int)node << "n " << (int)i<< std::endl;

                if(graph[offset + i] == 1 and visited[i] == 1) {
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
        if(std::any_of( visited.cbegin(), visited.cend(), [](auto& x) {return x != 1;})) {
            return false;
        }

        return true;

    }
};
