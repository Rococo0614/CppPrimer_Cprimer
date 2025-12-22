// 第一个想法就是unordered_map去统计看是否有重复，注意这里的重复应该是看指针节点的重复
// 因为有很大可能值相等但是节点不同，这算两个不同的listNode单元
// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         if(head->next = nullptr || head = nullptr) return false;
//         }
//         unordered_set<ListNode*> visit;
//         ListNode* temp = head;
//         while (temp->next != nullptr) {
//             if (visit.count(temp)) {
//                 return true;
//             }
//             visit.insert(temp);
//         }
//         return false;
//     }
// };
//第二种方法是flyod快慢指针，就跟龟兔赛跑一样，如果有环那么一定会在某个时间点快指针套圈慢指针
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};