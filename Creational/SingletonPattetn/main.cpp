#include <iostream>
#include "Singleton.h"

class TestA {
	friend class Singleton<TestA>;

public:
	void show() {
		m_calledCount++;
		std::cout << m_calledCount << std::endl;
	};

	//私有化构造函数、析构函数、拷贝构造函数、赋值函数。使其不能创建实列
private:
	TestA() {
		m_calledCount = 1;
		std::cout << "TestA被构造" << std::endl;
		std::cout << m_calledCount << std::endl;
	};
	~TestA() {};
	TestA(const TestA&) {};
	TestA& operator=(const TestA&) {};

private:
	int m_calledCount;
};

int main(int argc, char* argv[])
{
	//测试代码
	TestA* a = Singleton<TestA>::getInstance();
	a->show();
	TestA* b = Singleton<TestA>::getInstance();
	b->show();
	b->show();
	b->show();
	TestA* c = Singleton<TestA>::getInstance();
	c->show();
	c->show();
	c->show();

	system("pause");
	return 0;
}