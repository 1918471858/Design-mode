#include <iostream>

using namespace std;

//抽象算法
class Sort 
{
public:
	virtual ~Sort() = default;
	virtual int sort(int left, int right) = 0;
};

//具体算法
class add :public Sort
{
	int sort(int left, int right) override
	{
		return left + right;
	}
};

class sub :public Sort
{
	int sort(int left, int right) override
	{
		return left - right;
	}
};

class mul :public Sort
{
	int sort(int left, int right) override
	{
		return left * right;
	}
};

class divi :public Sort
{
	int sort(int left, int right) override
	{
		return left / right;
	}
};

//策略容器
class StrategyVec
{
public:
	StrategyVec() { m_sort = nullptr; };
	void setSort(Sort* sort) { m_sort = sort; };
	int getReturn(int left, int right) {
		if (m_sort != nullptr)
			return m_sort->sort(left, right);
		else
			return -10086;
	}
private:
	Sort* m_sort;
};


int main(int argc, char* argv[])
{
	int left, right;
	char key;
	StrategyVec* strategy = new StrategyVec();
	add* _add = new add();
	sub* _sub = new sub();
	mul* _mul = new mul();
	divi* _divi = new divi();

	while (1) 
	{
		cin >> left >> key >> right;
		switch (key)
		{
		case '+':
			strategy->setSort(_add);
			cout << strategy->getReturn(left, right) << endl;
			break;
		case '-':
			strategy->setSort(_sub);
			cout << strategy->getReturn(left, right) << endl;
			break;
		case '*':
			strategy->setSort(_mul);
			cout << strategy->getReturn(left, right) << endl;
			break;
		case '/':
			strategy->setSort(_divi);
			cout << strategy->getReturn(left, right) << endl;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}