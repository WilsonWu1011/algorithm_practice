#include <iostream>
#include <stack>
#include <string>
#include "node.hpp"
using namespace std;

template<typename T>
class binary_search_tree{
private:
	node<T>* root;
	bool insert_(node<T>*& subTree,const T& item);
	void midTraverse_(ostream& out,node<T>* subTree);
	bool remove_(node<T>*& subTree,const T& item);
public:	
	binary_search_tree():root(nullptr){
		//if(!createTree_(root)){
		//	std::cout << "Constructing Failure!" << endl;	
		//}
	}
	void midTraverse(ostream& out){
		midTraverse_(out,root);
	}
	bool insert(const T& item){
		return insert_(root,item);
	}
	bool remove(const T& item){
		return remove_(root,item);
	}	
};

template<typename T>
void binary_search_tree<T>::midTraverse_(ostream& out,node<T>* subTree)
{
	if(subTree != nullptr){
		midTraverse_(out,subTree->left);
		out << subTree->key << " ";
		midTraverse_(out,subTree->right);
	}
}
template<typename T>
bool binary_search_tree<T>::insert_(node<T>*& subTree,const T& item)
{
	if(subTree == nullptr){
		subTree = new node<T>(item);
		if(subTree == nullptr){
			cout << "Construct Failure!" << endl;
			return false;
		}
		return true;
	}
	else{
		if(item < subTree->key)
			insert_(subTree->left,item);
		else if(subTree->key < item)
			insert_(subTree->right,item);
		else
			return true;
	}
}
template<typename T>
bool binary_search_tree<T>::remove_(node<T>*& subTree,const T& item)
{
	node<T>* temp;
	if(subTree != nullptr){
		if(item < subTree->key)
			remove_(subTree->left,item);
		else if(subTree->key < item)
			remove_(subTree->right,item);
		else{
			//Node<T>* temp;
			if(subTree->left != nullptr && subTree->right != nullptr){
				temp = subTree->right;
				while(temp->left != nullptr)
					temp = temp->left;
				subTree->key = temp->key;
				remove_(subTree->right,subTree->key);		
			}
			else{
				temp = subTree;
				if(subTree->left == nullptr)
					subTree = subTree->right;
				else
					subTree = subTree->left;
				delete temp;
				return true;
			}
		}	
	}
	return false;
}
int main()
{
	binary_search_tree<int> tree;
	int array[] = {53,17,78,9,45,65,87,23};
	for(int i = 0;i < 8;i++){
		tree.insert(array[i]);
	}
	tree.midTraverse(std::cout);
	cout << endl;
	tree.remove(78);
	tree.midTraverse(std::cout);
	return 0;
}
