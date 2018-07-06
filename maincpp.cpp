#include "Tree_Node.h"
#include "Tree_Node.cpp"
#include "Binary_Tree_Node.h"
#include "Binary_Tree_Node.cpp"
#include <iostream>


using namespace std;

void test_tree_node()
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
}

void test_binary_tree_node()
{
	Binary_Tree_Node<int> *root = new Binary_Tree_Node<int>(0);
	Binary_Tree_Node<int> *_1 = new Binary_Tree_Node<int>(1, NULL, NULL, root, true);
	Binary_Tree_Node<int> *_2 = new Binary_Tree_Node<int>(2, NULL, NULL, root, false, true);
	Binary_Tree_Node<int> *_3 = new Binary_Tree_Node<int>(3, NULL, NULL, _1, true);
	Binary_Tree_Node<int> *_4 = new Binary_Tree_Node<int>(4, NULL, NULL, _1, false, true);
	Binary_Tree_Node<int> *_5 = new Binary_Tree_Node<int>(5, NULL, NULL, _2, true);
	Binary_Tree_Node<int> *_6 = new Binary_Tree_Node<int>(6, NULL, NULL, _2, false, true);
	Binary_Tree_Node<int> *_7 = new Binary_Tree_Node<int>(7);
	Binary_Tree_Node<int> *_8 = new Binary_Tree_Node<int>(14);
	_3->set_left(_7);
	_6->set_right(_8);
	_6->set_right(13);
	_7->set_right(16);
	_8->set_left(30);
	cout << root->is_root() << " " << root->is_left() << " " << root->is_right() << " " << root->is_leaf() << endl;
	cout << _1->is_root() << " " << _1->is_left() << " " << _1->is_right() << " " << _1->is_leaf() << endl;
	cout << _2->is_root() << " " << _2->is_left() << " " << _2->is_right() << " " << _2->is_leaf() << endl;
	cout << _3->is_root() << " " << _3->is_left() << " " << _3->is_right() << " " << _3->is_leaf() << endl;
	cout << _4->is_root() << " " << _4->is_left() << " " << _4->is_right() << " " << _4->is_leaf() << endl;
	cout << _5->is_root() << " " << _5->is_left() << " " << _5->is_right() << " " << _5->is_leaf() << endl;
	cout << _6->is_root() << " " << _6->is_left() << " " << _6->is_right() << " " << _6->is_leaf() << endl;
	cout << _7->is_root() << " " << _7->is_left() << " " << _7->is_right() << " " << _7->is_leaf() << endl;
	cout << _8->is_root() << " " << _8->is_left() << " " << _8->is_right() << " " << _8->is_leaf() << endl;
	Binary_Tree_Node<int> *Post_oreder_succ1 = _1->PostOrderSuccessor();
	Binary_Tree_Node<int> *Post_oreder_succ2 = _2->PostOrderSuccessor();
	Binary_Tree_Node<int> *Post_oreder_succ3 = _3->PostOrderSuccessor();
	Binary_Tree_Node<int> *Post_oreder_succ4 = _4->PostOrderSuccessor();
	Binary_Tree_Node<int> *Post_oreder_succ5 = _5->PostOrderSuccessor();
	Binary_Tree_Node<int> *Post_oreder_succ6 = _6->PostOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ7 = _7->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ1 = _1->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ2 = _2->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ3 = _3->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ4 = _4->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ5 = _5->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ6 = _6->InOrderSuccessor();
	Binary_Tree_Node<int> *In_oreder_succ7 = _7->InOrderSuccessor();
}

int main()
{
	test_tree_node();
	test_binary_tree_node();
	getchar();
	return 0;
}
