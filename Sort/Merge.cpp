#include <queue>
#include "Merge.h"

namespace algorithm
{
	template <typename T>
	void Merge<T>::Sorting(std::function<bool(T a, T b)> comparator) override
	{
		if (comparator != nullptr)
		{
			this->sorting(this->m_list, this->m_count, comparator);
		}
		else if (true) //비교연산자가 구현되어 있는지 확인.
		{
			this->sorting(this->m_list, this->m_count, [](T a, T b) -> bool { return a < b; });
		}
		else
		{
			//비교 연산자가 구현되어 있지 않다면 오류 출력
		}
	}


	template <typename T>
	void Merge<T>::Sorting(T list[], const size_t length, std::function<bool(T a, T b)> comparator) override
	{
		if (comparator != nullptr)
		{
			this->sorting(list, static_cast<int>(length), comparator);
		}
		else if (true) //비교연산자가 구현되어 있는지 확인.
		{
			this->sorting(list, static_cast<int>(length), [](T a, T b) -> bool { return a < b; });
		}
		else
		{
			//비교 연산자가 구현되어 있지 않다면 오류 출력
		}
	}


	template <typename T>
	void Merge<T>::sorting(T list[], const int length, std::function<bool(T a, T b)> comparator)
	{
		T* temp = new T[length];
		assert(temp != nullptr);

		int mid, right, l, r, k;

		for (int width = 1; width < length; width *= 2)
		{
			for (int i = 0; i < length; i += 2 * width)
			{
				mid = std::min(i + width, length);
				right = std::min(i + 2 * width, length);
				l = i;
				r = mid;
				k = i;

				while (l < mid && r < right)
				{
					if (comparator(list[l], list[r]))
					{
						temp[k++] = list[l++];
					}
					else
					{
						temp[k++] = list[r++];
					}
				}

				while (l < mid)
				{
					temp[k++] = list[l++];
				}

				while (r < right)
				{
					temp[k++] = list[r++];
				}
			}

			for (int i = 0; i < length; ++i)
			{
				list[i] = temp[i];
			}
		}

		delete[] temp;
	}

}
