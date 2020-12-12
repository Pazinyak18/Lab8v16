#include <iostream>
using namespace std;

struct Node{
    string name;
    string genre;
    string studio;
    float duration;

    struct Node* left;
    struct Node* right;

    Node(string name,string genre,string studio,float duration)
    : name(name),genre(genre),studio(studio),duration(duration){
        left = NULL;
        right = NULL;
    }

};

class Btree {
 public:
    Btree() : root(NULL){}
    ~Btree();
    int size;

    void insert(string name,string genre,string studio,float duration);
    void cutTree();
    void print();
    void deleteElemnt(string studio);
    int getSize();
    void searchByGerne(string genre);
 private:
    Node* root;

    Node* searchByGerne(string genre,Node* leaf);
    void print(Node* leaf, int space);
    void insert(string name,string genre,string studio,float duration,Node*& leaf);
    void cutTree(Node* leaf);
    void deleteElemnt(string studio,Node* leaf);
    int getSize(Node *leaf);
    Node* minValueNode(Node* leaf);
    Node* deleteRoot(string Author, Node* Leaf);
};

void Btree::searchByGerne(string genre){
    searchByGerne(genre,root);
}

Btree::~Btree() {
    cutTree(root);
}
void Btree::cutTree(){
    cutTree(root);
}
void Btree::cutTree(Node* leaf)
{
    if(leaf!=NULL){
        return;
    }

    cutTree(leaf->left);
    cutTree(leaf->right);
    delete leaf;
}

void Btree::insert(string name,string genre,string studio,float duration) {
    insert(name,genre,studio,duration,root);
    getSize();
}

void Btree::insert(string name,string genre,string studio,float duration,Node*& leaf) {
    if(leaf==NULL) {
        leaf = new Node(name,genre,studio,duration); //Insert Root
    }else if(name < leaf->name){                        //left
        if(leaf->left!=NULL) {
            insert(name,genre,studio,duration,leaf->left);
        }
        else{                          // go to next left node
            leaf->left = new Node(name,genre,studio,duration);
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }else if(name >= leaf->name){                       //right
        if(leaf->right!=NULL) {
            insert(name,genre,studio,duration, leaf->right);
        }
        else{                          // go to next right node
            leaf->right = new Node(name,genre,studio,duration);
            leaf->right->left=NULL;
            leaf->right->right=NULL;
        }
    }

}
Node* Btree::searchByGerne(string genre,Node *leaf){
    if(leaf != NULL){
        if( leaf->genre == genre){
            cout<<" Name :"<< leaf -> name <<" genre :"<< leaf -> genre <<" studio :"<< leaf -> studio << endl;
        }
        searchByGerne(genre, leaf -> right);
        searchByGerne(genre,leaf -> left);
    }
    return nullptr;
}

void Btree::print(Node *leaf, int space)
{
    if (leaf == NULL) {
        return;
    }


    space += getSize() + (leaf->name.length());



    print(leaf -> right, space);


    cout<<endl;
    for (int i = getSize(); i < space; i++) {
        cout << " ";
    }


    cout<< leaf -> name << "\n";

    print(leaf -> left, space);
}

void Btree::print(){
    print(root, 0);
}

void Btree::deleteElemnt(string studio){
    deleteElemnt(studio,root);
}

Node* Btree::minValueNode(Node* leaf){
    Node* current = leaf;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node * Btree::deleteRoot(string studio, Node* leaf){
    // base case
    if (leaf == NULL) {
        return leaf;

        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
    }else{
        leaf->left = deleteRoot(studio, leaf->left);
        leaf->right = deleteRoot(studio, leaf->right);
    }
    if(leaf->studio == studio){
        // node with only one child or no child
        if (leaf->left == NULL){
            Node* temp = leaf->right;
            delete leaf;
            return temp;

        }else if (leaf->right == NULL){
            Node* temp = leaf->left;
            delete leaf;
            return temp;

        }
        // node with two children: Get the inorder successor (smallest

        // in the right subtree)
        Node* temp = minValueNode(leaf->right);
        leaf->name = temp->name;
        leaf->right = deleteRoot( temp->studio,leaf->right);

    }
    return leaf;

}
void Btree::deleteElemnt(string studio,Node* leaf){
    deleteRoot(studio,leaf);

}

int Btree::getSize(Node *leaf){
    size = 0;
    if(leaf != NULL){
        getSize(leaf->left);
        getSize(leaf->right);
        size++;
    }

    return size;
}
int Btree::getSize(){
    return getSize(root);
}
