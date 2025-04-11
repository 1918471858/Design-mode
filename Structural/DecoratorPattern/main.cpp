#include <iostream>
#include <string>

using namespace std;

//����ӿ�
class Component 
{
public:
	virtual void operation() = 0;
	virtual ~Component() = default;
};

//�������A
class ComponentA :public Component
{
public:
	virtual void operation()override {
		cout << "���A�Ĺ���" << endl;
	}
};

//����װ������
class Decorator : public Component 
{
public:
	Decorator(Component* c) : m_component(c) {};
	virtual void operation()
	{
		m_component->operation();
	}
	virtual ~Decorator() = default;
protected:
	Component* m_component;
};

//����װ����B
class DecoratorB :public Decorator
{
public:
	DecoratorB(Component* com) :Decorator(com) {};
	virtual void operation() override
	{
		cout << "װ����BΪ�������¹���B" << endl;
	}
	virtual ~DecoratorB() = default;
};

//����װ����C
class DecoratorC :public DecoratorB
{
public:
	DecoratorC(Component* com) :DecoratorB(com) {};
	virtual void operation() override
	{
		cout << "װ����CΪ�������¹���C" << endl;
	}
	virtual ~DecoratorC() = default;
};

int main(int argc, char* argv[])
{
	//�������A�����ʹ���
	ComponentA* componentA = new ComponentA();
	componentA->operation();
	cout << endl;

	//����װ����B��װ�����A
	DecoratorB* decoratorB = new DecoratorB(componentA);
	//ͨ��װ����B���ʹ���
	decoratorB->Decorator::operation();
	decoratorB->operation();
	cout << endl;

	//����װ����C��װ�����A
	DecoratorC* decoratorC = new DecoratorC(componentA);
	//ͨ��װ����C���ʹ���
	decoratorC->Decorator::operation();
	decoratorC->DecoratorB::operation();
	decoratorC->operation();
	

	system("pause");
	return 0;
}