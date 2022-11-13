package BinaryTree;

public class BinaryTree{

    Nodo root;

    BinaryTree(){

    }
}

public void insert(int value){
    if(root == null){
        root = new Nodo(null, null, null, value);
        }
    else{
        if(value < root.value){}
        }
    }   



    public void insertR(Nodo root, int value){
        if(value < root.value){
            if(root.left == null){
                root.left = new Nodo(null, null, root, value);
            }
            else{
                insertR(root.left, value);
            }
        }
        else{
            if(value < root.value){
                if(root.right == null){
                    root.right = new Nodo(null, null, root, value);
                }
                else{
                    insertR(root.right, value);
                }
            }
            else{
                insertR(root.right, value);
            }
        }
    }

    public void inorden(Nodo root){
        if(root != null){
            inorden(root.left);
            System.out.println(root.value);
            inorden(root.right);
        }
    }

    public void inorderR(Nodo root){
        if(root != null){
            inorderR(root.left);
            System.out.println(root.value);
            inorderR(root.right);
        }
    }