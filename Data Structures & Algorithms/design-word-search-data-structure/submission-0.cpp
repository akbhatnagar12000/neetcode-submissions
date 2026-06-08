class WordDictionary {
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
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
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
    
    bool searchWord(string &word, int pos, Trie* node){
        if(pos == word.size())
            return node->isEndWord;

        if(word[pos] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->children[i] &&
                searchWord(word, pos + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        int idx = word[pos] - 'a';

        if(!node->children[idx])
            return false;

        return searchWord(word, pos + 1, node->children[idx]);
    }

    bool search(string word) {
        return searchWord(word, 0, trie);
    }
};
