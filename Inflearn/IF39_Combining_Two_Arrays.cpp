#include <iostream>

using namespace std;

void solution39()
{
	int aSize = 0, bSize = 0;
	
	cin >> aSize;
	int* a = new int[aSize];
	for (int i = 0; i < aSize; i++)
	{
		cin >> a[i];
	}

	cin >> bSize;
	int* b = new int[bSize];
	for (int i = 0; i < bSize; i++)
	{
		cin >> b[i];
	}

	int size = aSize + bSize;
	int* result = new int[size];
	int index = 0;
	int j = 0;
	int i = 0;
	while (index < size)
	{
		if (i >= aSize)
		{
			result[index] = b[j++];
		}
		else if (j >= bSize)
		{
			result[index] = a[i++];
		}

		else if (a[i] < b[j])
		{
			result[index] = a[i++];
		}
		else
		{
			result[index] = b[j++];
		}
		index++;
	}

	for (int k = 0; k < size; k++)
	{
		cout << result[k] << " ";
	}

	delete[] result;
}