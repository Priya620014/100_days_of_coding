/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)
        {
            return root;
        }
        TreeNode* left= lowestCommonAncestor(root->left,  p, q);
        TreeNode* right=lowestCommonAncestor( root->right,  p, q);

        if(left&&right)
        {
            return root;
        }
        else if(left)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    // bool findPath(TreeNode* root,TreeNode* node,vector<TreeNode*>& path)
    // {
    //     //base case
    //     if(root==node)
    //     {
    //         path.push_back(root);
    //         return true;
    //     }
    //     if(!root)
    //     {
    //         return false;
    //     }
    //     path.push_back(root);
    //     if(findPath(root->left,node,path)) return true;
    //       if(findPath(root->right,node,path)) return true;
    //       path.pop_back();
    //       return false;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root)
    //     return NULL;
    //     vector<TreeNode*> path1,path2;
    //     findPath(root,p,path1);
    //     findPath(root,q,path2);
    //     for(int i=min(path1.size(),path2.size())-1;i>=0;i--)
    //     {
    //         if(path1[i]==path2[i])
    //         {
    //             return path1[i];
    //         }
    //     }
    //     return NULL;
    // }

};