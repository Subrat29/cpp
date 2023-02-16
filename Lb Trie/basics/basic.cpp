#include <bits/stdc++.h>  //this approach is based on capital letter
using namespace std;

// creation
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTermimal;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTermimal = false;
    }
};



class Trie
{
public:
    TrieNode *root;

    // constructor
    Trie()
    {
        root = new TrieNode('\0');
    }



    // INSERTION tc-> O(l) l: len of word
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTermimal = true;
            return;
        }

        // assumption, word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }



    // SEARCH tc-> O(l)
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTermimal; // means last word terminal h ki nhi like we search tim but time is given here m is not terminal means where string end
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }



    // DELETION tc -> O(l)
    void Delete(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTermimal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            return Delete(child, word.substr(1));
        }
        else
        {
            cout << "Word is not present" << endl;
        }
    }

    void deleteWord(string word)
    {
        Delete(root, word);
    }
};



int main()
{
    Trie *t = new Trie();

    // insertion
    t->insertWord("RAMAN");
    t->insertWord("TIME");
    t->insertWord("DO");



    // searching
    string word = "RAMAN";
    if (t->searchWord(word))
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word not found" << endl;
    }



    // deletion
    cout << "After deletion " << endl;
    t->deleteWord("RAMAN");
    if (t->searchWord(word))
    {
        cout << "Word Found" << endl;
    }
    else
    {
        cout << "Word not found" << endl;
    }

    return 0;
}