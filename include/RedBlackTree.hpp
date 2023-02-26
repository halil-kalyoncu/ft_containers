/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:26 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/25 11:42:12 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "RbtNode.hpp"

//allocator
#include <memory>
//less
#include <functional>
//NULL
#include <cstddef>

/*

	RedBlackTree synopsis

	template<typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class RedBlackTree
	{
	public:
		typedef ft::RedBlackTree<T, Compare, Alloc>	tree_type;
		typedef tree_type&							tree_reference;
		typedef const tree_type&					tree_const_reference;
		typedef ft::RbtNode<T, Alloc>				node_type;
		typedef node_type*							node_pointer;
		typedef const node_type*					node_const_pointer;
		typedef std::allocator<node_type>			allocator_type;
		typedef T									value_type;
		typedef value_type&							value_ref;
		typedef const value_type&					value_const_ref;
		typedef Compare								key_compare;

		RedBlackTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		RedBlackTree(tree_const_reference copy);
		~RedBlackTree(void);
		tree_reference		operator=(tree_const_reference rhs);

		node_pointer		getFirstNode(void) const;
		node_pointer		getEnd(void) const;

		node_pointer		insertNode(value_const_ref value);
		bool				deleteNode(value_const_ref value);
		node_pointer		findNode(value_const_ref value_ref) const;

	private:
		node_pointer		_root;
		key_compare			_comp;
		allocator_type		_alloc;
		node_pointer		_end;

		bool				_matchKeys(value_const_ref x, value_const_ref y) const;
		void				_leftRotate(node_pointer node);
		void				_rightRotate(node_pointer node);
		void				_transplant(node_pointer node, node_pointer child);
		void				_updateLeftNode(node_pointer parent, node_pointer child);
		void				_updateRightNode(node_pointer parent, node_pointer child);
		void				_updateChild(node_pointer parent, node_pointer child);
		node_pointer		_insertFindParent(value_const_ref value);
		node_pointer		_insertCreateNewNode(value_const_ref value);
		void				_insertFixup(node_pointer node);
		node_pointer		_insertFixupCases(node_pointer node,
								node_pointer (ft::RbtNode<T, Alloc>::*getNodeDirectionSibling) (void),
								void (ft::RedBlackTree<T, Compare, Alloc>::*rotateDirectionSibling) (node_pointer),
								void (ft::RedBlackTree<T, Compare, Alloc>::*rotateOppositeDirection) (node_pointer));
		void				_deleteFixup(node_pointer node);
		node_pointer		_deleteFixupCases(node_pointer node,
								node_pointer (ft::RbtNode<T, Alloc>::*getNodeDirectionSibling) (void),
								node_pointer (ft::RbtNode<T, Alloc>::*getNodeOppositeDirection) (void),
								void (ft::RedBlackTree<T, Compare, Alloc>::*rotateDirectionSibling) (node_pointer),
								void (ft::RedBlackTree<T, Compare, Alloc>::*rotateOppositeDirection) (node_pointer));
		void				_freeSingleNode(node_pointer node);
		void				_freeNode(node_pointer node);
		node_pointer		_copyNode(node_const_pointer node, node_pointer end);
		static node_pointer	_getMaximum(node_pointer node);

*/

namespace ft
{
	template<typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class RedBlackTree
	{
	public:
		typedef ft::RedBlackTree<T, Compare, Alloc>	tree_type;
		typedef tree_type&							tree_reference;
		typedef const tree_type&					tree_const_reference;
		typedef ft::RbtNode<T, Alloc>				node_type;
		typedef node_type*							node_pointer;
		typedef const node_type*					node_const_pointer;
		typedef std::allocator<node_type>			allocator_type;
		typedef T									value_type;
		typedef value_type&							value_ref;
		typedef const value_type&					value_const_ref;
		typedef Compare								key_compare;

		explicit RedBlackTree(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _root(NULL),
				_comp(comp), _alloc(alloc), _end(NULL)
		{
			node_pointer	end_node = this->_alloc.allocate(1);

			this->_alloc.construct(end_node, node_type());
			this->_end = end_node;
			return ;
		}

		RedBlackTree(tree_const_reference copy) : _root(NULL), _comp(copy._comp),
			_alloc(copy._alloc), _end(NULL)
		{
			node_pointer	end_node = this->_alloc.allocate(1);

			this->_alloc.construct(end_node, node_type());
			this->_end = end_node;
			this->_root = this->_copyNode(copy._root, this->_end);
			this->_end->setParentNode(this->_root);
			return ;
		}

		~RedBlackTree(void)
		{
			this->_freeNode(this->_root);
			this->_freeNode(this->_end);
			return ;
		}

		tree_reference	operator=(tree_const_reference rhs)
		{
			if (this != &rhs) {
				this->_comp = rhs._comp;
				this->_freeNode(this->_root);
				this->_root = this->_copyNode(rhs._root, this->_end);
				this->_end->setParentNode(this->_root);
			}
			return (*this);
		}

		node_pointer	getFirstNode(void) const
		{
			if (this->_root == NULL) {
				return (this->_end);
			}
			return (node_type::lookUpMinimum(this->_root));
		}

		node_pointer	getEnd(void) const
		{
			return (this->_end);
		}

		/*
		- traverse the tree until you find the position
			- this ends on a NIL node, we take the previous node which gives us the parent
				- delete this NIL node
		- create NIL nodes for the new node, set the relationships for the NIL node,
		  the inserted node and the parent node
		- call fixup on the inserted node
		*/
		node_pointer	insertNode(value_const_ref value)
		{
			node_pointer	parent_node = this->_insertFindParent(value);
			node_pointer	insert_node = this->_insertCreateNewNode(value);

			insert_node->setParentNode(parent_node);
			this->_updateChild(parent_node, insert_node);
			this->_insertFixup(insert_node);
			this->_end->setParentNode(this->_root);
			return (insert_node);
		}

		/*
		- if the node, that is going to be deleted, has only one or no child,
		delete the NIL node, replace it with the child (or the other NIL node)
		and call fixup on that node
		- otherwise search for the minimum in the right subtree and replace the node
			- if the minimum is not the child of the delete node, his right subtree
			  takes the place of the minimum
			- call fixup on the right node of minimum
		*/
		bool	deleteNode(value_const_ref value)
		{
			node_pointer	node = this->findNode(value);
			node_pointer	child;
			node_pointer	fixup;
			node_pointer	minimum;
			bool			original_color;

			if (node == this->_end) {
				return (false);
			}
			original_color = node->getColor();
			child = node->getLeftNode();

			if (ft::RbtNode<T, Alloc>::checkNIL(child) == true) {
				fixup = node->getRightNode();
			}
			else {
				child = node->getRightNode();
				fixup = node->getLeftNode();
			}

			if (ft::RbtNode<T, Alloc>::checkNIL(child) == true) {
				this->_freeSingleNode(child);
				this->_transplant(node, fixup);
			}
			else {
				minimum = node_type::lookUpMinimum(node->getRightNode());
				original_color = minimum->getColor();
				fixup = minimum->getRightNode();
				this->_freeSingleNode(minimum->getLeftNode());
				if (minimum->getParentNode() != node) {
					this->_transplant(minimum, minimum->getRightNode());
					this->_updateRightNode(minimum, node->getRightNode());
				}
				this->_transplant(node, minimum);
				this->_updateLeftNode(minimum, node->getLeftNode());
				minimum->setColor(node->getColor());
			}
			this->_freeSingleNode(node);
			if (original_color == COLOR_BLACK) {
				this->_deleteFixup(fixup);
			}
			this->_end->setParentNode(this->_root);
			return (true);
		}

		node_pointer	findNode(value_const_ref value_ref) const
		{
			node_pointer	node = this->_root;

			if (node == NULL) {
				return (this->_end);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				if (this->_matchKeys(value_ref, node->getValue()) == true) {
					return (node);
				}
				if (this->_comp(value_ref, node->getValue()) == true) {
					node = node->getLeftNode();
				}
				else {
					node = node->getRightNode();
				}
			}
			return (this->_end);
		}

		/*
		- we are searching for the node that equals or is the first one after the
		  given value
			-> by saving the node everytime before we go left on the tree, we end
			   up with the smallest possible value that is bigger than the given
			   value
				- except, if we find the value in the tree, then we just return
				  that node
		*/
		node_pointer	findLowerBound(value_const_ref value_ref) const
		{
			node_pointer	lower_bound = this->_end;
			node_pointer	node = this->_root;

			if (node == NULL) {
				return (this->_end);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				if (this->_matchKeys(value_ref, node->getValue()) == true) {
					return (node);
				}
				if (this->_comp(value_ref, node->getValue()) == true) {
					lower_bound = node;
					node = node->getLeftNode();
				}
				else {
					node = node->getRightNode();
				}
			}
			return (lower_bound);
		}

		/*
		- similiar to lower bound but here we don't check for equality, we want 
		  the first one after the given value
		*/
		node_pointer	findUpperBound(value_const_ref value_ref) const
		{
			node_pointer	lower_bound = this->_end;
			node_pointer	node = this->_root;

			if (node == NULL) {
				return (this->_end);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				if (this->_comp(value_ref, node->getValue()) == true) {
					lower_bound = node;
					node = node->getLeftNode();
				}
				else {
					node = node->getRightNode();
				}
			}
			return (lower_bound);
		}

	private:
		node_pointer	_root;
		key_compare		_comp;
		allocator_type	_alloc;
		node_pointer	_end;

		bool	_matchKeys(value_const_ref x, value_const_ref y) const
		{
			return (this->_comp(x, y) == false
					&& this->_comp(y, x) == false);
		}

		/*
		- right child of node -> parent of node
			- update parent of right child
		- right child's (of node) left child -> right child of node
		*/
		void	_leftRotate(node_pointer node)
		{
			node_pointer	rightNode;
			node_pointer	rightNode_leftSubtree;

			if (node == NULL
					|| ft::RbtNode<T, Alloc>::checkNIL(node->getRightNode())) {
				return ;
			}
			rightNode = node->getRightNode();
			rightNode_leftSubtree = rightNode->getLeftNode();

			this->_updateRightNode(node, rightNode_leftSubtree);
			this->_transplant(node, rightNode);
			this->_updateLeftNode(rightNode, node);
			return ;
		}

		void	_rightRotate(node_pointer node)
		{
			node_pointer	leftNode;
			node_pointer	leftNode_rightSubtree;

			if (node == NULL 
					|| ft::RbtNode<T, Alloc>::checkNIL(node->getLeftNode())) {
				return ;
			}
			leftNode = node->getLeftNode();
			leftNode_rightSubtree = leftNode->getRightNode();

			this->_updateLeftNode(node, leftNode_rightSubtree);
			this->_transplant(node, leftNode);
			this->_updateRightNode(leftNode, node);
			return ;
		}

		void	_updateLeftNode(node_pointer parent, node_pointer child)
		{
			parent->setLeftNode(child);
			child->setParentNode(parent);
			return ;
		}

		void	_updateRightNode(node_pointer parent, node_pointer child)
		{
			parent->setRightNode(child);
			child->setParentNode(parent);
			return ;
		}

		/*
		- node is replaced by setting the relationship between node.parent and
		  replace
		*/
		void	_transplant(node_pointer node, node_pointer replace)
		{
			node_pointer	parent_node = node->getParentNode();

			if (parent_node == NULL) {
				this->_root = replace;
			}
			else if (node == parent_node->getLeftNode()) {
				parent_node->setLeftNode(replace);
			}
			else {
				parent_node->setRightNode(replace);
			}
			replace->setParentNode(parent_node);
			return ;
		}

		void	_updateChild(node_pointer parent, node_pointer child)
		{
			node_pointer	old_child;

			if (parent == NULL) {
				this->_root = child;
				return ;
			}
			else if (this->_comp(child->getValue(), parent->getValue()) == true) {
				old_child = parent->getLeftNode();
				parent->setLeftNode(child);
			}
			else {
				old_child = parent->getRightNode();
				parent->setRightNode(child);
			}
			if (ft::RbtNode<T, Alloc>::checkNIL(old_child) == true) {
				this->_freeSingleNode(old_child);
			}
			return ;
		}

		node_pointer	_insertFindParent(value_const_ref value)
		{
			node_pointer	parent_node = NULL;
			node_pointer	node = this->_root;

			if (node == NULL) {
				return (NULL);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				parent_node = node;
				if (this->_comp(value, node->getValue()) == true) {
					node = node->getLeftNode();
				}
				else {
					node = node->getRightNode();
				}
			}
			return (parent_node);
		}

		node_pointer	_insertCreateNewNode(value_const_ref value)
		{
			node_pointer	insert_node = this->_alloc.allocate(1);
			node_pointer	left_nil = this->_alloc.allocate(1);
			node_pointer	right_nil = this->_alloc.allocate(1);

			this->_alloc.construct(insert_node, node_type(value, this->_end));
			this->_alloc.construct(left_nil, node_type(this->_end));
			this->_alloc.construct(right_nil, node_type(this->_end));
			this->_updateLeftNode(insert_node, left_nil);
			this->_updateRightNode(insert_node, right_nil);
			insert_node->setColor(COLOR_RED);
			return (insert_node);
		}

		/*
		case 0: node is root
			set color to black
		case 1: uncle is red
			set color of parent and uncle to black, grandparent to red
		case 2: uncle is black (triangle)
			rotate parent in the opposite direction of node (== opposite direction of uncle)
		case 3: uncle is black (line)
			set color of parent to black, grandparent to red and rotate grandparent in direction of uncle
		*/
		void	_insertFixup(node_pointer node)
		{
			node_pointer	grandparent = node_type::lookUpGrandparent(node);
			node_pointer	parent = node_type::lookUpParent(node);

			while (grandparent != NULL && parent->getColor() == COLOR_RED) {
				if (parent == grandparent->getLeftNode()) {
					node = this->_insertFixupCases(node,
						&ft::RbtNode<T, Alloc>::getRightNode,
						&ft::RedBlackTree<T, Compare, Alloc>::_rightRotate,
						&ft::RedBlackTree<T, Compare, Alloc>::_leftRotate);
				}
				else {
					node = this->_insertFixupCases(node,
						&ft::RbtNode<T, Alloc>::getLeftNode,
						&ft::RedBlackTree<T, Compare, Alloc>::_leftRotate,
						&ft::RedBlackTree<T, Compare, Alloc>::_rightRotate);
				}
				parent = node_type::lookUpParent(node);
				grandparent = node_type::lookUpGrandparent(node);
			}
			//case 0
			this->_root->setColor(COLOR_BLACK);
			return ;
		}

		node_pointer	_insertFixupCases(node_pointer node,
			node_pointer (ft::RbtNode<T, Alloc>::*getNodeDirectionUncle) (void),
			void (ft::RedBlackTree<T, Compare, Alloc>::*rotateDirectionUncle) (node_pointer),
			void (ft::RedBlackTree<T, Compare, Alloc>::*rotateOppositeDirection) (node_pointer))
		{
			node_pointer	grandparent = node_type::lookUpGrandparent(node);
			node_pointer	parent = node_type::lookUpParent(node);
			node_pointer	uncle;

			uncle = (grandparent->*getNodeDirectionUncle)();
			if (uncle->getColor() == COLOR_RED) {
				//case 1
				parent->setColor(COLOR_BLACK);
				uncle->setColor(COLOR_BLACK);
				grandparent->setColor(COLOR_RED);
				node = grandparent;
			}
			else if (node == (parent->*getNodeDirectionUncle)()) {
				//case 2
				node = parent;
				(this->*rotateOppositeDirection)(node);
			}
			else {
				//case 3
				parent->setColor(COLOR_BLACK);
				grandparent->setColor(COLOR_RED);
				(this->*rotateDirectionUncle)(grandparent);
			}
			return (node);
		}

		/*
		look at sibling, side determines which children to look at and the rotation
		case 0: sibling is red
			- set color of sibling to red, parent to black
			- rotate parent in direction of node
			- redefine sibling (node.parent.getNodeSiblingDirection)
		case 1: sibling is black, both sibling's children are black
			- set color of sibling to red
			- move on node up
		case 2: sibling is black, sibling.getNodeDirectionSibling is red and sibling.opposite is red
			- set color of sibling.oppositeDirection to black, sibling to red
			- rotate sibling
			- redefine sibling
			-> case 2 always calls case 3 afterwards
		case 3: sibling is black, sibling.getNodeDirectionSibling is red
			- set color of sibling to color of parent, parent to red, sibling.right to black
			- rotate parent in direction of node (opposite direction of sibling)
			- set node to root
		*/
		void	_deleteFixup(node_pointer node)
		{
			if (node == NULL) {
				return ;
			}
			while (node != this->_root && node->getColor() == COLOR_BLACK) {
				if (node == node->getParentNode()->getLeftNode()) {
					node = this->_deleteFixupCases(node,
						&ft::RbtNode<T, Alloc>::getRightNode,
						&ft::RbtNode<T, Alloc>::getLeftNode,
						&ft::RedBlackTree<T, Compare, Alloc>::_rightRotate,
						&ft::RedBlackTree<T, Compare, Alloc>::_leftRotate);
				}
				else {
					node = this->_deleteFixupCases(node,
						&ft::RbtNode<T, Alloc>::getLeftNode,
						&ft::RbtNode<T, Alloc>::getRightNode,
						&ft::RedBlackTree<T, Compare, Alloc>::_leftRotate,
						&ft::RedBlackTree<T, Compare, Alloc>::_rightRotate);
				}
			}
			node->setColor(COLOR_BLACK);
			if (ft::RbtNode<T, Alloc>::checkNIL(this->_root) == true) {
				this->_freeSingleNode(this->_root);
				this->_root = NULL;
			}
			return ;
		}

		node_pointer	_deleteFixupCases(node_pointer node,
			node_pointer (ft::RbtNode<T, Alloc>::*getNodeDirectionSibling) (void),
			node_pointer (ft::RbtNode<T, Alloc>::*getNodeOppositeDirection) (void),
			void (ft::RedBlackTree<T, Compare, Alloc>::*rotateDirectionSibling) (node_pointer),
			void (ft::RedBlackTree<T, Compare, Alloc>::*rotateOppositeDirection) (node_pointer))
		{
			node_pointer	sibling;

			sibling = (node->getParentNode()->*getNodeDirectionSibling)();
			if (sibling->getColor() == COLOR_RED) {
				//case 0
				sibling->setColor(COLOR_BLACK);
				node->getParentNode()->setColor(COLOR_RED);
				(this->*rotateOppositeDirection)(node->getParentNode());
				sibling = (node->getParentNode()->*getNodeDirectionSibling)();
			}
			if ((sibling->*getNodeOppositeDirection)()->getColor() == COLOR_BLACK
					&& (sibling->*getNodeDirectionSibling)()->getColor() == COLOR_BLACK) {
				//case 1
				sibling->setColor(COLOR_RED);
				node = node->getParentNode();
			}
			else {
				if ((sibling->*getNodeDirectionSibling)()->getColor() == COLOR_BLACK) {
					//case 2
					(sibling->*getNodeOppositeDirection)()->setColor(COLOR_BLACK);
					sibling->setColor(COLOR_RED);
					(this->*rotateDirectionSibling)(sibling);
					sibling = (node->getParentNode()->*getNodeDirectionSibling)();
				}
				//case 3
				sibling->setColor(node->getParentNode()->getColor());
				node->getParentNode()->setColor(COLOR_BLACK);
				(sibling->*getNodeDirectionSibling)()->setColor(COLOR_BLACK);
				(this->*rotateOppositeDirection)(node->getParentNode());
				node = this->_root;
			}
			return (node);
		}

		void	_freeSingleNode(node_pointer node)
		{
			this->_alloc.destroy(node);
			this->_alloc.deallocate(node, 1);
			return ;
		}

		void	_freeNode(node_pointer node)
		{
			if (node == NULL) {
				return ;
			}
			this->_freeNode(node->getLeftNode());
			this->_freeNode(node->getRightNode());
			this->_freeSingleNode(node);
			return ;
		}

		node_pointer	_copyNode(node_const_pointer node, node_pointer end)
		{
			node_pointer	n;

			if (node == NULL) {
				return (NULL);
			}
			n = this->_alloc.allocate(1);
			if (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				this->_alloc.construct(n, node_type(node->getValue(), end));
			}
			else {
				this->_alloc.construct(n, node_type(end));
			}
			n->setColor(node->getColor());
			n->setLeftNode(this->_copyNode(node->getLeftNode(), end));
			if (n->getLeftNode() != NULL) {
				n->getLeftNode()->setParentNode(n);
			}
			n->setRightNode(this->_copyNode(node->getRightNode(), end));
			if (n->getRightNode() != NULL) {
				n->getRightNode()->setParentNode(n);
			}
			return (n);
		}

		static node_pointer	_getMaximum(node_pointer node)
		{
			node_pointer	maximum = NULL;

			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				maximum = node;
				node = node->getRightNode();
			}
			return (maximum);
		}
	};
}
