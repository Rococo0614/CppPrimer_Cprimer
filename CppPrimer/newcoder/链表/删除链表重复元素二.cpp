//重复的都删除
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;  // 指向最后一个不重复的节点
        ListNode* curr = head;    // 当前检查的节点
        
        while (curr) {
            // 检查当前节点是否有重复
            bool duplicate = false;
            
            // 跳过所有与当前节点值相同的节点
            while (curr->next && curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }
            
            if (duplicate) {
                // 当前节点是重复的，跳过整个重复序列
                prev->next = curr->next;
            } else {
                // 当前节点不重复，保留
                prev = curr;
            }
            
            curr = curr->next;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};