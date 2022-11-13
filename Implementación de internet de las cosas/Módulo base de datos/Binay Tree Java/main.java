package BinaryTree;

public class main {

    public static void main(String args[]){

        BinaryTree tree = new BinaryTree();

        tree.insert(5);
        tree.insert(3); 
        tree.insert(7);

        tree.inorden(tree.root);
    }
    
}
