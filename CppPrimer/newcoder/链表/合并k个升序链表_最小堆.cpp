//链表的找最小，记住怎么创建ListNode的堆就可以，其他思路一样
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
    struct Compare{
        bool operator()(ListNode *a, ListNode*b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        if(lists.empty()) return nullptr;

        priority_queue<ListNode* , vector<ListNode*>, Compare> min_heap;
        for(auto list : lists){
            if(list) min_heap.push(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (!min_heap.empty()){
            ListNode* minNode = min_heap.top();
            min_heap.pop();

            cur -> next = minNode;
            cur = cur -> next;
            if(minNode -> next){
                min_heap.push(minNode->next);
            }
        }
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};