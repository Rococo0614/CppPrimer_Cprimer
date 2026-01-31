//基础思路就是拆分然后合并
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        
        ListNode* odd = head;           // 奇数链表头
        ListNode* even = head->next;    // 偶数链表头
        ListNode* evenHead = even;      // 保存偶数链表头
        
        while (even && even->next) {
            // 连接奇数节点
            odd->next = even->next;
            odd = odd->next;
            
            // 连接偶数节点
            even->next = odd->next;
            even = even->next;
        }
        
        // 合并两个链表
        odd->next = evenHead;
        
        return head;
    }
};