#ifndef NODE_FOR_BST_HPP
#define NODE_FOR_BST_HPP

template<typename T>
struct node{
	T key;
//	T value;
	node<T> *left;
	node<T> *right;
	node(T k):key(k),left(nullptr),right(nullptr){}
	node() = default;
	bool operator<(const node<T>& rhs){
		return (key < rhs.key);
	}
};
#endif
