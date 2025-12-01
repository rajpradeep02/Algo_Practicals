#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() { isEnd = false; }
};

class SuffixTrie {
private:
    TrieNode *root;

public:
    SuffixTrie() {
        root = new TrieNode();
    }

    
    void insertSuffix(const string &text, int i) {
        TrieNode *curr = root;
        for (int j = i; j < text.length(); j++) {
            char ch = text[j];
            if (!curr->children[ch])
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    void buildSuffixTrie(const string &text) {
        for (int i = 0; i < text.length(); i++)
            insertSuffix(text, i);
    }

    
    bool search(const string &pattern) {
        TrieNode *curr = root;
        for (char ch : pattern) {
            if (!curr->children[ch]) return false;
            curr = curr->children[ch];
        }
        return true;
    }
};

int main() {
    string text = "banana";
    string pattern = "ana";

    SuffixTrie trie;
    trie.buildSuffixTrie(text);

    if (trie.search(pattern))
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";

    return 0;
}
