#include <iostream>
#include <string>

using namespace std;

//组件接口
class Component 
{
public:
	virtual void operation() = 0;
	virtual ~Component() = default;
};

//具体组件A
class ComponentA :public Component
{
public:
	virtual void operation()override {
		cout << "组件A的功能" << endl;
	}
};

//抽象装饰器类
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

//具体装饰器B
class DecoratorB :public Decorator
{
public:
	DecoratorB(Component* com) :Decorator(com) {};
	virtual void operation() override
	{
		cout << "装饰器B为组件添加新功能B" << endl;
	}
	virtual ~DecoratorB() = default;
};

//具体装饰器C
class DecoratorC :public DecoratorB
{
public:
	DecoratorC(Component* com) :DecoratorB(com) {};
	virtual void operation() override
	{
		cout << "装饰器C为组件添加新功能C" << endl;
	}
	virtual ~DecoratorC() = default;
};

int main(int argc, char* argv[])
{
	//创建组件A并访问功能
	ComponentA* componentA = new ComponentA();
	componentA->operation();
	cout << endl;

	//创建装饰器B并装饰组件A
	DecoratorB* decoratorB = new DecoratorB(componentA);
	//通过装饰器B访问功能
	decoratorB->Decorator::operation();
	decoratorB->operation();
	cout << endl;

	//创建装饰器C并装饰组件A
	DecoratorC* decoratorC = new DecoratorC(componentA);
	//通过装饰器C访问功能
	decoratorC->Decorator::operation();
	decoratorC->DecoratorB::operation();
	decoratorC->operation();
	

	system("pause");
	return 0;
}