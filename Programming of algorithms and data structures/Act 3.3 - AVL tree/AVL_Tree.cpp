#include <iostream>
#define SPACE 10

using namespace std;

// Class to create a node
class AVLNode{
    public:
        int value;
        AVLNode *left;
        AVLNode *right;
    
    AVLNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }

    AVLNode(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

// Class to create a tree
class AVLTree{
    public:
        AVLNode *root;
    AVLTree(){
        root = NULL;
    }

    // Check if tree is empty
    // ---------------------- Time complexity of this function is O(1) ----------------------
    bool isEmpty(){
        if (root == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    

    //Get height of the tree
    // ---------------------- Time complexity of this function is O(n) ----------------------
    int height(AVLNode * node){
        if (node == NULL){
            return -1;
        }
        else{
            int left_height = height(node->left);
            int right_height = height(node->right);

            if (left_height > right_height){
                return (left_height + 1);
            }
            else{
                return (right_height + 1);
            }
        }
    }

    // Get balance factor of node N
    // ---------------------- Time complexity of this function is O(1) ----------------------
    int getBalanceFactor(AVLNode * node){
        if (node == NULL){
            return -1;
        }
        else{
            return height(node->left) - height(node->right);
        }
    }

    // Right rotate
    // ---------------------- Time complexity of this function is O(1) ----------------------
    AVLNode * rightRotate(AVLNode * parent){
        AVLNode * temp = parent->left;
        AVLNode * t = temp->right;

        // Perform rotation
        temp->right = parent;
        parent->left = t;
        return temp;
    }

    // Left rotate
    // ---------------------- Time complexity of this function is O(1) ----------------------
    AVLNode * leftRotate(AVLNode * parent){
        AVLNode * temp = parent->right;
        AVLNode * t = temp->left;

        // Perform rotation
        temp->left = parent;
        parent->right = t;
        // Return new root
        return temp;
    }

    // Insert a node
    // ---------------------- Time complexity of this function is O(log n) ----------------------
    AVLNode * insertNode(AVLNode * node, AVLNode * new_node){
        // Find the correct position and insert the node
        if (node == NULL){
            node = new_node;
            cout << "Node Inserted" << endl;
            return node;
        }
        if (new_node -> value < node -> value){
            node->left = insertNode(node->left, new_node);
        }
        else if (new_node -> value > node -> value){
            node->right = insertNode(node->right, new_node);
        }
        else{
            cout << "Node already exists, Insert another value" << endl;
            return node;
        }

        // Update the balance factor of each node and
        // balance the tree
        int balance = getBalanceFactor(node);
        // Left Left Case
        if (balance > 1 && new_node -> value < node->left->value){
            return rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && new_node -> value > node->right->value){
            return leftRotate(node);
        }
        // Left Right Case
        if (balance > 1 && new_node -> value > node->left->value){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && new_node -> value < node->right->value){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // Return the (unchanged) node pointer
        return node;
    }
        //Finding the min value
        // ---------------------- Time complexity of this function is O(log n) ----------------------
        AVLNode * minValueNode(AVLNode * node){
            AVLNode * current = node;
            while (current->left != NULL){
                current = current->left;
            }
            return current;
        }

        // Delete a node
        // ---------------------- Time complexity of this function is O(log n) ----------------------
        AVLNode * deleteNode(AVLNode * root, int value){
            // Find the node and delete it
            if (root == NULL){
                return NULL;
            }
            else if(value < root->value){
                root->left = deleteNode(root->left, value);
            }

            else if(value > root->value){
                root->right = deleteNode(root->right, value);
            }

            else{
                // Case 1:  No child
                if (root->left == NULL ){
                    AVLNode * temp = root->right;
                    delete root;
                    return temp;
                }
                //Case 2: One child
                else if (root->right == NULL){
                    AVLNode * temp = root -> left;
                    delete root;
                    return temp;
                }
                // case 3: 2 children
                else{
                    AVLNode * temp = minValueNode(root->right);
                    root->value = temp->value;
                    root->right = deleteNode(root->right, temp->value);
                }
            }
            
            // Update the balance factor of each node and
            // balance the tree
            int balance = getBalanceFactor(root);
            // Left Left Case
            if (balance == 2 && getBalanceFactor(root->left) >= 0){
                return rightRotate(root);
            }
            // Left Right Case
            if (balance == 2 && getBalanceFactor(root->left) == -1){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            // Right Right Case
            if (balance == -2 && getBalanceFactor(root->right) <= 0){
                return leftRotate(root);
            }
            // Right Left Case
            if (balance == -2 && getBalanceFactor(root->right) == 1){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }

        // Print the tree
        // ---------------------- Time complexity of this function is O(n) ----------------------
        void printTree(AVLNode * node, int space){
            // Base case
            if (node == NULL){
                return;
            }
            // Increase distance between levels
            space += SPACE;
            // Process right child first
            printTree(node->right, space);
            // Print current node after space
            // count
            cout << endl;
            for (int i = SPACE; i < space; i++){
                cout << " ";
            }
            cout << node->value << endl;
            // Process left child
            printTree(node->left, space);
        }

        //print in preorder
        // ---------------------- Time complexity of this function is O(n) ----------------------
        void preorder(AVLNode * node){
            if (node == NULL){
                return;
            }
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }

        //print in inorder
        // ---------------------- Time complexity of this function is O(n) ----------------------
        void inorder(AVLNode * node){
            if (node == NULL){
                return;
            }
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }

        //print in postorder
        // ---------------------- Time complexity of this function is O(n) ----------------------
        void postorder(AVLNode * node){
            if (node == NULL){
                return;
            }
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }

        //Print at a given level
        // ---------------------- Time complexity of this function is O(n) ----------------------
        void printGivenLevel(AVLNode * node, int level){
            if (node == NULL){
                return;
            }
            if (level == 0){
                cout << node->value << " ";
            }
            else{
                printGivenLevel(node->left, level - 1);
                printGivenLevel(node->right, level - 1);
            }
        }

        //Print level order
        // ---------------------- Time complexity of this function is O(n^2) ----------------------
        void printLevelOrder(AVLNode * node){
            int h = height(node);
            for (int i = 0; i <= h; i++){
                printGivenLevel(node, i);
            }
        }

        //Iterative search
        // ---------------------- Time complexity of this function is O(log n) ----------------------
        AVLNode * iterativeSearch(int value){
            if (root == NULL){
                return root;
            }
            else {
                AVLNode * temp = root;
                while (temp != NULL){
                    if (value == temp->value){
                        return temp;
                    }
                    else if (value < temp->value){
                        temp = temp->left;
                    }
                    else {
                        temp = temp->right;
                    }
                }
                return NULL;
                }
        }

    //Recursive search
    // ---------------------- Time complexity of this function is O(log n) ----------------------
    AVLNode * recursiveSearch(AVLNode * node, int val){
        if (node == NULL || node->value == val){
            return node;
        }
        else if (val < node->value){
            return recursiveSearch(node->left, val);
        }
        else{
            return recursiveSearch(node->right, val);
        }
    }
};

int main(){
    AVLTree tree;
    int option, val;

    do{
        cout << "++++ AVL Tree Operations ++++" << endl;
        cout << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your option: ";
        cin >> option;

        AVLNode * new_node = new AVLNode();

        switch (option)
        {
        case 0:
            break;
        
        case 1:
            cout << "INSERT a node" << endl;
            cout << "Enter value of a node to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            tree.root = tree.insertNode(tree.root, new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH a node" << endl;
            cout << "Enter value of a node to SEARCH in AVL Tree: ";
            cin >> val;
            new_node = tree.recursiveSearch(tree.root, val);
            if (new_node != NULL){
                cout << "Node found: " << new_node->value << endl;
            }
            else{
                cout << "Node not found" << endl;
            }
            cout << endl;
            break;

        case 3:
            cout << "DELETE a node" << endl;
            cout << "Enter value of a node to DELETE in AVL Tree: ";
            cin >> val;
            new_node = tree.recursiveSearch(tree.root, val);
            if (new_node != NULL){
                tree.deleteNode(tree.root, val);
                cout << "Node deleted: " << new_node->value << endl;
            }
            else{
                cout << "Node not found" << endl;
            }
            cout << endl;
            break;

        case 4:
            cout << "PRINT the AVL Tree" << endl;
            tree.printTree(tree.root, 0);
            cout << "Preorder: ";
            tree.preorder(tree.root);
            cout << endl;
            cout << "Inorder: ";
            tree.inorder(tree.root);
            cout << endl;
            cout << "Postorder: ";
            tree.postorder(tree.root);
            cout << endl;
            cout << "Level Order: ";
            tree.printLevelOrder(tree.root);
            cout << endl;
            cout << endl;
            break;

        case 5:
            cout << "HEIGHT of the AVL Tree" << endl;
            cout << "Height of the AVL Tree is: " << tree.height(tree.root) << endl;
            cout << endl;
            break;
        
        case 6:
            system("cls");
            break;
        default:
        cout << "Enter a valid option" << endl;
        }
        }
        while (option != 0);
        return 0;
    }



