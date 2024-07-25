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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
q.push(root);
int cntr=0;
while(!q.empty())
{
	int sz=q.size();
     vector<int> temp;
	while(sz>0)
	{
        sz=sz-1;
	 TreeNode*	f=q.front();
    
		q.pop();
        temp.push_back(f->val);
		//cout<<f->data;
        if(f->left) q.push(f->left);
			if(f->right) q.push(f->right);
		
        
	
	}
    if(cntr%2==1)
    {
        reverse(temp.begin(),temp.end());
    }
    ans.push_back(temp);
	cntr++;
}
return ans;
    }
};