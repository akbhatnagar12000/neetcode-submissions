class PrefixTree {
    struct Trie{
        vector<Trie*>children;
        bool isEndWord;
        Trie(){
            for(int i=0;i<26;i++){
                children.push_back(nullptr);
            }
            isEndWord=false;
        }
    };
    Trie* trie;
public:
    PrefixTree() {
        trie = new Trie();
    }
    
    void insert(string word) {
        Trie* curr = trie;
        for(int i=0;i<word.length();i++){
            int idx = word[i]-'a';
            if(!curr->children[idx]){
                curr->children[idx] = new Trie();
            }
            curr=curr->children[idx];
        }
        curr->isEndWord=true;
    }
    
    bool search(string word) {
        Trie* curr = trie;

        for(char ch : word){
            int idx = ch - 'a';

            if(!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->isEndWord;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = trie;

        for(char ch : prefix){
            int idx = ch - 'a';

            if(!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};
