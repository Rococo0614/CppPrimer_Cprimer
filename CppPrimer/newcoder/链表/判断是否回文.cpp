//判断回文的稍微有点操作的做法，先找到中点，然后反转后半部分，再比较两半，最后恢复链表
class Solution {
public:
    bool isPail(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. 快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. 反转后半部分
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;  // 保存以便恢复
        
        // 3. 比较两半
        bool result = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // 4. 恢复链表（如果需要保持原链表）
        reverseList(secondHalfCopy);
        
        return result;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};