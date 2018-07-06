#include "Binary_Tree_Node.h"




template<class T>
Binary_Tree_Node<T>::Binary_Tree_Node
(T d, Binary_Tree_Node<T>* left, Binary_Tree_Node<T>* right, Binary_Tree_Node<T>* parent,bool left_child,bool right_child)
	:data_(d),left_(left),right_(right),parent_(parent)
{
 	if ((left_child && right_child) || left_child)
		parent->set_left(this); //ignore the right_child ->left is higher priority than right
	else if (right_child)
		parent->set_right(this);
}

template <class T>
Binary_Tree_Node<T>::~Binary_Tree_Node()
{
	data_ = 0;
	left_ = NULL; delete left_;
	right_ = NULL; delete right_;
	parent_ = NULL; delete parent_;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::get_left()
{
	return this->left_;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::get_right()
{
	return this->right_;
}

template<class T>
void Binary_Tree_Node<T>::set_left(T d)
{
	Binary_Tree_Node<T> * new_node= new Binary_Tree_Node<T>(d,NULL,NULL,this,true);
}

template<class T>
void Binary_Tree_Node<T>::set_left(Binary_Tree_Node<T>* BTN_ptr)
{
	this->left_ = BTN_ptr;
	BTN_ptr->parent_ = this;
}

template<class T>
void Binary_Tree_Node<T>::set_right(T d)
{
	Binary_Tree_Node<T> * new_node = new Binary_Tree_Node<T>(d,NULL,NULL,this,false,true);
	this->right_ = new_node;
	new_node->parent_ = this;
}

template<class T>
void Binary_Tree_Node<T>::set_right(Binary_Tree_Node<T>* BTN_ptr)
{
	this->right_ = BTN_ptr;
	BTN_ptr->parent_ = this;
}

template<class T>
T Binary_Tree_Node<T>::get_data()
{
	return this->data_;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::get_parent()
{
	return this->parent_;
}

template<class T>
void Binary_Tree_Node<T>::set_data(T d)
{
	this->data_ = d;
}

template<class T>
bool Binary_Tree_Node<T>::is_leaf()
{
	return (this->right_==NULL&&this->left_==NULL);
}

template<class T>
bool Binary_Tree_Node<T>::is_root()
{
	return this->parent_==NULL;
}

template<class T>
bool Binary_Tree_Node<T>::is_left()
{
	bool result=false;
	if (this->parent_ != NULL && this->parent_->left_ == this)
		result = true;
	return result;
}

template<class T>
bool Binary_Tree_Node<T>::is_right()
{
	bool result = false;
	if (this->parent_ != NULL && this->parent_->right_ == this)
		result = true;
	return result;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::LeftMostOfRightSubTree()
{
	Binary_Tree_Node<T> * leftmostrightsubtree = this->right_;
	while (leftmostrightsubtree->left_ != NULL)
		leftmostrightsubtree = leftmostrightsubtree->left_;
	return leftmostrightsubtree;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::RightMostOfLeftSubTree()
{
	Binary_Tree_Node<T> * rightmostleftsubtree = this->left_;
	while (rightmostleftsubtree->right_ != NULL)
		rightmostleftsubtree = rightmostleftsubtree->right_;
	return rightmostleftsubtree;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::InOrderSuccessor()
{
	if (this->right_ != NULL)
		return this->LeftMostOfRightSubTree();
	Binary_Tree_Node<T> *me = this;
	Binary_Tree_Node<T> *my_parent = this->parent_;
	while (my_parent != NULL && me->is_right())
	{
		me = my_parent;
		my_parent = my_parent->parent_;
	}
	return my_parent;
}

template<class T>
Binary_Tree_Node<T>* Binary_Tree_Node<T>::PostOrderSuccessor()
{
	Binary_Tree_Node<int> *me = this;
	Binary_Tree_Node<int> *my_parent = this->parent_;
	if (me->is_left())
	{
		if (my_parent->right_ != NULL)
		{
			Binary_Tree_Node<int> *p_o_s = my_parent->LeftMostOfRightSubTree();
			while (p_o_s == my_parent->right_ && !p_o_s->is_leaf())
			{
				p_o_s = p_o_s->LeftMostOfRightSubTree();
			}
			return p_o_s;
		}
		else
			return my_parent;
	}
	else if (me->is_right())
	{
		return my_parent;
	}
}
