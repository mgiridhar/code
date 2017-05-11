/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*** Solution with map **/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *chead = new RandomListNode(head->label);
        RandomListNode *p = head, *cp = chead;
        unordered_map<RandomListNode *, RandomListNode *> hash;
        while(p->next != NULL) {
            cp->next = new RandomListNode(p->next->label);
            hash[p] = cp;
            p = p->next;
            cp = cp->next;
        }
        hash[p] = cp;
        p = head;
        cp = chead;
        while(cp != NULL) {
            if(hash.find(p->random) != hash.end())
                cp->random = hash[p->random];
            cp = cp->next;
            p = p->next;
        }
        return chead;
    }
};

/*** Faster solution without using map ***/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *p = head, *cp;
        while(p != NULL) {
            cp = new RandomListNode(p->label);
            cp->next = p->next;
            p->next = cp;
            p = cp->next;
        }
        p = head;
        while(p != NULL) {
            p->next->random = (p->random != NULL) ? p->random->next : NULL;
            p = p->next->next;
        }
        
        RandomListNode *chead = head->next;
        cp = chead;
        p = head;
        while(p != NULL && cp != NULL) {
            p->next = cp->next;
            cp->next = (p->next == NULL) ? NULL : p->next->next;
            p = p->next;
            cp = cp->next;
        }
        return chead;
    }
};
