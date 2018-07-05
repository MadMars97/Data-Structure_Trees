#pragma once
#include <list>
using namespace std;
template <class datatype>
class Tree_Node
{
public:
	Tree_Node(datatype d=0,Tree_Node<datatype> *parent = NULL);
	~Tree_Node();
	void set_parent(Tree_Node<datatype> *parent);
	Tree_Node<datatype> getparent();
	void add_child(Tree_Node<datatype> *child);
	void add_child(datatype d);
	void add_children(int ch_no, ...);
	void add_children(list<Tree_Node<datatype>*> children);
	datatype get_data();
	void set_data(datatype d);
	bool is_leaf();
	bool is_root();
	void remove_parent();
	void operator =(Tree_Node<datatype> *right_side);
private:
	datatype data_;
	Tree_Node<datatype> *parent_;
	list<Tree_Node<datatype> *>children_;
};
