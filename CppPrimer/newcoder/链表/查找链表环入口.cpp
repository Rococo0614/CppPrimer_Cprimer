//在确定有环后，快慢指针相遇点到环入口点的距离等于头节点到环入口点的距离
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(!pHead || !pHead->next) return nullptr;

        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                ListNode* ptr1 = pHead;
                ListNode* ptr2 = fast;

                while(ptr1 != ptr2){
                    ptr1 = ptr1 -> next;
                    ptr2 = ptr2 -> next;
                }
                return ptr1;
            }
        }
        return nullptr;

    }
};