/**

 
 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。 

 
 

 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 

 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
isConnected[i][j] = 0 表示二者不直接相连。 

 返回矩阵中 省份 的数量。 

 

 示例 1： 
 
 
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
 

 示例 2： 
 
 
输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
 

 

 提示： 

 
 1 <= n <= 200 
 n == isConnected.length 
 n == isConnected[i].length 
 isConnected[i][j] 为 1 或 0 
 isConnected[i][i] == 1 
 isConnected[i][j] == isConnected[j][i] 
 

 Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 919 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<int> head;
    vector<int> level;
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cities = isConnected.size();
        head.resize(cities);
        level.resize(cities); // 高度
        for (int i = 0; i < cities; i++)
        {
            head[i] = i;
            level[i] = 1;
        }
        for (int i = 0; i < cities; i++)
        {
            for (int j = i + 1; j < cities; j++) // 从i + 1开始就行，因为不用自己和自己比，而且小于i的都已经比过了
            {
                if (isConnected[i][j])
                {
                    merge(i, j);
                }
            }
        }
        int provinces = 0;
        for (int i = 0; i < cities; i++)
        {
            if (head[i] == i)
            {
                provinces++;
            }
        }
        return provinces;
    }

    void merge(int x, int y) // 修改head向量
    {
        int i = find(x);
        int j = find(y);

        if (i == j)
        {
            return;
        }

        if (level[i] <= level[j]) // 矮的合并到高的
        {
            head[i] = j; // i的父亲设置为j
            if (level[i] == level[j])
            {
                level[j]++;
            }
        }
        else
        {
            head[j] = i;
        }
    }

    int find(int x)
    {
        if (head[x] == x)
        {
            return x;
        }
        return head[x] = find(head[x]); // 压缩
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << s.findCircleNum(isConnected);
}
