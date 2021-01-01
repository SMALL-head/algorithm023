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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *node1 = l1, *node2 = l2, *rl, *tail;
        
        rl = new ListNode(-1); //构建带头节点的链表
        tail = rl; //尾插法

        while(node1 != nullptr && node2 != nullptr)
        {
            if(node1->val > node2->val)
            {//搬运l1的node
                ListNode *tmp = node2;
                node2 = node2->next;
                tail->next = tmp;
                tail = tail->next;
            }
            else
            {//搬运l2的node
                ListNode *tmp = node1;
                node1 = node1->next;
                tail->next = tmp;
                tail = tail->next;
            }
        }
        tail->next = node1 ? node1 : node2;//搬运剩余的链表
        return rl->next; //跳过头结点
    }
};