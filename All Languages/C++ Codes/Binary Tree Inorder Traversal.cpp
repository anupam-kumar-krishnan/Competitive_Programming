 vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>v;
        TreeNode*curr=root;
        while(true){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }   
            else{
                if(st.empty()) break;
                curr=st.top();
                st.pop();
                v.push_back(curr->val);
                curr=curr->right;
            }
        }
        return v;
    }
