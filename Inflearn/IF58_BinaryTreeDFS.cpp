#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 완전이진트리
// 1
// 2 3
// 45 67

// preorder traverse
void PreOrder(int n)
{
	if (n > 7) return;
	else {
		cout << n << " ";
		PreOrder(n * 2);
		PreOrder(n * 2 + 1);
	}
}

// inorder traverse
void InOrder(int n)
{
	if (n > 7) return;
	else 
	{
		InOrder(n * 2);
		cout << n << " ";
		InOrder(n * 2 + 1);
	}
}

// postorder traverse
void PostOrder(int n)
{
	if (n > 7) return;
	else 
	{
		PostOrder(n * 2);
		PostOrder(n * 2 + 1);
		cout << n << " ";
	}
}


void solution58()
{
	PreOrder(1);
	cout << endl;
	InOrder(1);	

	cout << endl;
	PostOrder(1);
}