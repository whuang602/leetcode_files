/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// William Huang | 8833196
#include <vector>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        //declare and initialize vector v holding ints
        vector<int> v;
        
        inorderMakeVector(root, v);
    
        // checks to see if the vector is sorted (least to greatest)
        // if it is, then that means it most likely is a valid bst
        if ( std::is_sorted(v.begin(), v.end()) )
        {
            // however, we have to check to see if there are repeating values
            for ( int i = 0 ; i < v.size() - 1 ; i++ )
            {
                if ( v[i] == v[i+1] )
                    return false;
            }
            
            //if the code hasnt exitted by this point then
            // 1) vector sorted in order
            // 2) vector has no repeated valued
            // which means the tree is a BST
            return true;
        }
        
        return false;
    }

private:
    
    // inspired by inorderTraversal code from lecture 15
    // basically just takes a vector by reference and add node values to it in order
 void inorderMakeVector(TreeNode* node, vector<int> &v){

	if( !node )
        return;	
     
	inorderMakeVector(node->left, v);
    v.push_back(node->val);
	inorderMakeVector(node->right, v);
}
    
    
};