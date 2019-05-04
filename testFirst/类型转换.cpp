#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void cry() = 0;
};

class Dog:public Animal
{
public:
	virtual void cry()
	{
		cout << "wang wang" << endl;
	}
	void doHome()
	{
		cout << "watch door" << endl;
	}
};

class Cat:public Animal
{
public:
	virtual void cry()
	{
		cout << "miao miao" << endl;
	}
	void catchMouse()
	{
		cout << "catch mouse" << endl;
	}
};

void playObj(Animal* base)
{
	base->cry();
	Dog* d;
	d = dynamic_cast<Dog*>(base);
	if (d != NULL)
	{
		d->doHome();
	}

	Cat* c;
	c = dynamic_cast<Cat*>(base);
	if (c != NULL)
	{
		c->catchMouse();
	}

}

int main8()
{
	Dog d;
	Cat c;
	/*
	playObj(&d);
	playObj(&c);
	*/

	Animal* a;
	a = static_cast<Animal*>(&d);
	a->cry();
	return 0;
}