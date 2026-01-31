//最巧的办法，双指针，他俩路程相等时一定在交点处或者nullptr处相遇
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if(!pHead1 || !pHead2) return nullptr;
		ListNode* pA = pHead1;
		ListNode* pB = pHead2;

		while(pA != pB){
			pA = (pA == nullptr) ? pHead2 : pA -> next;
			pB = (pB == nullptr) ? pHead1 : pB -> next;
		}
		return pA;
        
    }
};
