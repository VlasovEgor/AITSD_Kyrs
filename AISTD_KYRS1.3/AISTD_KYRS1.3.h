#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Queue
{
private:
	Element* head; 
	Element* tail; 
public:
	Queue()
	{
		head = nullptr;
		tail = nullptr;
	}
	~Queue()
	{
		while (!empty())
			pop_first();
	}
	int count(); 
	bool empty(); // returns true if queue is empty
	Element* pop_first(); 
	Element* push_front(string);
	Element* push_front(double, string);
	void push_back(Element*);
};
class Stack
{
private:
	Element* top;
	void set_top(Element*);
public:
	Stack()
	{
		top = nullptr;
	}
	~Stack()
	{
		while (!empty())
			pop_front();
	}
	bool empty() // returns true if queue is empty
	{
		if (tail == nullptr) return true;
	}
	int count() // return a number of elements in queue
	{
		int count = 0;
		for (Element* now = tail; now->next() != nullptr; now = now->next())
			count++;
		return count;
	}
	Element* top(); // to show who's on the top
	Element* pop_front(); // to delte top and show it
	Element* push_front(double); // to push on top and show it
	void push_front(Element*);
};

class Element
{
	Element* next;
	string expression;
	double data;
	void next(Element*);
	void data(double);
	void data(string);
public:
	Element()
	{
		data = -1;
		next = nullptr;
	}
	~Element()
	{
		delete next;
		next = nullptr;
	}
	double data();
	double data() { return data; }
	class Queue;
	class Stack;
	Element* next();
	Element* next() { return next; }
	string expression();
	string expression() { return expression; }
	void next(Element* new_element) { next = new_element; }
	void data(double inf) { data = inf; }
	void data(string inf) { expression = inf; }
};
bool Queue::empty()
{
	if (top == nullptr)
		return true;
	return false;
}
int Queue::count()
{
	int count = 1;
	if (empty())
		return 0;
	for (Element* now = top; now->next() != nullptr; now = now->next())
		count++;
	return count;
}
Element* Queue::push_front(string data) // to add in the end of the queue the element with data
{
	Element* new_element = new Element;
	new_element->data(data);
	if (empty())
		head = tail = new_element;
	else
	{
		new_element->next(tail);
		tail = new_element;
	}
}

Element* Queue::push_front(double number, string data) /
{
	Element* new_elem = new Element;
	new_elem->data(number, data);
	if (empty())
		head = tail = new_elem;
	else
	{
		new_elem->next(tail);
		tail = new_elem;
	}
}

void Queue::push_back(Element* new_elem) 
{
	if (empty())
		head = tail = new_elem;
	else
	{
		new_element->next(tail);
		tail = new_elem;
	}
}

Element* Queue::pop_first() 
{
	Element* to_delete;
	 if (count() == 1)
	{
		to_delete = head;
		head = tail = nullptr;
	}
	else
	{
		to_delete = head;
		for (Element* now = tail; now->next() != nullptr; now = now->next())
			head = now;
		head->next = nullptr;
	}
	return to_delete;
}
void Stack::set_top(Element* top_elem) { top = top_elem; }
bool Stack::empty()
{
	if (top == nullptr)
		return true;
	return false;
}
int Stack::count()
{
	int count = 1;
	if (empty())
		return 0;
	for (Element* now = top; now->next() != nullptr; now = now->next())
		count++;
	return count;
}
Element* Stack::top() // to show who's on the top
{
	return top;
}
Element* Stack::pop_front() // to delte top and show it
{
	Element* to_delete = top;
	if (empty())
		throw out_of_range("the stack is empty");
	else
		top = top->next();
	return to_delete;
}
Element* Stack::push_front(double data) // to push on top and show it
{
	Element* new_element = new Element;
	new_element->data(data);
	if (empty())
		top = new_element;
	else
	{
		new_element->next(top);
		top = new_element;
	}
	return new_element;
}
void Stack::push_front(Element* new_elem) // to push on top and show it
{
	if (empty())
		top = new_elem;
	else
	{
		new_elem->next(top);
		top = new_elem;
	}
}
enum functions { Cos, Sin, Tg, Ctg, Log, Ln, Sqrt, Pi, E, other };
enum priorities { brecket, minplus, multdiv, degree, func, other };
int priority(char);
int function(string);
Queue* string_processing();
Queue* convert_to_reverse_polish_notation(Queue*);
double calc(Queue* elements);