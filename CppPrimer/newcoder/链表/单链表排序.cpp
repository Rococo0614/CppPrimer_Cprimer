//最小堆排序链表
class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // 最小堆
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // 小顶堆
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // 所有节点入堆
        ListNode* curr = head;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }
        
        // 出堆重建链表
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            tail->next = nullptr;  // 断开原链表连接
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};