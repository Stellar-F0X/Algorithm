#include <iostream>
#include <random>
#include <concepts>
#include "Sort.h"

namespace algorithm
{
	template <typename T> 
	Sort<T>::Sort(size_t size, T* list)
	{
		this->m_count = size;

		if (list == nullptr)
		{
			this->m_list = new T[size];
		}
		else
		{
			this->m_list = list;
		}

		assert(this->m_list != nullptr);
	}

	template <typename T>
	Sort<T>::~Sort()
	{
		delete[] m_list;
	}

	template <typename T>
	T* Sort<T>::GetList() const
	{
		return m_list;
	}

	template <typename T>
	int Sort<T>::GetLength() const
	{
		return m_count;
	}

	template <typename T>
	void Sort<T>::Shuffle()
	{
		int idx = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, m_count - 1);

		for (int i = 0; i < m_count; ++i)
		{
			idx = dist(gen);
			std::swap(m_list[i], m_list[idx]);
		}
	}

	template <typename T>
	void Sort<T>::Print(std::function<void(T)> printer) const
	{
		assert(printer != nullptr);

		for (int i = 0; i < m_count; ++i)
		{
			printer(m_list[i]);
		}
	}

	template <typename T>
	void Sort<T>::Print(const char* end) const
	{
		for (int i = 0; i < m_count; ++i)
		{
			std::cout << m_list[i] << end;
		}
	}
}
