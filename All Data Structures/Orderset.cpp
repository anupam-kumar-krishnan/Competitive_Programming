ORDERED SET
Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. It performs all the operations as performed by the set data structure in STL in log(n) complexity and performs two additional operations also in log(n) complexity .

order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).
Required header files to implement ordered set and their description

For implementing ordered_set and GNU C++ library contains other Policy based data structures we need to include :

// Common file
include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
include <ext/pb_ds/tree_policy.hpp>
The first one is used to include the associative containers or group of templates such as set, multimap, map etc.The tree-based data structures which we will be using below is present in this header file.
The second header file is used to include the tree_order_statistics_node update which is explained below:

using namespace __gnu_pbds;
It is a namespace necessary for the GNU based Policy based data structures.

The tree based container has a concrete structure but the necessary structure required for the ordered set implementation is :

tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >
int : It is the type of the data that we want to insert (KEY).It can be integer, float or pair of int etc.
null_type : It is the mapped policy. It is null here to use it as a set.If we want to get map but not the set, as the second argument type must be used mapped type.
less : It is the basis for comparison of two functions.
rb_tree_tag : type of tree used. It is generally Red black trees because it takes log(n) time for insertion and deletion while other take linear time such as splay_tree.
tree_order_statistics_node__update : It is included in tree_policy.hpp and contains various operations for updating the node variants of a tree-based container, so we can keep track of metadata like the number of nodes in a subtree
Additional functions in the ordered set other than the set

Along with the previous operations of the set, it supports two main important operations

find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

Difference between set and ordered set

There is not so much difference between the set and ordered set although ordered set can be assumed as an extended version of set capable of performing some more advanced functions(stated above) that are extensively used in competitive programming.

NOTE : ordered_set is used here as a macro given to tree<int, null_type, less, rb_tree_tag, tree_order_statistics_node_update>. Therefore it can be given any name as macro other than ordered_set but generally in the world of competitive programming it is commonly referred as ordered set as it is a set with additional operations.
Problem link:-(https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree <int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds s;
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; --i)
        {
            ans[i] = s.order_of_key(nums[i]);           
			s.insert(nums[i]);               
        }
        
        return ans;
    }
};