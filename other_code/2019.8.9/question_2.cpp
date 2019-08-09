#include <iostream>
#include <string>
#if 0
class Person
{
public:
	std::string name_;
	int age_;
};

class Student : public Person
{
public:
	std::string id_;
};

int main()
{
	Person p = Student();
	Student s;
	Person *pt = &s;
	Person &p1 = s;
	Student *s1 = (Student*)pt;
	return 0;
}
#endif

#if 0
class Person
{public:
	Person(std::string name = "", int age = 10)
		:name_(name)
		, age_(age)
	{}

	Person(const Person& p)
	{
		name_ = p.name_;
		age_ = p.age_;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			name_ = p.name_;
			age_ = p.age_;
		}
		return *this;
	}
protected:
	std::string name_;
	int age_;
};

class Student : public Person
{
public:
	Student(std::string name, int age)
		:Person(name, age)//派生类构造函数调用基类的构造函数
	{}
	Student(const Student& s)
		:Person(s)//派生类对象可以赋值给基类的指针、引用和对象
	{//派生类的拷贝构造函数调用基类的拷贝构造函数
		std::cout << "Student(const)\n";
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			Person::operator=(s);//派生类的赋值运算符重载，调用基类的赋值运算符重载吧功夫
		}
		return *this;
	}
};

int main()
{
	Student s1("lixiong", 12);
	Student s2(s1);
	Student s3("xiaoming", 22);
	s3 = s1;
	return 0;
}
#endif

#if 0
class A
{
public:
	int a_;
};

class B
{
public:
	int b_;
};

class C :public A, public B
{
public:
	int c_;

	~C()
	{
		throw;
	}
};

int main()
{
	C c;
	c.a_ = 1;
	c.b_ = 2;
	c.c_ = 3;
	return 0;
}
#endif

class Person
{
public:
	virtual Person* BuyTicket()
	{
		std::cout << "all money\n";
		return this;
	}
};

class Student :public Person
{
public:
	Student* BuyTicket()  override//修饰派生类虚函数，强制重写基类虚函数
	{
		std::cout << "ban money\n";
		return this;
	}
};

void Func(Person& p)
{
	p.BuyTicket();
}
inline void add()
{
	;
}

int main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
	add();
	return 0;
}
