#include <iostream>
#include "CMyList.h"

using namespace std;

int main() {
	int choose(0);

	int g, c;
	cout << "�г� �� ����" << endl;
	cout << "�г� : ";
	cin >> g;
	cout << "�� : ";
	cin >> c;
	CMyListEx* List = new CMyListEx(g, c);

	while (1) {
		List->Menu();
		cin >> choose;

		switch (choose) {
		case 0:
			List->Unlock();
			cout << "���α׷� ����" << endl;
			return 0;
		case 1:
			List->Insert();
			break;
		case 2:
			List->Print();
			break;
		case 3:
			List->Delete();
			break;
		case 4:
			List->GetInfo();
			break;
		default:
			cout << "���Է� �ʿ�" << endl;
		}
	}
}