#include <iostream>
#include <string.h>
using namespace std;
class TriesNode
{
public:
    char data;
    TriesNode **children;
    bool isTerminal;
    TriesNode(char data)
    {
        this->data = data;
        children = new TriesNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
    TriesNode *root;
    TriesNode * temp;

public:
    Trie()
    {
        root = new TriesNode('\0');
        temp = root;
    }

    void insertWordHelper(string Word, TriesNode *root)
    {

        // Base Case
        if (Word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calcuclation
        int Index = Word[0] - 'a';
        TriesNode *child;
        if (root->children[Index] == NULL)
        {
            child = new TriesNode(Word[0]);
            root->children[Index] = child;
        }

        // Recursive call
        insertWordHelper(Word.substr(1), root->children[Index]);
    }
    // For user
    void insertWord(string word)
    {
        insertWordHelper(word, root);
    }

    bool SearchHelp(TriesNode *root,string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }
        }

    
        // small caluclations
        int Index = word[0] - 'a';
        if (root->children[Index] == NULL)
        {
            return false;
        }
        // Recursive call
        return SearchHelp(root -> children [Index],word.substr(1));
    }
    bool Search(string word)
    {
        return SearchHelp(root, word);
    }
    
    void RemoveWordHelper(TriesNode *root,string word)
    {
            if (word.size() == 0)
            {
                root -> isTerminal = false;
                return;
            }
           TriesNode *child; 
            int Index = word[0] - 'a';
            if (root -> children[Index] != NULL)
            {
                child = root -> children[Index];
            }
            else
            {
                // word not found
                return;
            }

            RemoveWordHelper(child , word.substr(1)); 
            if (child -> isTerminal == false)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (child -> children[i] != NULL)
                    {
                        return;
                    }
                    
                }
                delete child;
                root -> children[Index] = NULL;
                
            }
                   
            
    }
    void RemoveWord(string word)
    {
        RemoveWordHelper(root,word);
    }

};
int main()
{
    Trie T1;
    T1.insertWord("abc");
    T1.insertWord("pqrst");
    cout<<T1.Search("abc")<<endl;
    T1.RemoveWord("abc");
    cout<<T1.Search("abc");
    
}