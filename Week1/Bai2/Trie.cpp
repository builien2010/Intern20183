
// Tìm hiểu về Trie: insert, search

#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie{

    struct Trie* children[ALPHABET_SIZE];

    bool isEndOfWord;

};

// tra ve  mot node moi
struct Trie* getNode(){

    struct Trie* p = new Trie;

    p->isEndOfWord = false;

    for ( int i = 0; i < ALPHABET_SIZE; i++){
        p->children[i] = NULL;

    }

    return p;

}

// Insert key : trie

void insert( struct Trie* root, string key){

    struct Trie* p = root;

    for ( int i = 0; i < key.length(); i++){

        int index = key[i] - 'a';
        
        if ( p->children[index] == NULL){
            cout << index << " ";
            cout << key[i] << endl;
            p->children[index] = getNode();
        }

        p = p->children[index];
        

    }

    // mark last node as leaf
    p->isEndOfWord = true;

}

// search : tìm kiếm chính xác key trong trie, chứ ko phải 1 phần của key

bool search(struct Trie* root, string key){

    struct Trie* p = root;

    for ( int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';

        if(p->children[index] == NULL)
            return false;
        p = p->children[index];

    }

    return (p != NULL && p->isEndOfWord);

}

int main(){

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

    int n = sizeof(keys)/sizeof(keys[0]);
     
    Trie* root = getNode();
    /*
    for (int i = 0; i < n; i++){
    
        insert(root, keys[i]);
    }
    */
    

    insert(root, "hello"); 
    insert(root, "dog"); 
    insert(root, "hell"); 
    insert(root, "cat"); 
    insert(root, "a"); 
    insert(root, "hel"); 
    insert(root, "help"); 
    insert(root, "helps"); 
    insert(root, "helping"); 

    search(root, "help") ? cout << "Yes" << endl : cout << "No" << endl;

    search(root, "then") ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;




}