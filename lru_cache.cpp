#include<iostream>
#include<list>
#include<map>
#include<iterator>
using namespace std;

class Element
{
public:
	int key;
	int value;
	Element(int k, int v)
	{
		this->key = k;
		this->value = v;
	}
};

class LRU 
{
public:
	list<Element> q;
	map<int, list<Element>::iterator > hash;
	int size;

	LRU(int size)
	{
		this->size = size;
	}

	void set(int x, int y)
	{
		// if element already in list then move it to the back of the queue
		if(hash.find(x) != hash.end())
		{
			q.erase(hash[x]);
		}
		// if list (cache size) is full then remove the least recently used element .ie. the element in front of the queue 
		else if(q.size() == this->size)
		{
			hash.erase(hash.find((*(q.begin())).key));
			q.erase(q.begin());
		}

		q.push_back(Element(x,y));
		hash[x] = --q.end();
	}

	int get(int x)
	{
		if(hash.find(x) == hash.end())
			return -1;
		return (*(hash[x])).value;
	}

	void print_cache()
	{
		for(list<Element>::iterator it = q.begin(); it != q.end(); it++)
		{
			cout << (*(it)).value << " ";
		}
		cout << endl;
	}
};

int main()
{
	LRU cache(4);
	cache.set(1,1);
	cache.set(2,2);
	cache.set(3,3);
	cache.print_cache();	
	cache.set(1,1);
	cache.print_cache();	
	cache.set(4,4);
	cache.set(5,5);
	cache.print_cache();	
}
