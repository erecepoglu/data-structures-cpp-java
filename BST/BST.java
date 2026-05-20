import java.util.*;

/**
 * A Generic Binary Search Tree.
 * T must implement Comparable to allow for <, >, and == logic via compareTo().
 */
public class BST<T extends Comparable<T>> {

    private class Node {
        T data;
        Node left, right;

        Node(T data) {
            this.data = data;
            this.left = this.right = null;
        }
    }

    private Node root;

    public BST() {
        this.root = null;
    }

    // =========================================================
    // 1. INSERTION
    // =========================================================

    /**
     * RECURSIVE INSERT: 
     * Breaks the problem down by moving to the left or right subtree
     * until a null spot (leaf) is found.
     */
    public void insertRecursive(T data) {
        root = addRecursive(root, data);
    }

    private Node addRecursive(Node current, T data) {
        if (current == null) {
            return new Node(data);
        }

        int cmp = data.compareTo(current.data);
        if (cmp < 0) {
            current.left = addRecursive(current.left, data);
        } else if (cmp > 0) {
            current.right = addRecursive(current.right, data);
        }
        // If cmp == 0, it's a duplicate; we do nothing.
        return current;
    }

    /**
     * ITERATIVE INSERT:
     * Uses a while loop to traverse down. We must keep track of the 
     * 'parent' node because once 'curr' becomes null, we lose the link.
     */
    public void insertIterative(T data) {
        Node newNode = new Node(data);
        if (root == null) {
            root = newNode;
            return;
        }

        Node curr = root;
        Node parent = null;

        while (curr != null) {
            parent = curr;
            int cmp = data.compareTo(curr.data);
            if (cmp < 0) curr = curr.left;
            else if (cmp > 0) curr = curr.right;
            else return; // Duplicate found
        }

        // Link the new node to the parent
        if (data.compareTo(parent.data) < 0) parent.left = newNode;
        else parent.right = newNode;
    }

    // =========================================================
    // 2. SEARCH
    // =========================================================

    /**
     * RECURSIVE SEARCH:
     * Returns true if the element exists in the tree.
     */
    public boolean searchRecursive(T data) {
        return findRecursive(root, data);
    }

    private boolean findRecursive(Node current, T data) {
        if (current == null) return false;
        int cmp = data.compareTo(current.data);
        if (cmp == 0) return true;
        return cmp < 0 ? findRecursive(current.left, data) : findRecursive(current.right, data);
    }

    /**
     * ITERATIVE SEARCH:
     * More memory efficient as it doesn't add frames to the call stack.
     */
    public boolean searchIterative(T data) {
        Node curr = root;
        while (curr != null) {
            int cmp = data.compareTo(curr.data);
            if (cmp == 0) return true;
            curr = (cmp < 0) ? curr.left : curr.right;
        }
        return false;
    }

    // =========================================================
    // 3. DELETION
    // =========================================================

    /**
     * RECURSIVE DELETION:
     * Handles 3 Cases:
     * 1. Node is a leaf (0 children).
     * 2. Node has only one child.
     * 3. Node has two children (requires finding the Inorder Successor).
     */
    public void deleteRecursive(T data) {
        root = removeRecursive(root, data);
    }

    private Node removeRecursive(Node current, T data) {
        if (current == null) return null;

        int cmp = data.compareTo(current.data);
        if (cmp < 0) {
            current.left = removeRecursive(current.left, data);
        } else if (cmp > 0) {
            current.right = removeRecursive(current.right, data);
        } else {
            // Node found! 
            // Case 1 & 2: 0 or 1 child
            if (current.left == null) return current.right;
            if (current.right == null) return current.left;

            // Case 3: 2 children
            // Find the smallest value in the right subtree (successor)
            current.data = getMin(current.right);
            // Delete the successor node
            current.right = removeRecursive(current.right, current.data);
        }
        return current;
    }

    private T getMin(Node n) {
        T minVal = n.data;
        while (n.left != null) {
            n = n.left;
            minVal = n.data;
        }
        return minVal;
    }

    /**
     * ITERATIVE DELETION:
     * Significantly more complex because we must manually manage parent pointers
     * and correctly re-link the tree after removing a node.
     */
    public void deleteIterative(T data) {
        Node curr = root;
        Node parent = null;

        // 1. Locate the node and its parent
        while (curr != null && !curr.data.equals(data)) {
            parent = curr;
            curr = (data.compareTo(curr.data) < 0) ? curr.left : curr.right;
        }

        if (curr == null) return; // Node not found

        // 2. Handle Case 3 (Two Children)
        // We replace curr's data with the successor's data, then delete the successor node.
        if (curr.left != null && curr.right != null) {
            Node succParent = curr;
            Node succ = curr.right;
            while (succ.left != null) {
                succParent = succ;
                succ = succ.left;
            }
            curr.data = succ.data; // Swap data
            curr = succ;           // Move target to the successor
            parent = succParent;   // Successor's parent for deletion
        }

        // 3. Handle Case 1 & 2 (0 or 1 child)
        Node child = (curr.left != null) ? curr.left : curr.right;

        if (parent == null) {
            root = child; // Deleting the root
        } else if (parent.left == curr) {
            parent.left = child;
        } else {
            parent.right = child;
        }
    }
    public static void main(String[] args) {
        BST<Integer> tree = new BST<>();
        int[] vals = {50, 30, 20, 40, 70, 60, 80};
        for (int v : vals) tree.insertIterative(v);

        System.out.print("Java Iterative Inorder: ");

        System.out.println("Deleting 70 (Node with children):");
        tree.deleteIterative(70);
    }
}