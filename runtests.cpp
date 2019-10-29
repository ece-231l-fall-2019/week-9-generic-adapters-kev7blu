#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1 
#include "List.h"
#include "Stack.h" //first in last out
#include "Queue.h" //first in first out
typedef Stack<std::string> StringStack;
typedef List<std::string> StringList;
typedef Queue<double> DoubleQueue;
typedef Stack<int> IntStack;
typedef List<int> IntList;
typedef Queue<char> CharQueue;
#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	//StringList
	StringList a{};
	StringList b{};

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.size() == 2, "StringList a has 2 elements");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;
	
	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	StringList i{"I", "am", "your", "friend"};
	i.print("StringList i : pre-methods");
	Assert(i.size() == 4, "StringList has 4 elements");
	Assert(i.front() == "I", "i.front() == I");
	Assert(i.back() == "friend", "i.back() == friend");
	i.pop_back();
	Assert(i.empty() == false, "i is NOT empty");
	i.push_back("father");
	i.pop_front();
	Assert(i.front() == "am", "i.front() == am");
	i.pop_front();
	Assert(i.front() == "your", "i.front() == your");
	i.push_front("is");
	i.push_front("Vader");
	i.push_front("Darth");
	Assert(i.size() == 5, "i has 5 elements");
	i.print("StringList i : post-methods");
	
	//StringStack
	StringStack c{};
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "StringStack c is not empty");
	Assert(c.size() == 1, "StringStack c has 1 element");
	c.pop();
	Assert(c.empty() == true, "StringStack c is empty");
	Assert(c.size() == 0, "StringStack c has 0 elements");

	StringStack h{"TIC", "TAC", "TOE"};
	Assert(h.top() == "TOE", "TOE is at top");
	Assert(h.size() == 3, "StringStack c has 3 elements");
	h.pop();
	Assert(h.top() == "TAC", "TAC is at top");
	Assert(h.empty() == false, "StringStack h is not empty");
	Assert(h.size() == 2, "StringStack c has 2 elements");
	h.pop();
	h.pop();
	Assert(h.size() == 0, "StringStack c has 0 elements");
	
//	Assert(c != h, "StringStack c == StringStack h");
	
	//IntList
	IntList ia{};
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");
	ia.push_front(7);
	ia.push_front(8);
	ia.push_front(9);	
	Assert(ia.back() == 5, "back is 5");
	ia.pop_front();	
	Assert(ia.front() == 8, "front is 8");
	ia.pop_back(); 
	Assert(ia.back() == 6, "back is 6");
	ia.push_back(10);
	Assert(ia.back() == 10, "back is 10");

	IntList g;
	g = ia;

//	Assert(g == ia, "IntList g == IntList ia");	

	Assert(g.empty() == false, "IntList g is NOT empty");
	Assert(g.size() == 4, "IntList g has 4 elements");
	g.pop_back();
	g.pop_back();
	g.pop_back();
	g.pop_back();
	Assert(g.empty() == true, "IntList g is empty");
	Assert(g.size() == 0, "IntList g has 0 elements");

//	Assert(g != ia, "IntList g == IntList ia");	
	
	//IntStack
	IntStack ib{};
	ib.push(6);
	ib.push(5);
	//ib.print("test");
	Assert(ib.top() == 5, "top is 5");
	
	IntStack ic{};
	ic.push(6);
	ic.push(5);
	
	IntStack id{};
	id = ic;
	id.push(37);	

	Assert(ib == ic, "IntStack ib == IntStack ic");
//	Assert(id != ic, "id != ic");
	
	Assert(ic.empty() == false, "ic is NOT empty");
	Assert(ic.size() == 2, "ic has 2 elements");
	
	IntStack d{};
	d.push(1);
	d.push(2);
	d.push(3);
	d.push(4);
	Assert(d.top() == 4, "top is 4");
	d.pop();
	d.pop();
	Assert(d.top() == 2, "top is 2");
	
	IntStack e{};
	e.push(42);
	Assert(e.empty() == false, "e.IntStack is NOT empty");
	Assert(e.size() == 1, "e.IntStack has 1 element");
	Assert(e.top() == 42, "top is 42");
	
	IntStack f{};
	f = e;
	f.pop();
	Assert(f.empty() == true, "f.IntStack is empty");
	Assert(f.size() == 0, "f.IntStack has 1 element");
	
	//DoubleQueue FIFO
	DoubleQueue j{23.236, 45.346, 86.342, 36.965, 22.245};
	
	Assert(j.front() == 23.236, "j.front() is 23.236");
	Assert(j.back() == 22.245, "j.back() is 22.245");
	Assert(j.size() == 5, "DoubleQueue j has 5 elements");
	j.pop();
	Assert(j.front() == 45.346, "j.front() is 45.346");
	Assert(j.back() == 22.245, "j.back() is 22.245");
	Assert(j.size() == 4, "DoubleQueue j has 4 elements");
	j.push(43.723);
	
	DoubleQueue k{};
	
	Assert(k.empty() == true, "DoubleQueue k is empty");
	k = j;
	Assert(k.empty() == false, "DoubleQueue k is NOT empty");
	Assert(j.size() == 5, "DoubleQueue k has 5 elements");
		
	DoubleQueue l{};
	
	Assert(l.size() == 0, "DoubleQueue l has NO elements");
	l = k;
	
//	Assert(k == j, "DoubleQueue k == DoubleQueue j");	
//	Assert(l == j, "DoubleQueue l == DoubleQueue j");		

	//CharQueue	
	CharQueue m{'E', 'A', 'R', 'T', 'H', 'Q', 'U', 'A', 'K', 'E'};
	Assert(m.front() == 'E', "m.front() = E");
	Assert(m.back() == 'E', "m.back() = E");
	Assert(m.size() == 10, "CharQueue m has 10 elements");
	m.pop();
	m.pop();
	m.pop();
	m.pop();
	m.pop();
	Assert(m.front() == 'Q', "m.front() = Q");
	Assert(m.back() == 'E', "m.back() = E");
	Assert(m.size() == 5, "CharQueue m has 5 elements");
	
	CharQueue n{};
	Assert(n.empty() == true, "CharQueue n is empty");
	Assert(n.size() == 0, "CharQueue n has NO elements");
	n = m;
	n.push('R');
	n.push('E');
	n.push('S');
	n.push('H');
	n.push('A');
	n.push('K');
	n.push('E');

	CharQueue o{};
	o = n;	

//	Assert(o == n, "CharQueue o == CharQueue n");
//	Assert(m != n, "CharQueue m != CharQueue n");
	
	Assert(o.size() == 12, "CharQueue o has 12 elements");
	o.pop();
	o.pop();
	o.pop();
	o.pop();
	o.pop();
	Assert(o.size() == 7, "CharQueue o has 7 elements");
	Assert(o.front() == 'R', "m.front() = R");
	Assert(o.back() == 'E', "m.back() = E");
	
	return 0;
}
