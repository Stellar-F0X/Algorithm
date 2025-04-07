#pragma once
#include <functional>
#include <cassert>

namespace algorithm
{
	template<typename T>
	class Sort
	{
	protected:
		T* m_list;
		int m_count;

	public:
		Sort(size_t size, T list[] = nullptr);
		Sort(Sort&& obj) = delete;
		Sort(Sort& obj) = delete;
		~Sort();

	public:
		T* GetList() const;
		int GetLength() const;
		void Shuffle();
		void Print(const char* end = "") const;
		void Print(std::function <void(T e)> printer) const;

	public:
		void virtual Sorting(std::function<bool(T a, T b)> comparator = nullptr) = 0;
		void virtual Sorting(T list[], const size_t length, std::function <bool(T a, T b)> comparator = nullptr) = 0;
	};
}