// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

void post(TreeNode* root, vector<int>&ans)
{
    if(root!=NULL)
    {
        post(root->left,ans);
        post(root->right,ans);
        ans.push_back(root->val);
    }

    // // or can do as below
    // if(!root) return;
    // post(root->left,ans);
    // post(root->right,ans);
    // ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector <int>ans;
    
    post(root,ans);
    
    return ans;
}
