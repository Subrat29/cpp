#include <iostream>
#include <string>
#include <vector>
using namespace std;

// tc: O(n*m^2)    m = avg leng of string, n = no of strings given
// sc: O(n*m)

// creation
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = false;
        }
        isTerminal = false;
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

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
            // return;  why we not use return here ???
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();  //backtrack
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for lastch
            TrieNode *curr = prev->children[lastch - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // step 1: creation of trie
    Trie *t = new Trie();

    // step 2 : insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }

    // step 3 : return ans
    return t->getSuggestions(queryStr);
}

int main()
{

    return 0;
}