#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GetAverageValue(vector<int> gridRow)
{
	float sum = 0;

	for (int value : gridRow)
		sum += (float)value;

	return round(sum / gridRow.size());
}

int GetClosestValue(vector<int> gridRow, int average)
{
	int diff = average;
	int closestValue = 0;

	for (int value : gridRow)
	{
		int difference = abs(value - average);

		if (difference == diff)
		{
			if (value > closestValue)
				closestValue = value;
		}
		else if (difference < diff)
		{
			closestValue = value;
			diff = difference;
		}
	}

	return closestValue;
}

void solution48()
{
	vector<vector<int>> grid(9, vector<int>(9, 0));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int temp = 0;
			cin >> temp;
			grid[i][j] = temp;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		int average = GetAverageValue(grid[i]);
		int closestValue = GetClosestValue(grid[i], average);

		cout << average << " " << closestValue << endl;
	}	
}