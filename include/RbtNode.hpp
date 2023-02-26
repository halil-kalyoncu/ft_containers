/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RbtNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:22:45 by hkalyonc          #+#    #+#             */
/*   Updated: 2023/02/25 11:21:39 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define COLOR_RED 0
#define COLOR_BLACK 1

//allocator
#include <memory>
//NULL
#include <cstddef>

/*

	RbtNode synopsis

	template<typename T, typename Alloc = std::allocator<T> >
	class RbtNode
	{
	public:
		typedef T						value_type;
		typedef value_type&				value_ref;
		typedef const value_type&		value_const_reference;
		typedef T*						value_pointer;
		typedef Alloc					allocator_type;

		static bool						checkNIL(const ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	lookUpParent(ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	lookUpGrandparent(ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	lookUpMinimum(ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	lookUpMaximum(ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	nextNode(ft::RbtNode<T, Alloc>* node);
		static ft::RbtNode<T, Alloc>*	previousNode(ft::RbtNode<T, Alloc>* node);

		RbtNode(const allocator_type& alloc = allocator_type());
		RbtNode(ft::RbtNode<T, Alloc>* end, const allocator_type& alloc = allocator_type());
		RbtNode(value_const_reference value, ft::RbtNode<T, Alloc>* end, const allocator_type& alloc = allocator_type());
		RbtNode(const ft::RbtNode<T, Alloc>& copy);
		~RbtNode(void);

		value_pointer					getValuePointer(void) const;
		value_ref						getValue(void);
		value_const_reference			getValue(void) const;
		bool							getColor(void) const;
		void							setColor(bool color);
		ft::RbtNode<T, Alloc>*			getParentNode(void);
		const ft::RbtNode<T, Alloc>*	getParentNode(void) const;
		void							setParentNode(ft::RbtNode<T, Alloc>* parentNode);
		const ft::RbtNode<T, Alloc>*	getLeftNode(void) const;
		ft::RbtNode<T, Alloc>*			getLeftNode(void);
		void							setLeftNode(ft::RbtNode<T, Alloc>* leftNode);
		const ft::RbtNode<T, Alloc>*	getRightNode(void) const;
		ft::RbtNode<T, Alloc>*			getRightNode(void);
		void							setRightNode(ft::RbtNode<T, Alloc>* rightNode);
		ft::RbtNode<T, Alloc>*			getEnd(void) const;
		void							setEnd(ft::RbtNode<T, Alloc>* endNode);

	private:
		value_pointer					_value;
		bool							_color;
		ft::RbtNode<T, Alloc>*			_parent;
		ft::RbtNode<T, Alloc>*			_left;
		ft::RbtNode<T, Alloc>*			_right;
		ft::RbtNode<T, Alloc>*			_end;
		allocator_type					_alloc;

		ft::RbtNode<T, Alloc>&			operator=(const ft::RbtNode<T, Alloc>& rhs);
	};

*/

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class RbtNode
	{
	public:
		typedef T					value_type;
		typedef value_type&			value_ref;
		typedef const value_type&	value_const_reference;
		typedef T*					value_pointer;
		typedef Alloc				allocator_type;

		static bool	checkNIL(const ft::RbtNode<T, Alloc>* node)
		{
			if (node == NULL) {
				return (false);
			}
			return (node->getValuePointer() == NULL);
		}

		static ft::RbtNode<T, Alloc>*	lookUpParent(ft::RbtNode<T, Alloc>* node)
		{
			if (node == NULL) {
				return (NULL);
			}
			return (node->getParentNode());
		}

		static ft::RbtNode<T, Alloc>*	lookUpGrandparent(ft::RbtNode<T, Alloc>* node)
		{
			ft::RbtNode<T, Alloc>*	parent = ft::RbtNode<T, Alloc>::lookUpParent(node);

			if (parent == NULL) {
				return (NULL);
			}
			return (parent->getParentNode());
		}

		static ft::RbtNode<T, Alloc>*	lookUpMinimum(ft::RbtNode<T, Alloc>* node)
		{
			ft::RbtNode<T, Alloc>*	minimum = NULL;

			if (node == NULL) {
				return (NULL);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				minimum = node;
				node = node->getLeftNode();
			}
			return (minimum);
		}

		static ft::RbtNode<T, Alloc>*	lookUpMaximum(ft::RbtNode<T, Alloc>* node)
		{
			ft::RbtNode<T, Alloc>*	maximum = NULL;

			if (node == NULL) {
				return (NULL);
			}
			while (ft::RbtNode<T, Alloc>::checkNIL(node) == false) {
				maximum = node;
				node = node->getRightNode();
			}
			return (maximum);
		}

		/*
		next biggest node is either it's right child or when moving up the tree
		the first time if it is the left child
		*/
		static ft::RbtNode<T, Alloc>*	nextNode(ft::RbtNode<T, Alloc>* node)
		{
			ft::RbtNode<T, Alloc>*	parent_node;
			ft::RbtNode<T, Alloc>*	previous_node;

			if (node->getEnd() == NULL) {
				return (node);
			}
			if (ft::RbtNode<T, Alloc>::checkNIL(node->getRightNode()) == false) {
				return (ft::RbtNode<T, Alloc>::lookUpMinimum(node->getRightNode()));
			}
			previous_node = node;
			parent_node = node->getParentNode();
			while (parent_node != NULL && parent_node->getLeftNode() != previous_node) {
				previous_node = parent_node;
				parent_node = parent_node->getParentNode();
			}
			if (parent_node != NULL) {
				return (parent_node);
			}
			return (node->getEnd());
		}

		static ft::RbtNode<T, Alloc>*	previousNode(ft::RbtNode<T, Alloc>* node)
		{
			ft::RbtNode<T, Alloc>*	parent_node;
			ft::RbtNode<T, Alloc>*	previous_node;

			if (node->getEnd() == NULL) {
				if (node->getParentNode() == NULL) {
					return (node);
				}
				return (ft::RbtNode<T, Alloc>::lookUpMaximum(node->getParentNode()));
			}
			if (ft::RbtNode<T, Alloc>::checkNIL(node->getLeftNode()) == false) {
				return (ft::RbtNode<T, Alloc>::lookUpMaximum(node->getLeftNode()));
			}
			previous_node = node;
			parent_node = node->getParentNode();
			while (parent_node != NULL && parent_node->getRightNode() != previous_node) {
				previous_node = parent_node;
				parent_node = parent_node->getParentNode();
			}
			if (parent_node != NULL) {
				return (parent_node);
			}
			// only the case if you have decrement the smallest element
			// not quite right, but the original causes a seqfault, when dereferencing
			return (node);
		}

		RbtNode(const allocator_type& alloc = allocator_type()) : _value(NULL),
			_color(COLOR_BLACK), _parent(NULL), _left(NULL), _right(NULL),
			_end(NULL), _alloc(alloc)
		{
			this->_value = this->_alloc.allocate(1);
			this->_alloc.construct(this->_value, value_type());
			return ;
		}

		RbtNode(ft::RbtNode<T, Alloc>* end,
			const allocator_type& alloc = allocator_type()) : _value(NULL),
				_color(COLOR_BLACK), _parent(NULL), _left(NULL), _right(NULL),
				_end(end), _alloc(alloc)
		{
			return ;
		}

		RbtNode(value_const_reference value, ft::RbtNode<T, Alloc>* end,
			const allocator_type& alloc = allocator_type()) : _value(NULL),
				_color(COLOR_BLACK), _parent(NULL), _left(NULL), _right(NULL),
				_end(end), _alloc(alloc)
		{
			this->_value = this->_alloc.allocate(1);
			this->_alloc.construct(this->_value, value);
			return ;
		}

		RbtNode(const ft::RbtNode<T, Alloc>& copy) : _value(NULL), _color(copy._color),
			_parent(NULL), _left(NULL), _right(NULL), _end(copy._end),
			_alloc(copy._alloc)
		{
			if (copy._value != NULL) {
				this->_value = this->_alloc.allocate(1);
				this->_alloc.construct(this->_value, *(copy._value));
			}
			return ;
		}

		~RbtNode(void)
		{
			if (this->_value != NULL) {
				this->_alloc.destroy(this->_value);
				this->_alloc.deallocate(this->_value, 1);
			}
			return ;
		}

		value_pointer	getValuePointer(void) const
		{
			return (this->_value);
		}

		value_ref	getValue(void)
		{
			return (*(this->_value));
		}

		value_const_reference	getValue(void) const
		{
			return (*(this->_value));
		}

		bool	getColor(void) const
		{
			return (this->_color);
		}

		void	setColor(bool color)
		{
			this->_color = color;
			return ;
		}

		ft::RbtNode<T, Alloc>*	getParentNode(void)
		{
			return (this->_parent);
		}

		const ft::RbtNode<T, Alloc>*	getParentNode(void) const
		{
			return (this->_parent);
		}

		void	setParentNode(ft::RbtNode<T, Alloc>* parentNode)
		{
			this->_parent = parentNode;
			return ;
		}

		const ft::RbtNode<T, Alloc>*	getLeftNode(void) const
		{
			return (this->_left);
		}

		ft::RbtNode<T, Alloc>*	getLeftNode(void)
		{
			return (this->_left);
		}

		void	setLeftNode(ft::RbtNode<T, Alloc>* leftNode)
		{
			this->_left = leftNode;
			return ;
		}

		const ft::RbtNode<T, Alloc>*	getRightNode(void) const
		{
			return (this->_right);
		}

		ft::RbtNode<T, Alloc>*	getRightNode(void)
		{
			return (this->_right);
		}

		void	setRightNode(ft::RbtNode<T, Alloc>* rightNode)
		{
			this->_right = rightNode;
			return ;
		}

		ft::RbtNode<T, Alloc>*	getEnd(void) const
		{
			return (this->_end);
		}

		void	setEnd(ft::RbtNode<T, Alloc>* endNode)
		{
			this->_end = endNode;
			return ;
		}

	private:
		value_pointer			_value;
		bool					_color;
		ft::RbtNode<T, Alloc>*	_parent;
		ft::RbtNode<T, Alloc>*	_left;
		ft::RbtNode<T, Alloc>*	_right;
		ft::RbtNode<T, Alloc>*	_end;
		allocator_type			_alloc;

		// We don't want that the value can be changed after initialization,
		// making the attribute private doesn't work here, allocator needs two
		// function calls.
		// Also the relationships between the nodes can't easily be copied.
		// therefore the assignment is private
		ft::RbtNode<T, Alloc>&	operator=(const ft::RbtNode<T, Alloc>& rhs)
		{
			if (this != &rhs) {
				this->_alloc.destroy(this->_value);
				this->_alloc.construct(this->_value, *(rhs._value));
			}
			return (*this);
		}

	};

}
