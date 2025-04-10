#pragma once

template<typename T>
class Singleton
{
public:
	static T* getInstance() {
		if (m_instance == nullptr) {
			m_instance = new T();
		}
		return m_instance;
	};

//私有化构造函数、析构函数、拷贝构造函数、赋值函数。使其不能创建实列
private:
	Singleton() {T* Singleton<T>::m_instance = nullptr; };
	~Singleton() {
		if (m_instance != nullptr) {
			delete m_instance;
		}
	};
	Singleton(const Singleton<T>&) {};
	Singleton<T>& operator=(const Singleton<T>&) {};

private:
	static T* m_instance;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;