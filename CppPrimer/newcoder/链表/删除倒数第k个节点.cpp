//在找到的基础上删除，这里主要的坑是边界处理，考虑到可能会删第一个，所以需要哨兵，同时需要考虑位置的改变
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = dummy;
        for(int i = 0; i <= n; i++){
            if(!fast) return nullptr;
            fast = fast -> next;
        }
        ListNode* slow = dummy;
        while(fast){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* toDelete = slow -> next;
        slow -> next = slow -> next -> next;
        delete toDelete;
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;

    }
};