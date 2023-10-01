
// https://leetcode.com/problems/longest-common-prefix/

class TrieNode{
    public:
        char ch;
        TrieNode* children[26];
        bool isEnd;
        int childCount;

        TrieNode(char ch){
            this->ch= ch;
            for(int i=0; i<26; i++){
                children[i]= NULL;
            }
            isEnd= false;
            childCount= 0;
        }

};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root= new TrieNode('\0');
    }
    
    void insertWord(TrieNode* root, string word){

        //Word isEmpty
        if(word.length()==0){
            root->isEnd= true;
            return;
        }

        int index= word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child= root->children[index];
        }else{
            child= new TrieNode(word[0]);
            root->children[index]= child;
            root->childCount++;
        }
        
        insertWord(child, word.substr(1));

    }

    void insert(string word) {
        insertWord(root, word);
    }

    string getLongestPrefix(string word){
        string ans="";
        for(int i=0; i<word.length(); i++){
            char ch= word[i];
            if(root->childCount==1){
                ans.push_back(ch);
                root= root->children[ch-'a'];
            }else{
                break;
            }
            if(root->isEnd)
                break;
        }
        return ans;
    }

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie= new Trie();
        string smallestWord= strs[0];
        for(int i=0; i<strs.size(); i++){
            trie->insert(strs[i]);
            if(i+1<strs.size() && strs[i+1].length()<smallestWord.length()){
                smallestWord= strs[i+1];
            }
        }
        
    
        return trie->getLongestPrefix(smallestWord);

    }
};