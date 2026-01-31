//这道题注意的基础点就是比数值大小->val,同时while(pHead1 && pHead2)比while(temp)更高效
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
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2 -> val){
                temp -> next = pHead1;
                pHead1 = pHead1 -> next;
            }else{
                temp -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            temp = temp -> next;
        }
        temp -> next = pHead1 ? pHead1 : pHead2;
        return dummy -> next;
    }
};