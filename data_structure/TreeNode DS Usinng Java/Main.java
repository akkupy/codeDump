public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        // Insert values into the BST
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);

        // Perform an in-order traversal
        System.out.print("In-order traversal: ");
        bst.inOrderTraversal(bst.root);
        System.out.println();

        // Search for a value in the BST
        int searchValue = 30;
        if (bst.search(searchValue)) {
            System.out.println(searchValue + " found in the BST.");
        } else {
            System.out.println(searchValue + " not found in the BST.");
        }
    }
}