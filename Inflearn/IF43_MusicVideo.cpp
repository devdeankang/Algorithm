#include <iostream>
#include <vector>

using namespace std;

void solution43()
{
	int n, division, answer = 0;
	vector<int> songs;
	int length = 0;
	int max = -1;

	cin >> n >> division;

	for (int i = 0; i < n; i++)
	{
		int song;
		cin >> song;
		songs.push_back(song);
		length += song;
		if (max < song)
			max = song;
	}

	int start = 1;
	int end = length;	
	
	while (start != (start+end)/2)
	{
		int currentLength = 0;
		int pivot = (start + end) / 2;
		int dvdCount = 0;

		for (int i = 0; i < songs.size(); i++)
		{
			if (currentLength + songs[i] > pivot)
			{
				dvdCount++;
				currentLength = 0;
			}
			currentLength += songs[i];

			if (dvdCount > division) break;
		}

		if (dvdCount+1 <= division)
		{
			answer = pivot;
			end = pivot;
		}
		else
		{
			start = pivot;
			end = answer;
		}
	}
	answer = answer < max ? max : answer;
	cout << answer;
}