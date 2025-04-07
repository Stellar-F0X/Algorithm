#include "Merge.h"
#include <iostream>

using namespace std;
using namespace algorithm;

int main()
{
	int n = 10;
	int arr[10];

	for (int i=0; i<n; ++i)
	{
		arr[i] = i + 1;
	}

	Merge<int> m(n, arr);
	m.Print();
	return 0;
}