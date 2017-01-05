#include<iostream>
using namespace std;

typedef struct node node;
struct node {
	int value;
	node* next;
};

class list {
	node* head;
public:
	list(){
		this->head = NULL;
	}
	
	void insert(int n){
		if(this->head == NULL){
			this->head = new node;
			this->head->value = n;
			this->head->next = NULL;
		}
		else{
			node* p = this->head;
			while(p->next!=NULL)
				p = p->next;
			p->next = new node;
			p = p->next;
			p->value = n;
			p->next = NULL;
		}
	}

	node* partition_list(int x){
		node *lhead = NULL, *hhead = NULL, *p = this->head, *lp = NULL, *hp = NULL;
		while(p != NULL){
			if(p->value < x){
				if(lp == NULL){
					lhead = p;
					lp = p;
				}
				else{
					lp = lp->next;
				}
				p = p->next;
			}
			else{
				if(hp == NULL){
					hhead = p;
					hp = p;
				}
				else{
					hp->next = p;
					hp = hp->next;
				}
				lp->next = p->next;
				p->next = NULL;
				p = lp->next;
			}
		}
		lp->next = hhead;
		return this->head;
	}

	void print(){
		node* p = this->head;
		while(p != NULL){
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	list l;
	int n, e;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> e;
		l.insert(e);
	}
	int x;
	cin >> x;
	l.print();
	l.partition_list(x);
	l.print();
	return 0;
}
