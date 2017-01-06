class Solution {
	public:
		ListNode* mergeLists(ListNode* head1, ListNode* head2) {
			if(head1 == NULL && head2 == NULL)
				return NULL;
			if(head2 == NULL)
				return head1;
			if(head1 == NULL)
				return head2;
			ListNode *head=NULL, *prev=NULL, *p1=NULL, *p2=NULL;
			if(head1->val <= head2->val) {
				head = head1;
				prev = head1;
				p1 = head1->next;
				p2 = head2;
			}
			else {
				head = head2;
				prev = head2;
				p1 = head1;
				p2 = head2->next;
			}
			while(p1 != NULL && p2 != NULL) {
				if(p1->val <= p2->val) {
					prev->next = p1;
					prev = p1;
					p1 = p1->next;
				}
				else {
					prev->next = p2;
					prev = p2;
					p2 = p2->next;
				}
			}
			if(p1 != NULL)
				prev->next = p1;
			else
				prev->next = p2;
			return head;
		}
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if(lists.size() == 0)
				return NULL:
			unsigned long int k = lists.size();
			unsigned long int pow2 = 1;
			while(pow2 < k) {
				for(unsigned long int i=0; i<k; i+=(2*pow2)) {
					if(i+pow2 < k)
						lists[i] = mergeLists(lists[i], lists[i+pow2]);
				}
				pow2 *= 2;
			}
			return lists[0];
		}
};
