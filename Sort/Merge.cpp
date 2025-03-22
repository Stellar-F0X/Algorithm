#include <vector>
#include <random>

using namespace std;

void merge(vector<int>& ary, vector<int>& tmp, int lt, int mid, int rt)
{
	int p1 = lt, p2 = mid + 1, p3 = lt;

	while (p1 <= mid && p2 <= rt)
	{
		if (ary[p1] < ary[p2])
		{
			tmp[p3++] = ary[p1++];
		}
		else
		{
			tmp[p3++] = ary[p2++];
		}
	}

	while (p1 <= mid)
	{
		tmp[p3++] = ary[p1++];
	}

	while (p2 <= rt)
	{
		tmp[p3++] = ary[p2++];
	}

	for (int i = lt; i <= rt; ++i)
	{
		ary[i] = tmp[i];
	}
}


void divide(vector<int>& ary, int lt, int rt)
{
	vector<int> tmp(ary.size());

	if (lt < rt)
	{
		int mid = (lt + rt) / 2;

		divide(ary, lt, mid);
		divide(ary, mid + 1, rt);

		merge(ary, tmp, lt, mid, rt);
	}
}


int main() {
	int n = 10;
	vector<int> ary(n);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	for (int i = 0; i < 10; ++i) {
		ary[i] = i + 1;
		int idx = dis(gen) % (i + 1);
		swap(ary[i], ary[idx]);
	}

	divide(ary, 0, n - 1);

	for (int i = 0; i < 10; ++i) {
		printf("%d ", ary[i]);
	}
	return 0;
}