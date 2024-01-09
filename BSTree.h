#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
	int nelem;
	BSNode<T> *root;
	BSNode<T>* search(BSNode<T>* n, T e) const
	{
		if(n == nullptr)
			throw std::runtime_error("No encontrado");
		else
			if(n.elem == e)
				return n;
			else
				if(n.elem > e)
					return search(n->left, e);
				else
					return search(n->right, e);
	}

	BSNode<T>* insert(BSNode<T>* n, T e)
	{
		if(n == nullptr)
			throw std::runtime_error("No encontrado");
		else
			if(n.elem == e)
				throw std::runtime_error("Elemento duplicado");
			else 
				if(n.elem > e)
					n->left = insert(n->left, e);
				else
					n->right = insert(n->right, e);
		return n;
	}

	void print_inorder(std::ostream &out, BSNode<T>* n) const
	{
		if(n != nullptr)
		{
			print_inorder(out, n->left);
			out << n->elem << " ";
			print_inorder(out, n->right);
		}
		else
			out << ".";
	}
    

    public:
	BSTree()
	{
		nelem = 0;
		root = nullptr;
	}

	int size() const
	{
		return nelem;
	}    

	T search(T e) const
	{
		return search(root, e)->elem;
	}

	T operator[](T e) const
	{
		return search(e);
	}

	void insert(T e)
	{
		root = insert(root, e);
		nelem++;
	}
	
	friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst)
	{
		if(bst.root != nullptr)
			bst.print_inorder(out, bst.root);
		return out;
	}
    
};

#endif
