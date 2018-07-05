#include "Tree_Node.h"
#include "Tree_Node.cpp"
#include <iostream>


using namespace std;

int main()
{
	Tree_Node<int> k(5);
	Tree_Node<int> l(3, &k);
	Tree_Node<int> m(4);
	Tree_Node<int> n(6);
	Tree_Node<int> o(1);
	Tree_Node<int> p(2);
	list<Tree_Node<int>*> children;
	children.push_back(&m);
	children.push_back(&n);
	children.push_back(&o);
	children.push_back(&p);
	l.add_children(children);
	//l.add_children(4, &m, &n, &o, &p);
	/*l.add_child(&m);
	l.add_child(&n);
	l.add_child(&o);
	l.add_child(&p);*/
	cout << k.is_leaf() << endl;
	cout << k.is_root() << endl;
	cout << l.is_leaf() << endl;
	cout << l.is_root() << endl;
	cout << m.is_leaf() << endl;
	cout << m.is_root() << endl;
	cout << n.is_leaf() << endl;
	cout << n.is_root() << endl;
	cout << o.is_leaf() << endl;
	cout << o.is_root() << endl;
	//int max_=k.maxof(5, 10, 20, 40, 25, 40);
	//cout << max_;
	getchar();
	return 0;
}