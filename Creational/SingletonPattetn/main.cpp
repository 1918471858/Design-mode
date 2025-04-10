#include <iostream>
#include "Singleton.h"

class TestA {
	friend class Singleton<TestA>;

public:
	void show() {
		m_calledCount++;
		std::cout << m_calledCount << std::endl;
	};

	//˽�л����캯���������������������캯������ֵ������ʹ�䲻�ܴ���ʵ��
private:
	TestA() {
		m_calledCount = 1;
		std::cout << "TestA������" << std::endl;
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
	//���Դ���
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