#include "Tree_Node.h"
#include <stdarg.h>
#include <list>

using namespace std;

template<class datatype>
Tree_Node<datatype>::Tree_Node(datatype d , Tree_Node<datatype> *parent ) 
{
	data_ = d;
	parent_ = parent;
	if(parent!=NULL)
		parent_->add_child(this);
}


template <class datatype>
Tree_Node<datatype>::~Tree_Node()
{
	data_ = 0;
	parent_ = NULL;
	delete parent_;
	children_.clear();
}

template<class datatype>
void Tree_Node<datatype>::set_parent(Tree_Node<datatype>* parent)
{
	/*if (parent != NULL) 
	{
		this->parent_ = parent;
		parent->add_child(this);
	}*/
	this->parent_ = parent;
	parent_->add_child(this);
}

template<class datatype>
Tree_Node<datatype> Tree_Node<datatype>::getparent()
{
	return this->parent_;
}

template<class datatype>
void Tree_Node<datatype>::add_child(Tree_Node<datatype>* child)
{
	child->parent_ = this;
	this->children_.push_back(child);
}

template<class datatype>
void Tree_Node<datatype>::add_children(int ch_no, ...)
{
	va_list ap;
	va_start(ap, ch_no);
	for (int i = 0; i < ch_no; i++)
	{
		//Tree_Node<datatype> *node = new Tree_Node<datatype>();
		Tree_Node<datatype> *node = va_arg(ap, Tree_Node<datatype>*);
		node->set_parent(this);
	}
	va_end(ap);
}

template<class datatype>
void Tree_Node<datatype>::add_children(list<Tree_Node<datatype>*> children)
{
	typename list<Tree_Node<datatype>*>::iterator i; //typename is necessary
	for (i = children.begin(); i != children.end(); i++)
	{
		this->add_child(*i);
	}
}

template<class datatype>
void Tree_Node<datatype>::add_child(datatype d)
{
	Tree_Node<datatype> *child = new Tree_Node<datatype>(d);
	/*child->set_parent(this);
	this->add_child(child);*/
	child->parent_ = this;
	this->children_.push_back(child);
}

template<class datatype>
datatype Tree_Node<datatype>::get_data()
{
	return this->data_;
}

template<class datatype>
void Tree_Node<datatype>::set_data(datatype d)
{
	this->data_ = d;
}

template<class datatype>
bool Tree_Node<datatype>::is_leaf()
{
	return this->children_.size()==0;
}

template<class datatype>
bool Tree_Node<datatype>::is_root()
{
	return this->parent_ == NULL;
}

template<class datatype>
void Tree_Node<datatype>::remove_parent()
{
	this->parent_ = NULL;
	delete parent_;
}

template<class datatype>
void Tree_Node<datatype>::operator=(Tree_Node<datatype>* right_side)
{
	this->data_ = right_side->data_;
	this->parent_ = right_side->parent_;
	this->children_ = right_side->children_;
}


