class Node{
    public:
        char ch;
        bool terminal;
        vector<Node*> child;

        Node(char ch){
            this -> ch = ch;
            terminal = false;
            child = vector<Node*>(26,NULL);
        }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node('\0');
    }
    void insertUtil(Node* root, string& word, int ind){
        if(ind >= word.length()) {
            root -> terminal = true;
            return;
        }

        char ch = word[ind];
        if(root -> child[ch-'a'] == NULL){
            Node* nxt = new Node(ch);
            root -> child[ch-'a'] = nxt;
        }
        insertUtil(root -> child[ch-'a'], word,ind+1);
    }
    void insert(string word) {
        insertUtil(root,word,0);
    }

    bool searchUtil(Node* root, string& word, int ind){
        if(ind >= word.length()){
            if(root -> terminal) return true;
            return false;
        }

        char ch = word[ind];
        if(root -> child[ch -'a'] == NULL) return false;
        else{
            return searchUtil(root -> child[ch-'a'], word,ind+1);
        }
    }
    bool search(string word) {
        return searchUtil(root,word,0);
    }
    bool prefix(Node* root, string& pref, int ind){
        if(ind >= pref.length()){
            return true;
        }

        char ch = pref[ind];
        if(root -> child[ch-'a'] == NULL) return false;
        else{
            return prefix(root -> child[ch-'a'], pref, ind+1);
        }
    }
    bool startsWith(string pref) {
        return prefix(root,pref,0);
    }
};
