// Xong 

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

bool isLastNode( struct Trie* root){
    for ( int i = 0; i < ALPHABET_SIZE ; i++){
        if(root->children[i])
            return 0;
    }

    return 1;
}

void recommend( struct Trie* root, string prefix){

    // tiền tố trùng với 1 chuỗi trong trie

    if(root->isEndOfWord){
        cout << prefix << endl;
    }

    //Kiểm tra có phải node cuối

    if( isLastNode(root)){
        return;
    }

    // duyệt tất cả các kí tự xem root trỏ đến kí tự nào

    for ( int i = 0; i < ALPHABET_SIZE; i++){

        if( root->children[i]){
            prefix.push_back(97 + i);

            recommend(root->children[i], prefix);
            // xóa kí tự cuối mới thêm vào ở trên ( pop_back() ngược với push_back)
            prefix.pop_back();
  
        }

    }

}

int printAuto(struct Trie* root, const string query){

    struct Trie* p = root;
    int n = query.length();
 
    // search:
    for ( int i = 0; i < n; i++){
        int index = (int)query[i] - (int)'a';

        // root ko tro den ki tu query[i]
        if( p->children[index] == NULL)
            return 0;
        
        p = p->children[index];

    }

    // Kiểm tra tiền tố có phải là 1 từ ko 
    bool isWord = (p->isEndOfWord == true);

    bool isLast = isLastNode(p);

    if( isWord && isLast){
        cout << query << endl;
        return -1;

    }

    if(!isLast){
        string prefix = query;
        recommend(p, prefix);
        return 1;
    }
}

int main(){

    // Xây dựng trie
    Trie* root = getNode();
    
    insert(root, "hello"); 
    insert(root, "dog"); 
    insert(root, "hell"); 
    insert(root, "cat"); 
    insert(root, "a"); 
    insert(root, "hel"); 
    insert(root, "help"); 
    insert(root, "helps"); 
    insert(root, "helping");

    string prefix;

    cout << "Nhập vào ô tìm kiếm: "; 

    cin >> prefix ;


    int res = printAuto(root, prefix); 
  
    if ( res == -1) 
        cout << "Tiền tố này có trong trie và không có gợi ý khác "; 
  
    else if (res == 0) 
        cout << "Không có từ nào gợi ý cho tiền tố này \n"; 
  
   
    return 0;


}