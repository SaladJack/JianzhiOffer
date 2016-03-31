#include <iostream>
using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL && pHead2 == NULL) return NULL;
		if (pHead1 == NULL || pHead2 == NULL) return pHead1 == NULL ? pHead2 : pHead1;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode* pHead = NULL;
		if (p1->val <= p2->val){
			pHead = p1;
			p1->next = Merge(p1->next, p2);
		}
		else{
			pHead = p2;
			p2->next = Merge(p1, p2->next);
		}
		return pHead;
	}
};