/*approach
  brute force will be to check every possibility of string and use hashmap to store no of times they occur
  iterate again and add ans and return this is time consuming and will return TLE  
  so we use trie where we initailly mark everything null all the 26 letters and their sub-branches when we
  iterate through the words first we insert them inside the trie and then count for their prefixScores and 
  sum them up and return this is a much efficient approach*/
class TrieNode{
public:
    TrieNode* children[26];
    int count = 0;

    TrieNode(){
        count = 0;
        for(int i=0;i<26;++i){
            children[i] = nullptr;
        }
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insertNode(const string& word){
        TrieNode* node = root;
        for(char c:word){
            int ind = c - 'a';
            if(node->children[ind]==nullptr){
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
            node->count++;
        }
    }

    int prefixSum(const string& word){
        TrieNode* node = root;
        int score = 0;
        for(char c:word){
            int ind = c - 'a';
            if(node->children[ind]==nullptr)break;
            node = node->children[ind];
            score += node->count;
        }
        return score;
    }
};

class Solution{
public:
    vector<int> sumPrefixScores(vector<string>& words){
        Trie trie;
        for(const string& word:words){
            trie.insertNode(word);
        }
        vector<int>ans;
        for(const string& word:words){
            ans.push_back(trie.prefixSum(word));
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
