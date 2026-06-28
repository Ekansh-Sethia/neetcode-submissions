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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> LOT;
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
                LOT.push_back(out);
                out = {};

                if(!q.empty()) q.push(NULL);
            }
        }
        vector<int> ans;
        for(auto i : LOT){
            int n = i.size();
            ans.push_back(i[n-1]);
        }
        return ans;
    }
};
