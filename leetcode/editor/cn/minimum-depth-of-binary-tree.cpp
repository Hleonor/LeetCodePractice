/**
给定一个二叉树，找出其最小深度。 

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 

 说明：叶子节点是指没有子节点的节点。 

 

 示例 1： 
 
 
输入：root = [3,9,20,null,null,15,7]
输出：2
 

 示例 2： 

 
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

 

 提示： 

 
 树中节点数的范围在 [0, 10⁵] 内 
 -1000 <= Node.val <= 1000 
 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 898 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int dep = 0;
        // 广度优先做法，找到第一个叶子即为最小深度
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            dep++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                if (node->left == NULL && node->right == NULL)
                {
                    return dep;
                }
            }
        }
        return dep;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};
    
    cout<<"Hello LeetCode"<<endl;
}
