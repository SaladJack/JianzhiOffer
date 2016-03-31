#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* head, unsigned int k) {
		ListNode* pre = head;
		ListNode* p = head;
		if (head == NULL || k <= 0)
			return NULL;
		while (--k){
			if(p->next!=NULL)
				p = p->next;
			else return NULL;
		}
		while (p->next != NULL){
			p = p->next;
			pre = pre->next;

		}
		return pre;
	}
};