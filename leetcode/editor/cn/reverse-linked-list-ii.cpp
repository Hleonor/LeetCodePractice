/**
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节
点，返回 反转后的链表 。

 

 示例 1： 
 
 
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
 

 示例 2： 

 
输入：head = [5], left = 1, right = 1
输出：[5]
 

 

 提示： 

 
 链表中节点数目为 n 
 1 <= n <= 500 
 -500 <= Node.val <= 500 
 1 <= left <= right <= n 
 

 

 进阶： 你可以使用一趟扫描完成反转吗？ 

 Related Topics 链表 👍 1434 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//struct ListNode{
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode* current = head;
        ListNode* left_bound = head;
        int count = 0;
        for (count = 1; count < left; count++) // 找到left节点
        {
            left_bound = current;
            current = current->next;
        }
        ListNode* prev = current;
        ListNode* right_bound = NULL;
        while (current && count <= right)
        {
            ListNode* next = current->next;
            current->next = prev;
            // 注意下面两行的顺序不能颠倒
            prev = current;
            current = next;
            count++;
            if (count == right) // 最后一次操作
            {
                right_bound = current->next;
            }
        }
        if (left == 1)
        {
            left_bound->next = right_bound;
            return prev;
        }
        else
        {
            left_bound->next->next = right_bound;
            left_bound->next = prev;
            return head;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    ListNode* node6 = new ListNode(6);
//    ListNode* node5 = new ListNode(5, node6);
//    ListNode* node4 = new ListNode(4, node5);
//    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(5, NULL);
    ListNode* node1 = new ListNode(3, node2);
    s.reverseBetween(node1, 1 , 2);
    
    cout<<"Hello LeetCode"<<endl;
}
