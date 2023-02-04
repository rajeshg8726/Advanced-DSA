#include <bits/stdc++.h>
using namespace std;

// creating trie node structrucre
class Trienode
{
public:
    char data;
    Trienode *child[26];
    bool isTerminal;

    Trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

// insertion implementation

class Trie
{
public:
    Trienode *root;

    Trie()
    {
        root = new Trienode('\0');
    }
    void insertUtil(Trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true; // last node ka terminal true kar do
            return;
        }
        // assumption, word will be in CAPS
        int index = word[0] - 'A';  ///  map character to an array index
        Trienode *onechild;      

        // if one char is present then do nothing and move forward
        if (root->child[index] != NULL)
        {
            onechild = root->child[index];
        }
        else
        {
            // it means the char is not present then creat new node and insert it
            onechild = new Trienode(word[0]);
            root->child[index] = onechild;
        }

        // For the remaining strings call recursion
        insertUtil(onechild, word.substr(1));
    }

    void insertWrod(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(Trienode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        Trienode *onechild;
        // present character
        if (root->child[index] != NULL)
        {
            onechild = root->child[index];
        }
        else
        {
            // absent
            return false;
        }

        // recursion

        return searchUtil(onechild, word.substr(1));
    }

    bool searchString(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{

    Trie *t = new Trie();
    t->insertWrod("RAJESH");

    cout << "Word is present or not " << t->searchString("RAJESH") << endl;

    return 0;
}
