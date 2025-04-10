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

//˽�л����캯���������������������캯������ֵ������ʹ�䲻�ܴ���ʵ��
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