//熟悉头插法提高效率，重点理解，prev始终不变，curr是由于把next往前放才往后走，next则临时且始终保持在curr后一位
//哨兵节点是为了把头节点也转换为普通节点，边界条件处理更方便
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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(!head || m == n) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        for(int i = 1; i < m; i++){
            prev = prev -> next;
        }
        ListNode* curr = prev -> next;
        ListNode* next = nullptr;
        for(int i = m; i < n; i++){
            next = curr -> next;
            curr -> next = next -> next;
            next -> next = prev -> next;
            prev -> next = next;
        }
        return dummy -> next;
    }
};