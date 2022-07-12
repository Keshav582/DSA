#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    map<char, TrieNode *> children;
    bool wordEnd;
    int prefixCount;
    TrieNode() {
        wordEnd = false;
        prefixCount = 0;
    }
};

void insert(TrieNode &root, string word) {
    TrieNode *curr = &root;
    for(auto character:word) {
        if(curr->children.find(character)==curr->children.end()) {
            curr->children[character] = new TrieNode();
        }
        curr = curr->children[character];
        curr->prefixCount++;
    }
    curr->wordEnd = true;
}

int countPrefix(TrieNode &root, string word) {
    TrieNode *curr = &root;
    for(auto character:word) {
        if(curr->children.find(character)==curr->children.end()) return 0;
        curr = curr->children[character];
    }
    return curr->prefixCount;
}

bool isWordPresent(TrieNode &root, string word) {
    TrieNode *curr = &root;
    for(auto character:word) {
        if(curr->children.find(character)==curr->children.end()) return false;
        curr = curr->children[character];
    }
    return curr->wordEnd;
}

int main() {
    TrieNode root;
    insert(root, "trie");
    insert(root, "try");
    cout << countPrefix(root, "tr") << '\n';
    cout << isWordPresent(root, "try") << '\n';
    return 0;
}