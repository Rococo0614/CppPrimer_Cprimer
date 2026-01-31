//与指定位置一样，组内反转依旧使用头插法，且反转次数为k-1，注意头一组的第一个反转后是下一组的头节点
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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(!head || k <= 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        int groupsnum = cnt / k;
        ListNode* prev = dummy;
        ListNode* curr = head;
        for(int i = 0; i < groupsnum; i++){
            ListNode* groupfirst = curr;
            for(int j = 0; j < k - 1; j++){
                ListNode* next = curr -> next;
                curr -> next = next -> next;
                next -> next = prev -> next;
                prev -> next = next;
            }
            prev = groupfirst;
            curr = groupfirst -> next;
        }
        return dummy -> next;
    }
};
