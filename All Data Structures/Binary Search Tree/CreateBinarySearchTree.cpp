#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->val) {
            node->left = insert(node->left, value);
        } else if (value > node->val) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    int kthSmallest(TreeNode* node, int& k) {
        if (node == nullptr) {
            return -1;
        }

        int leftResult = kthSmallest(node->left, k);
        if (k == 0) {
            return leftResult;
        }

        if (k == 1) {
            k--;
            return node->val;
        }

        k--;
        return kthSmallest(node->right, k);
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    int findKthSmallest(int k) {
        return kthSmallest(root, k);
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    int k = 3; // Find the 3rd smallest element
    int result = bst.findKthSmallest(k);

    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;

    return 0;
}
