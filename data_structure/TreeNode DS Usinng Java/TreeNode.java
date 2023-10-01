// Define a class for a binary tree node
class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

// Define a class for the Binary Search Tree
class BinarySearchTree {
    TreeNode root;

    public BinarySearchTree() {
        root = null;
    }

    // Function to insert a value into the BST
    public void insert(int data) {
        root = insertRec(root, data);
    }

    // Helper function to recursively insert a value into the BST
    private TreeNode insertRec(TreeNode root, int data) {
        if (root == null) {
            root = new TreeNode(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        return root;
    }

    // Function to perform an in-order traversal of the BST
    public void inOrderTraversal(TreeNode root) {
        if (root != null) {
            inOrderTraversal(root.left);
            System.out.print(root.data + " ");
            inOrderTraversal(root.right);
        }
    }

    // Function to search for a value in the BST
    public boolean search(int data) {
        return searchRec(root, data);
    }

    // Helper function to recursively search for a value in the BST
    private boolean searchRec(TreeNode root, int data) {
        if (root == null) {
            return false;
        }

        if (data == root.data) {
            return true;
        }

        if (data < root.data) {
            return searchRec(root.left, data);
        }

        return searchRec(root.right, data);
    }
}


