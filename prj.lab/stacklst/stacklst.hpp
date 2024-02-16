
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
		Node(const Node&) = default;
		Node& operator=(const Node&) = default;
		Node(const Complex& data, const Node* next) 
			: data_{data}, next_{next}
		{	
		}
		Node(const Complex& data) 
			: data_{data}
		{
		}
		~Node() {
			next_ = nullptr;
		}
		Complex data_;
		Node* next_{nullptr};
	};
	Node* head_{nullptr};
	Node* first_{nullptr};
public:
	StackLST() = default;
	~StackLST(){
		while (first_ != nullptr) {
			Node* next = first_->next_;
			delete first_;
			first_ = next;
		}
		head_ = nullptr;
	}
	StackLST(const StackLST& rhs) 
	{
		if (rhs.first_ != nullptr) {
			first_ = new Node(rhs.first_->data_);
			head_ = first_;
			while ()
		}
	}
	StackLST& operator=(const StackLST&) ;

	void Pop() noexcept;
	void Push(const Complex&) noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();
	const Complex& Top() const;
};

#endif //STACKLSTHPP09022024