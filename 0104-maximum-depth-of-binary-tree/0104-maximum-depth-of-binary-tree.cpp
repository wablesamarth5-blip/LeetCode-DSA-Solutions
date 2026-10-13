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
class Solution {
public:
    int maxdepth=INT_MIN;
    int count;
    int maxDepth(TreeNode* root) {
        
       
        if(root==NULL)
        {
            maxdepth=max(maxdepth,count);
            return count;
        }

         count+=1;
       
       maxDepth(root->left);
       maxDepth(root->right);
       count=count-1;

       return maxdepth;
    }
};