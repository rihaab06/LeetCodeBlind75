#include<iostream>
#include<string>
using namespace std;
class Trie {
private:
    struct TrieNode
    {
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            //intitially no children
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
            isEnd = false; //no words end at the beginning

            
        }
    }; 
    TrieNode* root;

    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] -'a'; //index will store the ascii value of i  that is a= 0 b= 1 c = 3 which is index value
           
            if (current->children[index]==nullptr)
            {
                current->children[index] = new TrieNode(); // If character doesn't exist, create a node
            }
               // Move to the next node
               current = current->children[index]; 
        }
         // Word ends here
        current->isEnd = true;
        
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] -'a';
            if (current->children[index] == nullptr)
            {
                return false;
            }
            current = current->children[index];
            
        }
       return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (current->children[index]== nullptr)
            {
                return false;
            }
            current = current->children[index];
        }
        return true;

    }
};
int main(){
   Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("cat");

    // Check if complete word exists
    cout << "Is apple present? "
         << trie.search("apple") << endl;

    cout << "Is app present? "
         << trie.search("app") << endl;

    cout << "Is car present? "
         << trie.search("car") << endl;

    // Check if prefix exists
    cout << "Is app a prefix? "
         << trie.startsWith("app") << endl;

    cout << "Is ap a prefix? "
         << trie.startsWith("ap") << endl;

    cout << "Is ca a prefix? "
         << trie.startsWith("ca") << endl;

    cout << "Is dog a prefix? "
         << trie.startsWith("dog") << endl;

return 0;
}