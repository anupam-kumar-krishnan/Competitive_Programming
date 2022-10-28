/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution 
{
    public Integer prev;
    
    public boolean isValidBST(TreeNode root) 
    {
        if(root!=null)
        {
            boolean l = isValidBST(root.left);
            if(prev != null && prev >= root.val)
                return false;
            prev = root.val;
            boolean r = isValidBST(root.right);
            return l && r;
        }
        return true;
    }
}
