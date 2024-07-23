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
    bool symmetry(TreeNode* root1,TreeNode* root2 )
{
     
       if(root1==NULL && root2==NULL)
       {
        return true;
       }
       if(root1==NULL || root2==NULL)
       {
        return false;
       }
       bool ans1= symmetry(root1->left,root2->right);
       bool ans2= symmetry(root1->right,root2->left);
       if(ans1 && ans2 && root1->val==root2->val)
       {
        return true;
       }
      return false;
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
           return true;
        }
        return symmetry(root->left,root->right);
    }
};