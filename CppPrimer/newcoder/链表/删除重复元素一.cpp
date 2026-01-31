//因为第一个保留，相对简单
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* curr = head;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // 发现重复，删除下一个节点
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;  // 如果要释放内存
            } else {
                // 不重复，移动到下一个节点
                curr = curr->next;
            }
        }
        
        return head;
    }
};