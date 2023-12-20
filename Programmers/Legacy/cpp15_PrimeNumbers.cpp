#include <iostream>
#include <cmath>

using namespace std;

// cpp algorithm
// 15. 소수의 개수
// 자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요. 만약 20이 입력되면 1부터 20까지의 소수는 2,3,5,7,11,13,17,19로 총 8개 입니다. 제한시간은 1초입니다.


int main(){
	// txt파일 읽어와서 출력할 때 
	//freopen("input.txt", "rt", stdin);
	int n;
	int count = 0;
	bool isPrimeNum = true;			
	cin >> n;
	
	for(int i=2; i<=n; i++)
	{
		isPrimeNum = true;
		
		for(int j=2; j*j<=i; j++)
		{
			if(i%j==0)
			{
				isPrimeNum = false;
				break;
			}
		}
		
		if(isPrimeNum == true) count++;
	}
	
	cout << count << endl;
	return 0;
}
