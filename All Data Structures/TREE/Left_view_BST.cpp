//BST left view printing in OOP
//C++ implementation

//---------Methodology----------------//
//In the left view they all contain the first node in their levels
#include <iostream> 
using namespace std; 

class BST 
{ 
	public:
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor and definition
    BST(){
    	data = 0;
    	left = NULL;
    	right = NULL;
	}
      
    // Parameterized constructor and definition 
    BST(int value){
    	data = value; 
    	left = right = NULL; 
	}
      
    // Insert function. 
    BST* Insert(BST *, int); 
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 

// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
    if(!root) 
    { 
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
       
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        root->left = Insert(root->left, value); 
    } 
      
    return root; 
} 

void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    
    Inorder(root->left); 
    cout << root->data <<" "; 
    Inorder(root->right); 
} 

int search(BST *root, int key) 
{ 
    // Base Cases: root is null or node's value is present at root 
    if (root == NULL || root->data == key) 
       return 1; 
     
    // value of the node is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // value of the node is smaller than root's key 
    return search(root->left, key); 
} 
  
// Recursive function to print left view of a binary tree. 
void leftViewUtil(BST* root, int level, int *max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout <<root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recursive for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
//Mother function of LeftViewUtil 
void leftView(BST* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 

int main() 
{ 
    BST b, *root = NULL; 
    //inserting the given nodes to the tree
    root = b.Insert(root,1); 
    b.Insert(root, 2); 
    b.Insert(root, 3); 
    b.Insert(root, 4); 
    b.Insert(root, 5); 
	b.Insert(root, 6);
    b.Insert(root, 7);
    b.Insert(root, 8);
  

	//Left view
	cout<<"\nLeft view printing"<<endl;
	leftView(root);
	
    return 0; 
} 
 
