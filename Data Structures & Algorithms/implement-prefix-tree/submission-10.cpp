class PrefixTree {
    struct Node {
        char c;
        bool is_leaf = false;
        std::array<Node*, 27> children = {};
    };

    Node* root;
public:
    PrefixTree() 
    {
        root = new Node{};
    }
    
    void insert(string word) 
    {
        Node** n = &root;
        int i = 0;  
        while(i < word.size()) {
            char c = word[i] - 'a';
            if((*n)->children[c] == nullptr) {
                (*n)->children[c] = new Node{c};
            }
            n = &((*n)->children[c]);
            i++;
        }
        (*n)->is_leaf = true;
    }
    
    bool search(string word) {
        Node * n = root;
        int i = 0;
        while(i < word.size()) {
            char c = word[i] - 'a';
            if(n->children[c] == nullptr) {
                return false;
            }
            n = n->children[c];
            i++;
        }
        return n->is_leaf;
    }
    
    bool startsWith(string prefix) {
        Node * n = root;
        int i = 0;
        while(i < prefix.size()) {
            char c = prefix[i] - 'a';
            if(n->children[c] == nullptr) {
                return false;
            }
            n = n->children[c];
            i++;
        }
        return true;
    }
};
