#include <iostream>
#include <queue>

using namespace std;

struct Node{
    //We create a node with a value and a pointer to the next node
    int data;
    Node *left, *right;

    //We create a constructor for the node
    Node (int d):data(d),left(NULL),right(NULL){}
};

class BinarySearchTree{
    //We create a pointer to the root of the tree
    //The user will not have access to the root of the tree
    private:
        Node *root;

        void Insert(Node *&, int&); //Insert a node in the tree
        void Inorder(Node *); //Print the tree in order
        void Preorder(Node *); //Print the tree in preorder
        void Postorder(Node *); //Print the tree in postorder
        void DeleteNode(int&, Node*&);
    
    public:
        BinarySearchTree():root(NULL){}
        ~BinarySearchTree(){
            DeleteBST(root);
            cout << "\nDestructor: BST deleted." << endl;
        }

        //Functions
        void Insert(int &value){
            Insert(value, root);
        }
        void Inorder(){
            Inorder(root);
        
        }
        void Preorder(){
            Preorder(root);
        }
        void Postorder(){
            Postorder(root);
        }

        void BFT();

        void SubstituteToMin(Node*&, Node*&);
        void DeleteNode(int &value){
            DeleteNode(value,root);
            }

        //Delete a node in the tree
        void DeleteBST(Node *&){
};

//Insert a node in the tree
//We pass the root of the tree by reference and the value of the node also by reference
//*& means that we pass the address of the root of the tree
//An int * is a pointer to an int
//So int *& must be a reference to a pointer to an int
void BinarySearchTree::Insert(Node *&root, int &value){
    if(root == NULL){ //If the root is null, we create a new node
        root = new Node(value); //We create a new node with the value
    }
    else{
        if(value < root->data){ //If the value is less than the root, we insert it in the left subtree
            Insert(root->left, value); //We go to the left of the tree
        }
        else if(value, root -> data){ //If the value is greater than the root, we insert it in the right subtree
            Insert(root->right, value); //We go to the right of the tree
        }
        else{
            cout << "The value is already in the tree" << endl;
            cout << "Repeated element" << endl;
        }
    }
}

void BinarySearchTree::Inorder(Node *root){
    if(root == NULL){
        return;
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void BinarySearchTree::Preorder(Node *root){
    if(root != NULL){
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
    
}

void BinarySearchTree::Postorder(Node *root){
    if(root == NULL){
        return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void BinarySearchTree:: BFT(){
    if(root == NULL){
        cout << "The tree is empty" << endl;
        return;
    }

    queue<Node*> Q;
    Q.push(root);

    Node *Aux;
    while(!Q.empty()){

        Q.push(NULL);
        Aux = Q.front();
        while(Aux != NULL){
            cout << Aux->data << " ";
            if(Aux->left != NULL){
                Q.push(Aux->left);
            }
            if(Aux->right != NULL){
                Q.push(Aux->right);
            }
            Q.pop();
            Aux = Q.front();
        }
        Q.pop();
        cout << endl;
    }
}

void BinarySearchTree::SubstituteToMin(Node *&root, Node *&Aux){
    if(Aux->left != NULL){
        SubstituteToMin(root-> left, Aux);
    }
    else{
        //We substitute the value of the node to delete with the value of the node that we are going to delete
        //Transfer data from the substitute node to the node to delete
        Aux->data = root->data;
        //We delete the node that we have copied
        //Save the minValue Node in Aux (Aux is a pointer to the node to delete)
        Aux = root;
        //We move the root to the right of the tree
        //Swap places with the right node (Node or NULL)
        root = root->right;
    }
}

void BinarySearchTree::DeleteNode(int &value, Node *&root){
    if(root == NULL){
        cout << "The tree is empty" << endl;
        return;
    }
    else if(value < root->data){
        DeleteNode(value, root->left);
    }
    else if(value > root->data){
        DeleteNode(value, root->right);
    }
    else{
        Node *Aux = root;
        if(Aux-> right == NULL){ //Only left child
            root = Aux->left;
        }
        if(Aux->left == NULL){ //Only right child
            root = Aux->right;
        }
        if(Aux->left != NULL && Aux->right != NULL){ //Two children
            SubstituteToMin(root->right, Aux);

        cout << "\nThe key to delete: " << value << endl;
        cout << "The element was deleeted with the key: " << Aux->data << endl;
        delete Aux;
        }
    }
}