//想法就是反转后相加，记得维护进位，最后再反转回来
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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode* l1 = reverseList(head1);
        ListNode* l2 = reverseList(head2);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;

        }
        ListNode* ans = reverseList(dummy->next);
        delete dummy;
        return ans;
    }
};