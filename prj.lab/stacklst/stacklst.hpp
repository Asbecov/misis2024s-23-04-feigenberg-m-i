
#ifndef STACKLSTHPP09022024
#define STACKLSTHPP09022024

#include <sstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackLST {
private:
	struct Node {
		Node() = default;
		Node(const Complex& data) 
			: data_{data}
		{
		}
		Complex data_{0};
		Node* prev_{nullptr};
	};
	Node* head_{nullptr};
public:
	StackLST() = default;
	~StackLST(){
		while (head_ != nullptr) {
			Node* previ = head_->prev_;
			delete head_;
			head_ = previ;
		}
	}
	StackLST(const StackLST& rhs) 
	{
		Node* rhs_head = rhs.head_;
		Node* this_head = head_;
		while (rhs_head != nullptr) {
			if (this_head->prev_ != nullptr) {
				this_head->data_ = rhs_head->data_;
				this_head = this_head->prev_;
			}
			else {
				this_head->data_ = rhs_head->data_;
				if (rhs_head->prev_ != nullptr) {
					Node* previ = this_head;
					this_head = new Node();
					previ->prev_ = this_head;
				}
			}
			rhs_head = rhs_head->prev_;
		}
	}
	
	StackLST& operator=(const StackLST& rhs) {
		if (this != &rhs) {
			Node* rhs_head = rhs.head_;
			Node* this_head = head_;
			while (rhs_head != nullptr) {
				if (this_head->prev_ != nullptr) {
					this_head->data_ = rhs_head->data_;
					this_head = this_head->prev_;
				}
				else {
					this_head->data_ = rhs_head->data_;
					if (rhs_head->prev_ != nullptr) {
						Node* previ = this_head;
						this_head = new Node();
						previ->prev_ = this_head;
					}
				}
				rhs_head = rhs_head->prev_;
			}
		}
		return *this;
	}

	void Pop() noexcept;
	void Push(const Complex&) noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();
	const Complex& Top() const;
};

#endif //STACKLSTHPP09022024