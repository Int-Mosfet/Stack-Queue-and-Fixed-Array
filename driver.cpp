//#include "Base_Array.h"
//#include "Array.h"
//#include <stdlib.h>     //for using the function sleep
#include <iostream>		//for printing debug info to screen
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(int argc, char * argv[])
{   
	std::cout << "*** Array / Stack / Queue / Fixed_Array Test Program ***" << std::endl;

	Array<char> a1;
	Stack<int> s1;
	Queue<double> q1;
	Fixed_Array<int,5> fa1;

	std::cout << "Array Test" << std::endl;



	//Stack<int> s2(s1);
	//cout << s1.size() << endl;
	//Queue<int> q1;
	//Queue<int> q2;
	//q1.is_empty();
	//cout << q1.size() << endl;

	//q1.enqueue(1);
	//q1.enqueue(269);
	//q1.enqueue(3);
	//q1.enqueue(4);
	//cout << q1.dequeue() << endl;
	//cout << q1.dequeue() << endl;
	//cout << q1.dequeue() << endl;
	//cout << q1.dequeue() << endl;
	//q1.clear();
	//cout << q1.is_empty() << endl;
	//Queue<int> q2(q1);

	//Queue<char> q3;
	//q3.resize(5);
	//q3.fill('r');
	//cout << q3.dequeue() << endl;
	//cout << q3.dequeue() << endl;
	//cout << q3.dequeue() << endl;
	//cout << q3.dequeue() << endl;
	//cout << q3.dequeue() << endl;*/


	//for (int i = 0; i < q1.size(); i++)
	//{
	//	cout << q1.get(i) << endl;
	//}

	//s1.pop(); //throws error when empty, good


	//Fixed array appears to work
	//Fixed_Array<char, 5> f1;
	//Fixed_Array<char, 5> f2(f1);

	//if (f1 == f2)
	//	cout << "TRUE TRUE TRUE" << endl;
	//if (f1 != f2)
	//	cout << "FALSE FALSE FALSE" << endl;

	
	//f1.fill('~');
	//f1.set(0, '@');
	//for (int i = 0; i < f1.size(); i++)
	//{
	//	cout << f1.get(i) << endl;
	//}

	
	
	//cout << q1.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		s1.push(i);
		cout << s1.top() << endl;
	}
	//cout << s1.size() << endl;

	s1.pop();
	cout << s1.top() << endl;
	//s1.pop();
	//s1.pop();
	//s1.pop();
	//s1.pop();
	//cout << s1.size() << endl;
	//s1.push(69);
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << s1.get(i) << endl;
	//}

	//cout << s1.top() << endl; //top() works
	//cout << s1.is_empty() << endl; //is_empty() works
	
	//cout <<  s1.get(11) << endl;



	//s1.push(2);
	//s1.push(3);
	//cout << "" << endl;
	//cout << "" << endl;
	//cout << "" << endl;
	//cout << "" << endl;
	//cout << s1.top() << endl;

	//q1.enqueue(1);
	//q1.enqueue(269);
	//q1.enqueue(3);
	//q1.enqueue(4);

	//Queue<int> q2(q1);

	//cout << "" << endl;
	//cout << "LIST QUEUE1:" << endl;
	//cout << "" << endl;
	//for (int i = 0; i < q1.size(); i++)
	//{
	//	cout << q1.get(i) << endl;
	//}

	//q1.dequeue();
	//q1.dequeue();
	//q1.clear();
	
	//cout << "" << endl;
	//cout << "LIST QUEUE1 AFTER DEQUEUE:" << endl;
	//cout << "" << endl;
	//for (int i = 0; i < q1.size(); i++)
	//{
	//	cout << q1.get(i) << endl;
	//}

	

	/*cout << "" << endl;
	cout << "LIST QUEUE2:" << endl;
	cout << "" << endl;
	for (int i = 0; i < q2.size(); i++)
	{
		cout << q2.get(i) << endl;
	}*/
	

	//cout << q1.size() << endl;

	
	//cout << q1.is_empty() << endl;



	/*
	s1.push('a');
	std::cout << "top of stack: " << s1.top() << "\n";
	*/



	//base array works
	//Base_Array<double> ba(10);
	//int set_val = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	ba.set(i, set_val);  //array set works
	//	set_val++;
	//}
	//ba.reverse();
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << ba.get(i) << endl; //array get works
	//}
	


	//Array seems to work
	//Array<double> arr; //<--default constructor
	//Array<double> arrr;
	//Array<double> a1(10); //<--initializing constructor (only length)
	//Array<short> arrhar(10, 2); //<--initializing constructor (length and fill)
	//Array<short> arrharhar(arrhar); //<--copy constructor
	//a1.fill(1.562362356); //<--only works up to 1.56236
	//cout << a1.get(10) << endl; //<--won't get at bounds, which is good
	
	//arr.resize(10);
	//double set_val = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	a1.set(i, set_val);  //array set works
	//	set_val++;
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << a1.get(i) << endl; //array get works
	//}
	




	//cout << a1.find(0, 1) << endl; //find with startpoint works

	//if (arr == a1)
	//{
	//	cout << "equal to" << endl; //equal to works
	//}
	//else if (arr != a1)
	//{
	//	cout << "not equal to" << endl; //not equal to works
	//}

	//cout << a1.find(11) << endl; //find works

	//shrink works
	//a1.resize(5);
	//cout << a1.size() << endl;
	//cout << a1.max_size() << endl;
	//a1.shrink();
	//cout << a1.size() << endl;
	//cout << a1.max_size() << endl;

	//a1.resize(18.354);//array resize greater than works
	//a1.resize(10);//array resize equal to works, no funkiness
	//a1.resize(2);//array resize less than works
	//a1.reverse(); //array reverse works
	//for (double i = 0; i < 1.6; i+0.1) //<--BUG! infinite loop
	//for (double i = 0; i < 10; i++)
	//{
	//	cout << a1.get(i) << endl;
	//}


	return 0;
}