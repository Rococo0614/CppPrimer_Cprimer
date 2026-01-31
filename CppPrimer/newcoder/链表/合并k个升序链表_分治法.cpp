//分治法，避免了一个链表被合并多次，从而提高效率
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
     * @param lists ListNode类vector 
     * @return ListNode类
     */
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                temp -> next = l1;
                l1 = l1 -> next;
            }else{
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }
        temp -> next = l1 ? l1 : l2;
        ListNode* result = dummy -> next;
        delete dummy;
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        if(lists.empty()) return nullptr;
        int k = lists.size();
        for(int step = 1; step < k; step *= 2){
            for(int i = 0; i + step < k; i += step * 2){
                lists[i] = mergeLists(lists[i], lists[i + step]);
            }

        }
        return lists[0];

    }
};