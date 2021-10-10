/* reverse level order traversal
link to the question - https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
Given a binary tree of size N, find its reverse level order traversal. 
ie- the traversal must begin from the last level.
*/



vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(root == NULL)
    return ans;
    //vector of vectors to store value level wise
    vector<vector<int>> result;
    Node* curr;
    int count;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0)
    {
        count = q.size();
        for(int i=0; i<count; i++)
        {
            curr = q.front();
            q.pop();
            //saving data to current level
            ans.push_back(curr->data);
            
            if(curr->left!=NULL)
            q.push(curr->left);
            
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        // save the current level
        result.push_back(ans);
        // clearing the vector to save another level values
        ans.clear();
    }
    // reverse the order of levels such that they become traversed
    reverse(result.begin(), result.end());

    //storing values level by level to 1d array
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            ans.push_back(result[i][j]);
        }
    }
    // returning the reverse level order traversal vectors
    return ans;
}