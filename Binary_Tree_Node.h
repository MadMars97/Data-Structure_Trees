#pragma once


template <class T>
class Binary_Tree_Node
{
public:
	Binary_Tree_Node(T d=0, Binary_Tree_Node<T> *left=NULL, Binary_Tree_Node<T> *right =NULL, Binary_Tree_Node<T> *parent=NULL, bool left_child=false, bool right_child=false);
	~Binary_Tree_Node();
	Binary_Tree_Node<T> *get_left();
	Binary_Tree_Node<T> *get_right();
	void set_left(T d);
	void set_left(Binary_Tree_Node<T> *BTN_ptr);
	void set_right(T d);
	void set_right(Binary_Tree_Node<T> *BTN_ptr);
	T get_data();
	Binary_Tree_Node<T> *get_parent();
	void set_data(T d);
	bool is_leaf();
	bool is_root();
	bool is_left();
	bool is_right();
	Binary_Tree_Node<T> * LeftMostOfRightSubTree();
	Binary_Tree_Node<T> * RightMostOfLeftSubTree();
	Binary_Tree_Node<T> * InOrderSuccessor();
	Binary_Tree_Node<T> * InOrderpredecessor();
	Binary_Tree_Node<T> * PreOrderSuccessor();
	Binary_Tree_Node<T> * PreOrderpredecessor();
	Binary_Tree_Node<T> * PostOrderSuccessor();
	Binary_Tree_Node<T> * PostOrderpredecessor();
private:
	T data_;
	Binary_Tree_Node<T> *left_;
	Binary_Tree_Node<T> *right_;
	Binary_Tree_Node<T> *parent_;
};

