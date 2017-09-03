#include<iostream>
#include<vector>
using namespace std;

class Kstacks {
	public:
		Kstacks(int size, int num_stacks);
		bool push(int val, int stack);
		int top(int stack_no);
		bool pop(int stack_no);
		void print();

		vector<int> arr, nav, stacks;
		int vacant;	
};

Kstacks::Kstacks(int size, int num_stacks): arr(size), nav(size), stacks(num_stacks, -1) {
	vacant = 0;
	for(int i=0; i<size; i++)
		nav[i] = i+1;
}

bool Kstacks::push(int val, int stack_no) {
	if(vacant == arr.size())
		return false;
	arr[vacant] = val;
	int next = nav[vacant];
	nav[vacant] = stacks[stack_no];
	stacks[stack_no] = vacant;
	vacant = next;
	return true;
}

int Kstacks::top(int stack_no) {
	// do something
}

bool Kstacks::pop(int stack_no) {
	if(stacks[stack_no] < 0)
		return false;
	int top = stacks[stack_no];
	stacks[stack_no] = nav[top];
	nav[top] = vacant;
	vacant = top;
	return true;
}

void Kstacks::print() {
	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	Kstacks ks(10, 4);
	ks.push(5, 2);
	ks.push(20, 2);
	ks.push(6, 1);
	ks.push(4, 0);
	ks.push(7, 1);
	ks.push(9, 1);
	ks.push(8, 0);

	ks.print();

	return 0;
}
