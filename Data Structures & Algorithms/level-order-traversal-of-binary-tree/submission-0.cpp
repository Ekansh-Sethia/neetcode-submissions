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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> out;

        while(!q.empty()){
            TreeNode* fr = q.front();
            q.pop();

            if(fr != NULL){
                int let = fr -> val;
                out.push_back(let);

                if(fr -> left) q.push(fr -> left);
                if(fr -> right) q.push(fr -> right);
            }
            else{
                ans.push_back(out);
                out = {};

                if(!q.empty()) q.push(NULL);
            }
        }
        return ans;
    }
};
