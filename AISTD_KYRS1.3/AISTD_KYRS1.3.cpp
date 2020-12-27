#include <iostream>
#include <math.h>
#include "AISTD_KYRS1.3.h"
using namespace std;

int priority(char symbol)
{
	if (symbol == ')' || symbol == '(')
		return brecket;
	if (symbol == '+' || symbol == '-')
		return minplus;
	if (symbol == '*' || symbol == '/')
		return multdiv;
	if (symbol == '^')
		return degree;
	return other;
}
bool letter(char symbol)
{
	string can_be_letter("cosintglqrexpab");
	for (char now_symbol : can_be_letter)
	{
		if (symbol == now_symbol)
			return true;
	}
	return false;
}
bool number(char symbol)
{
	string can_begin_with_number("0123456789");
	for (char now_symbol : can_begin_with_number)
	{
		if (symbol == now_symbol)
			return true;
	}
	return false;
}
int func(string func)
{
	if (func == "cos")
		return Cos;
	if (func == "sin")
		return Sin;
	if (func == "tg")
		return Tg;
	if (func == "ctg")
		return Ctg;
	if (func == "ln")
		return Ln;
	if (func == "log")
		return Log;
	if (func == "sqrt")
		return Sqrt;
	if (func == "pi")
		return Pi;
	if (func == "exp")
		return E;
	return other; // not a function of the list
}

double count_function(int funct, double x)
{
	double count = 0;
	switch (funct)
	{
	case Cos:
		count = cos(x);
		break;
	case Sin:
		count = sin(x);
		break;
	case Tg:
		count = tan(x);
		break;
	case Ctg:
		count = tan(x);
		count = pow(count, -1);
		break;
	case Ln:
		count = log(x);
		break;
	case Log:
		count = log10(x);
		break;
	case Sqrt:
		count = sqrt(x);
		break;
	
	case E:
		count = exp(x);
		break;
	}
	return count;
}

double count_operation(string operation, double x, double y)
{
	double result = 0;
	switch (operation[0])
	{
	case '-':
		result = (x - y);
		break;
	case '+':
		result = (x + y);
		break;
	case '*':
		result = (x * y);
		break;
	case '/':
		result = (x / y);
		break;
	case '^':
		result = (pow(x, y));
		break;
	}
	return result;
}

Queue* string_processing() 
{
	char now_char;
	Queue* elements = new Queue;
	int left_breckets = 0,right_breckets = 0;
	while (Element.top() != '\n')
	{
		cin >> now_char;
		if (now_char == '(') // if we met (
		{
			left_breckets++;
			elements->push_front(priority(now_char), "("); // add ( to queue
			cout << now_char; // (
			if (priority(Element.top()) != other)
			{
				if (Element.top() == '-') //unary minus
					elements->push_front(0, "unminus"); 
			}
		}
		else if (number(now_char)) // met a first digit of a number
		{
			double now_number;
			cin.putback(now_char);
			cin >> now_number; // read whole number
			elements->push_front(now_number); 
		}
		else if (now_char == ')') // met )
		{
			right_breckets++;
			elements->push_front(priority(now_char), ")"); 
		}
		else if (priority(now_char) != other) 
		{
			if ((now_char == '-') && (elements->empty()))
				elements->push_front(0, "unminus"); 
			else 
			{
				string math;
				math.push_back(now_char);
				elements->push_front(priority(now_char), math); // operation with priority
				cout << now_char; //operator
			}
		}
		else if (letter(now_char)) // met a letter
		{
			string func;
			func.push_back(now_char); 
			while (letter(Element.top()))
			{
				cin >> now_char;
				func.push_back(now_char);
			} // now we have a word
		}
	}
	return elements;
}
Queue* convert_to_reverse_polish_notation(Queue* elem)
{
	Queue* reversed = new Queue;
	Stack stack;
	while (!elem->empty())
	{
		Element* now_element = new Element;
		now_element = elem->pop_front();
		string now_string = now_element->expression();
		double now_data = now_element->data();
		if (now_string == "(")
			stack.push_front(now_element);
		else if ( (now_string == "unminus") || (now_string == "pi")) // operand
		{
			reversed->push_front(now_element);
		}
		else if (now_string == ")")
		{
			while (stack.top()->expression() != "(")
			{

				reversed->push_front(stack.pop_front());
			}
			stack.pop_front(); // (
		}
		else // operator or function
		{
			if (!stack.empty())
			{
				while (now_data <= stack.top()->data())/
				{

					reversed->push_front(stack.pop_front());
					if (stack.empty())
						break;
				}
			}
			stack.push_front(now_element);
		}
	}
	while (!stack.empty())
	{

		reversed->push_front(stack.pop_front());
	}
	return reversed;
}

double calc(Queue* elements)
{
	Queue* elements = string_processing();
	double res = 0;
	Stack stack;
	while (!elements->empty())
	{
		Element* now_element = elements->pop_front();
		string now_string = now_element->expression();
		double now_data = now_element->data();
		if ( (now_string == "unminus") || (now_string == "pi"))
		{
			stack.push_front(now_element);
		}
		else // function or operator
		{
			double first_operand = 0;
			if ((now_data == priorities::func) && (!stack.empty()))
			{
				res = count_function(function(now_string), stack.pop_front()->data());
				stack.push_front(res);
			}
			else if (!stack.empty())
			{
				res = stack.pop_front()->data();
				first_operand = stack.pop_front()->data();
				res = count_operation(now_string, first_operand, res);
				stack.push_front(res);
			}
		}
	}
	return res;
}