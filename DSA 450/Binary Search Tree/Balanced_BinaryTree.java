// Leetcode_110
public class Main {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    class Solution {
        public boolean isBalanced(TreeNode node) {
            if (node == null)
                return true;

            if (!isBalanced(node.left))
                return false;
            if (!isBalanced(node.right))
                return false;

            int diff = Math.abs(height(node.left) - height(node.right));
            if (diff > 1)
                return false;
            return true;

        }

        public int height(TreeNode node) {
            if (node == null)
                return -1;

            int left = height(node.left);
            int right = height(node.right);
            return Math.max(left, right) + 1;
        }
    }
}
