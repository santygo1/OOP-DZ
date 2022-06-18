#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
concept Printable = requires(std::ostream & os, T a)
{
	os << a;
};

template<Printable T>
class List
{
protected:
	struct Node {
		T value;
		Node* left;
		Node* right;

		Node() {
			left = right = nullptr;
		}
		Node(T value) {
			left = right = nullptr;
			this->value = value;
		}
	} *head, * tail;

public:


	template<class T>
	class Iterator {
		friend class List<T>;
	public:
		typedef T iterator_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef iterator_type value_type;
		typedef ptrdiff_t difference_type;
		typedef iterator_type& reference;
		typedef iterator_type* pointer;

		List::Node* ptr;
	public:
		Iterator(List::Node* p) : ptr(p) {}

		bool operator!=(Iterator const& other) const {
			return ptr != other.ptr;
		}

		bool operator==(Iterator const& other) const {
			return ptr == other.ptr;
		}

		typename Iterator::reference& operator*() const {
			return ptr->value;
		}

		Iterator& operator++() {
			if (ptr == nullptr || ptr->right == nullptr) return *this;
			ptr = ptr->right;
			return *this;
		}

		Iterator& operator--() {
			if (ptr == nullptr || ptr->left == nullptr) return *this;
			ptr = ptr->left;
			return *this;
		}
	};
	
	typedef Iterator<T> iterator;
	typedef Iterator<const T> const_iterator;

	List() :list_size(0), head(nullptr), tail(nullptr) {}
	~List() { clear(); }

	iterator begin() { 
		return iterator(head); 
	}
	iterator end() {
		return iterator(tail == nullptr ? nullptr : tail->right);
	}

	const_iterator begin() const {
		return const_iterator(head);
	}

	const_iterator end() const {
		return const_iterator(tail == nullptr ? nullptr : tail->right);
	}


	void push_back(T value) {
		if (head == nullptr) {
			head = tail = new Node(value);
			tail->right = new Node();
			tail->right->left = tail;
		}
		else {
			Node* temp = tail->right;
			tail->right = new Node(value);
			tail->right->left = tail;
			tail = tail->right;

			tail->right = temp;
			tail->right->left = tail;
		}
		list_size++;
	}

	void pop_front() {
		if (head == nullptr) return;
		if (list_size == 1) {
			delete tail->right;
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* tmp = head;
			head = head->right;
			head->left = nullptr;
			delete tmp;
		}
		--list_size;
	}

	void pop_back() {
		if (head == nullptr) return;
		if (list_size == 1) pop_front();
		else {
			Node* temp = tail;
			tail = tail->left;
			tail->right = temp->right;
			temp->right->left = tail;
			delete temp;
		}
		--list_size;
	}

	void remove(size_t index) {
		if (index < 0 || index >= list_size) return;
		
		if (index == 0) pop_front();
		else if (index == list_size - 1) pop_back();
		else {
			Node* tmp = find(index);
			tmp->left->right = tmp->right;
			tmp->right->left = tmp->left;
			delete tmp;
		}
	}

	void clear() {
		while (list_size) pop_front();
	}

	int size() {
		return list_size;
	}

	bool is_empty() {
		return list_size > 0 ? false : true;
	}

private:
	size_t list_size;

	Node* find(int index)
	{
		Node* current = head;
		size_t counter = 0;
		if (index <= list_size / 2) {
			do {
				if (counter++ == index) break;
				current = current->right;
			} while (current != tail);
		}
		else {
			current = tail;
			counter = list_size;
			do {
				if (--counter == index) break;
				current = current->left;
			} while (current != head);
		}
		return current;
	}
};

template<Printable T>
std::ostream& operator<<(std::ostream& os, List<T>& list) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		os << (*it) << endl;
	}
	return os;
}
#endif //LIST_H
