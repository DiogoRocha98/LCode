#include <iostream>
#include <queue>


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        std::queue<TreeNode*> q;
        q.push(root);
        bool xStatus = false, yStatus = false;

        while (!q.empty())
        {
            int size = q.size();
        
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = q.front();
                q.pop();
                // Caso onde os nós são irmãos
                if (curNode->left != NULL && curNode->right != NULL) {
                    if ((curNode->left->val == x && curNode->right->val == y) || 
                        (curNode->left->val == y && curNode->right->val == x))
                         return false;
                }   
                
                if (curNode->left != NULL) {
                    if (curNode->left->val == x)
                        xStatus = true;
                    if (curNode->left->val == y)
                        yStatus = true;
                    q.push(curNode->left);
                }
                
                if (curNode->right != NULL) {
                    if (curNode->right->val == x)
                        xStatus = true;
                    if (curNode->right->val == y)
                        yStatus = true;
                    q.push(curNode->right);
                }  
            }
            if (xStatus && yStatus) return true;
            if (xStatus || yStatus) return false;
        }

        return false;
    }
};