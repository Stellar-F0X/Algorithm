#pragma once
#include "Sort.h"

namespace algorithm
{
    template<typename T>
    class Merge : public Sort<T>
    {
    public:
        // Merge 생성자에서 Sort<T> 생성자 호출
        Merge(size_t size, T list[] = nullptr) : Sort<T>(size, list) { }

        void Sorting(std::function<bool(T a, T b)> comparator = nullptr) override;
        void Sorting(T list[], const size_t length, std::function<bool(T a, T b)> comparator = nullptr) override;

    private:
        void sorting(T list[], const int length, std::function<bool(T a, T b)> comparator = nullptr);
    };

}