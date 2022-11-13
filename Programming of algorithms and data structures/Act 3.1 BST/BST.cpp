//Liliana Solórzano Pérez  Matrícula: A01641392
#include <iostream>
#include <queue>


using namespace std;

//We create the nodes of the tree
struct Node {
    int data;
    Node *left;
    Node *right;
};

//-------------------- Timr copmlexity of thr 3 functions: O(n) --------------------

//We create the preorder function
void Preorder(Node *root) {
    if (root == NULL) return; //If the tree is empty, we return nothing
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

//We create the inorder function
void Inorder(Node *root) {
    if (root == NULL) return; //If the tree is empty, we return nothing
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

//We create the postorder function
void Postorder(Node *root) {
    if (root == NULL) return; //If the tree is empty, we return nothing
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//-------------------- Timr copmlexity: O(n) --------------------
//We create the level by level function
void LevelOrder(Node *root){
    if (root == NULL) return; //If the tree is empty, we return nothing
    queue<Node*> Q;
    Q.push(root);
    //while there is at least one discovered node
    while (!Q.empty()) {
        Node *current = Q.front();
        cout << current->data << " ";
        //Pushing the adresses of the children into the queue
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
        Q.pop(); //Removing the element at the front
    }
}

//-------------------- Timr copmlexity: O(n) --------------------
//We create the function to get the height of the tree
int height(Node *root){
    if (root == NULL) return -1; //If the tree is empty, we return -1
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

//-------------------- Timr copmlexity: O(n) --------------------
//Function to get the ancestors of a node
/* If target is present in tree, then prints the ancestors
   and returns true, otherwise returns false. */
bool Ancestors(struct Node *root, int target)
{
    /* base cases */
    if (root == NULL)
        return false;
    
    if (root->data == target)
        return true;
    
    /* If target is present in either left or right subtree of this node,
        then print this node */
    if ( Ancestors(root->left, target) ||
        Ancestors(root->right, target) )
    {
        cout << root->data << " ";
        return true;
    }
    
    /* Else return false */
    return false;
    }

//-------------------- Timr copmlexity: O(n) --------------------
//Function to get what level I am in
int getLevelUtil(struct Node* node, int data, int level)
{
    if (node == NULL)
        return 0;

    if (node->data == data)
        return level;

    int downlevel
        = getLevelUtil(node->left, data, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->right, data, level + 1);
    return downlevel;
}

//Returns level of given data value */
int getLevel(struct Node* node, int data)
{
    return getLevelUtil(node, data, 1);
}

int main (){
    //We create the nodes of the tree
    Node *root = new Node();

    //We create the root node opf the tree
    root->data = 1;

    //We create the left child of the root node
    root->left = new Node();
    root->left->data = 2;

    //We create the right child of the root node
    root->right = new Node();
    root->right->data = 3;

    //We create the left child of the left child of the root node
    root->left->left = new Node();
    root->left->left->data = 4;

    //We create the right child of the left child of the root node
    root->left->right = new Node();
    root->left->right->data = 5;

    //We simulate the tree
    //              1
    //            /   \
    //           2     3
    //          / \
    //         4   5

    //--------------------- First test case ---------------------
    //We print the tree in preorder
    cout << endl;
    cout << "++++ First test case ++++" << endl;
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;

    //We print the tree in inorder
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;

    //We print the tree in postorder
    cout << "Postorder: ";
    Postorder(root);
    cout << endl;

    //We print the tree level by level
    cout << "What Level am I?: ";
    int x;
    cout << endl;
    for (x = 1; x <= 5; x++) {
        int level = getLevel(root, x);
        if (level)
            cout << "Level of " << x << " is " << level
                << endl;
        else
            cout << x << "is not present in tree" << endl;
    }

    //Function LevelOrder
    cout << "Level Order: ";
    LevelOrder(root);
    cout << endl;

    //We print the height of the tree
    cout << "Height of the tree: " << height(root) << endl;

    //We print the ancestors of a node
    cout << "Ancestors of 5: ";
    Ancestors(root, 5);
    cout << endl;

    cout << endl;

 //--------------------- Second test case ---------------------
// We create the nodes of the tree
    Node *root2 = new Node();
    root2 -> data = 5;
    root2 -> left = new Node();
    root2 -> left -> data = 23;
    root2 -> right = new Node();
    root2 -> right -> data = 7;
    root2 -> left -> left = new Node();
    root2 -> left -> left -> data = 19;
    root2 -> left -> right = new Node();
    root2 -> left -> right -> data = 13;

    //We simulate the tree
    //              5
    //            /   \
    //           23     7
    //          / \
    //         19   13

    //We print the functions
    cout << "++++ Second test case ++++" << endl;
    cout << "Preorder: ";
    Preorder(root2);
    cout << endl;

    cout << "Inorder: ";
    Inorder(root2);
    cout << endl;

    cout << "Postorder: ";
    Postorder(root2);
    cout << endl;

    cout << "What Level am I?: ";
    int y;
    cout << endl;
    for (y = 1; y <= 7; y++) {
        int level = getLevel(root2, y);
        if (level)
            cout << "Level of " << y << " is " << level
                << endl;
        else
            cout << y << " is not present in tree" << endl;
    }

    cout << "Level by level: ";
    LevelOrder(root2);
    cout << endl;

    cout << "Height of the tree: " << height(root2) << endl;

    cout << "Ancestors of 13: ";
    Ancestors(root2, 13);
    cout << endl;
    cout << endl;



    cout << "++++ Third test case ++++" << endl;
    //We create the nodes of the tree
    Node *root3 = new Node();
    root3 -> data = 15;
    root3 -> left = new Node();
    root3 -> left -> data = 2;
    root3 -> right = new Node();
    root3 -> right -> data = 32;
    root3 -> left -> left = new Node();
    root3 -> left -> left -> data = 1;
    root3 -> left -> right = new Node();
    root3 -> left -> right -> data = 8;
    root3 -> right -> left = new Node();
    root3 -> right -> left -> data = 16;

    //We simulate the tree
    //              15
    //            /   \
    //           2     32
    //          / \
    //         1   8
    //            /
    //           16

    //We print the functions
    cout << "Preorder: ";
    Preorder(root3);
    cout << endl;

    cout << "Inorder: ";
    Inorder(root3);
    cout << endl;

    cout << "Postorder: ";
    Postorder(root3);
    cout << endl;

    cout << "What Level am I?: ";
    int z;
    cout << endl;
    for (z = 1; z <= 5; z++) {
        int level = getLevel(root3, z);
        if (level)
            cout << "Level of " << z << " is " << level
                << endl;
        else
            cout << z << " is not present in tree" << endl;
    }

    cout << "Level by level: ";
    LevelOrder(root3);
    cout << endl;

    cout << "Height of the tree: " << height(root3) << endl;

    cout << "Ancestor of 16: ";
    cout << Ancestors(root3, 16) << endl;
    cout << endl;

    cout << "++++ Fourth test case ++++" << endl;
    //We create the nodes of the tree
    Node *root4 = new Node();
    root4 -> data = 4;
    root4 -> left = new Node();
    root4 -> left -> data = 7;
    root4 -> right = new Node();
    root4 -> right -> data = 2;
    root4 -> left -> left = new Node();
    root4 -> left -> left -> data = 9;
    root4 -> left -> right = new Node();
    root4 -> left -> right -> data = 6;
    root4 -> right -> left = new Node();
    root4 -> right -> left -> data = 3;
    root4 -> right -> right = new Node();
    root4 -> right -> right -> data = 1;

    //We simulate the tree
    //              4
    //            /   \
    //           7     2
    //          / \   / \
    //         9   6 3   1

    //We print the functions
    cout << "Preorder: ";
    Preorder(root4);
    cout << endl;

    cout << "Inorder: ";
    Inorder(root4);
    cout << endl;

    cout << "Postorder: ";
    Postorder(root4);
    cout << endl;

    cout << "What Level am I?: ";
    int w;
    cout << endl;
    for (w = 1; w <= 9; w++) {
        int level = getLevel(root4, w);
        if (level)
            cout << "Level of " << w << " is " << level
                << endl;
        else
            cout << w << " is not present in tree" << endl;
    }

    cout << "Level by level: ";
    LevelOrder(root4);
    cout << endl;

    cout << "Height of the tree: " << height(root4) << endl;

    cout << "Ancestor of 1: ";
    cout << Ancestors(root4, 1) << endl;
    cout << endl;

    cout << "++++ End of the program ++++" << endl;

    return 0;
}

