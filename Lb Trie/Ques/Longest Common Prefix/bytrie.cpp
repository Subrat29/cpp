#include <bits/stdc++.h>
using namespace std;

class TrieNode // additional means some modification on trie insertion code
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount; // additional

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0; // additional
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch) // additional
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index])
        {
            child = root->children[index];
        }

        else
        {
            child = new TrieNode(word[0]);
            root->childCount++; // additional
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) // longest common prefix
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                // aage badho
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) // tc = O(n*m), sc = O(n*m)
{
    Trie *t = new Trie('\0');

    // insert all stings into trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main()
{

    return 0;
}