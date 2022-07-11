/**
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 * 
 */


#include "vector"
#include "deque"
#include "cassert"

using namespace std;

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
        {
            return ret;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(dq.size() > 0)
        {
            int size = dq.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = dq[0];
                dq.pop_front();
                if(i == size - 1)
                {
                    ret.push_back(node->val);
                }
                if(node->left != nullptr)
                {
                    dq.push_back(node->left);
                }
                if(node->right != nullptr)
                {
                    dq.push_back(node->right);
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution s;
    vector<int> result = s.rightSideView(new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4))));
    vector<int> expected = {1,3,4};
    assert(expected == result);
    return 0;
}