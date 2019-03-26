#include<iostream>

class base {
public:
	base()
	{
		std::cout << "Constructing base \n";
	}
	//delete it
	virtual ~base() =0
	{
		std::cout << "Destructing base \n";
	}
	//expects derived class to define
};

class derived : public base {
public:
	derived()
	{
		std::cout << "Constructing derived \n";
	}
	virtual ~derived()
	{
		std::cout << "Destructing derived \n";
	}
};

int main(void)
{
	derived *d = new derived();
	base *b = d;
	//You have to delete the derived and then the base
	//You can fix this with a virtual destructor 
	delete b; //calling base constructor. Makes a memory leak
	getchar();
	return 0;
}