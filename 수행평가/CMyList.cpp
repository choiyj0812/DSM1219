#include "CMyList.h"
#include <iostream>

using namespace std;

CMyList::CMyList()
{
	Head = nullptr;
	Tail = nullptr;
	_Grade = 0;
	_Class = 0;
}

CMyList::CMyList(int g, int c)
{
	Head = nullptr;
	Tail = nullptr;
	_Grade = g;
	_Class = c;
}

void CMyList::Menu()
{
	line();
	cout << "List Menu" << endl;
	cout << "0 ����" << endl;
	cout << "1 ���" << endl;
	cout << "2 ���" << endl;
	cout << "3 ����" << endl;
	line();
	cout << "�޴� ���� : ";
	return;
}

void CMyList::Insert()
{
	Node* N = new Node;
	N->Left = nullptr;
	N->Right = nullptr;
	Input(N);

	//����Ʈ�� ������� ��
	if (this->Head == nullptr) {
		this->Head = N;
		this->Tail = N;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//���� �й��� ���� ��
	if (this->Search(N) == false) {
		cout << "���� �й��� �����մϴ�." << endl;
		return;
	}

	//�� �տ� �߰�
	if (this->Head->_Num > N->_Num) {
		N->Right = this->Head;
		this->Head->Left = N;
		this->Head = N;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//�� �ڿ� �߰�
	if (this->Tail->_Num < N->_Num) {
		N->Left = this->Tail;
		this->Tail->Right = N;
		this->Tail = N;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//�߰��� �߰�
	Node* tmp = this->Head;
	while (tmp != nullptr) {
		if (tmp->_Num > N->_Num) {
			N->Left = tmp->Left;
			N->Right = tmp;
			tmp->Left->Right = N;
			tmp->Left = N;
			cout << "��� �Ϸ�" << endl;
			return;
		}
		tmp = tmp->Right;
	}
	return;
}

void CMyList::Delete()
{
	//����Ʈ�� ������� ��
	if (this->Head == nullptr) {
		cout << "����Ʈ�� ����ֽ��ϴ�." << endl;
		cout << "������ ��� �� �������ֽʽÿ�." << endl;
		return;
	}

	int Delete_num;
	cout << "������ ����� �й���? : ";
	cin >> Delete_num;

	//���� ��尡 1���� ��
	if (this->Head == this->Tail) {
		delete this->Head;
		this->Head = this->Tail = nullptr;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	Node* Del;

	//�� ���� ��� ����
	if (this->Head->_Num == Delete_num) {
		Del = this->Head;
		Del->Right->Left = nullptr;
		this->Head = Del->Right;
		delete Del;
		Del = nullptr;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	//�� ���� ��� ����
	if (this->Tail->_Num == Delete_num) {
		Del = this->Tail;
		Del->Left->Right = nullptr;
		this->Tail = Del->Left;
		delete Del;
		Del = nullptr;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	//�߰��� ��� ����
	Del = this->Head->Right;
	while (Del != nullptr) {
		if (Del->_Num == Delete_num) {
			Del->Left->Right = Del->Right;
			Del->Right->Left = Del->Left;
			delete Del;
			Del = nullptr;
			cout << "���� �Ϸ�" << endl;
			return;
		}
		if (Del->_Num > Delete_num) {
			cout << "���� ����" << endl;
			Del = nullptr;
			return;
		}
	}
	return;
}

void CMyList::Unlock()
{
	Node* pre = this->Head;
	Node* temp = pre->Right;
	while (pre != nullptr) {
		cout << pre->_Num << "�� ��� ����" << endl;
		delete pre;
		pre = temp;
		temp = temp->Right;
	}
	this->Head = nullptr;
	this->Tail = nullptr;
	return;
}

void CMyList::Print() const
{
	this->Print_Class();

	if (this->Head == nullptr) {
		cout << "��ϵ� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}

	Node* tmp = this->Head;
	while (1) {
		if (tmp == nullptr) break;
		line();
		cout << " ��ȣ : " << tmp->_Num << endl;
		cout << " ���� : " << tmp->_Korean << endl;
		cout << " ���� : " << tmp->_Math << endl;
		cout << " ��ȸ : " << tmp->_Social << endl;
		cout << " ���� : " << tmp->_Science << endl;
		cout << " ���� : " << tmp->_English << endl;
		cout << "����1 : " << tmp->_Major1 << endl;
		cout << "����2 : " << tmp->_Major2 << endl;
		tmp = tmp->Right;
	}
	return;
}

void CMyList::Print_Class() const
{
	line();
	cout << this->_Grade << "�г� ";
	cout << this->_Class << "��\n";
}

bool CMyList::Search(Node* rn) const
{
	Node* tmp = this->Head;
	do {
		if (tmp->_Num == rn->_Num)
			return false;
		if (tmp->_Num > rn->_Num)
			return true;
		tmp = tmp->Right;
	} while (tmp != nullptr);
	return true;
}

void line() {
	for (int i = 0; i < 25; i++)
		cout << '-';
	cout << endl;
	return;
}

void Input(Node* N)
{
	cout << "  �� ȣ   : ";
	cin >> N->_Num;

	cout << " �������� : ";
	cin >> N->_Korean;

	cout << " �������� : ";
	cin >> N->_Math;

	cout << " ��ȸ���� : ";
	cin >> N->_Social;

	cout << " �������� : ";
	cin >> N->_Science;

	cout << " �������� : ";
	cin >> N->_English;

	cout << "����1���� : ";
	cin >> N->_Major1;

	cout << "����2���� : ";
	cin >> N->_Major2;

	return;
}

CMyListEx::CMyListEx(int g, int c)
{
	Head = nullptr;
	Tail = nullptr;
	_Grade = g;
	_Class = c;
	length = 0;
	for (int i = 0; i < 7; i++)
		Class_Average[i] = 0.0;
	return;
}

void CMyListEx::GetInfo()
{
	if (this->length == 0) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	Node* tmp = this->Head;
	for (int i = 0; i < this->length; i++) {
		this->Class_Average[0] += tmp->_Korean;
		this->Class_Average[1] += tmp->_Math;
		this->Class_Average[2] += tmp->_Social;
		this->Class_Average[3] += tmp->_Science;
		this->Class_Average[4] += tmp->_English;
		this->Class_Average[5] += tmp->_Major1;
		this->Class_Average[6] += tmp->_Major2;

		tmp = tmp->Right;
	}

	line();
	cout << "��ϵ� ���� ���� : " << this->length << endl;
	cout << this->_Grade << "�г� " << this->_Class << "��" << endl;
	cout << " ���� ��� : " << Class_Average[0] / this->length << endl;
	cout << " ���� ��� : " << Class_Average[1] / this->length << endl;
	cout << " ��ȸ ��� : " << Class_Average[2] / this->length << endl;
	cout << " ���� ��� : " << Class_Average[3] / this->length << endl;
	cout << " ���� ��� : " << Class_Average[4] / this->length << endl;
	cout << "����1 ��� : " << Class_Average[5] / this->length << endl;
	cout << "����2 ��� : " << Class_Average[6] / this->length << endl;
	return;
}

void CMyListEx::Menu()
{
	line();
	cout << "List Menu" << endl;
	cout << "0 ����" << endl;
	cout << "1 ���" << endl;
	cout << "2 ���" << endl;
	cout << "3 ����" << endl;
	cout << "4 ����" << endl;
	line();
	cout << "�޴� ���� : ";
	return;
}

void CMyListEx::Insert()
{
	Node* N = new Node;
	N->Left = nullptr;
	N->Right = nullptr;
	Input(N);

	//����Ʈ�� ������� ��
	if (this->length == 0) {
		this->Head = N;
		this->Tail = N;
		this->length++;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//���� �й��� ���� ��
	if (this->Search(N) == false) {
		cout << "���� �й��� �����մϴ�." << endl;
		return;
	}

	//�� �տ� �߰�
	if (this->Head->_Num > N->_Num) {
		N->Right = this->Head;
		this->Head->Left = N;
		this->Head = N;
		this->length++;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//�� �ڿ� �߰�
	if (this->Tail->_Num < N->_Num) {
		N->Left = this->Tail;
		this->Tail->Right = N;
		this->Tail = N;
		this->length++;
		cout << "��� �Ϸ�" << endl;
		return;
	}

	//�߰��� �߰�
	Node* tmp = this->Head;
	for (int i = 1; i <= this->length; i++) {
		if (tmp->_Num > N->_Num) {
			N->Left = tmp->Left;
			N->Right = tmp;
			tmp->Left->Right = N;
			tmp->Left = N;
			this->length++;
			cout << "��� �Ϸ�" << endl;
			return;
		}
		tmp = tmp->Right;
	}
	return;
}

void CMyListEx::Delete()
{
	//����Ʈ�� ������� ��
	if (this->length == 0) {
		cout << "����Ʈ�� ����ֽ��ϴ�." << endl;
		cout << "������ ��� �� �������ֽʽÿ�." << endl;
		return;
	}

	int Delete_num;
	cout << "������ ����� ��ȣ��? : ";
	cin >> Delete_num;

	//���� ��尡 1���� ��
	if (this->length == 1) {
		delete this->Head;
		this->Head = this->Tail = nullptr;
		this->length--;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	Node* Del;

	//�� ���� ��� ����
	if (this->Head->_Num == Delete_num) {
		Del = this->Head;
		Del->Right->Left = nullptr;
		this->Head = Del->Right;
		delete Del;
		Del = nullptr;
		this->length--;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	//�� ���� ��� ����
	if (this->Tail->_Num == Delete_num) {
		Del = this->Tail;
		Del->Left->Right = nullptr;
		this->Tail = Del->Left;
		delete Del;
		Del = nullptr;
		this->length--;
		cout << "���� �Ϸ�" << endl;
		return;
	}

	//�߰��� ��� ����
	Del = this->Head->Right;
	for (int i = 1; i < this->length; i++) {
		if (Del->_Num == Delete_num) {
			Del->Left->Right = Del->Right;
			Del->Right->Left = Del->Left;
			delete Del;
			Del = nullptr;
			this->length--;
			cout << "���� �Ϸ�" << endl;
			return;
		}
		if (Del->_Num > Delete_num) {
			cout << "���� ����" << endl;
			Del = nullptr;
			return;
		}
		Del = Del->Right;
	}
	return;
}

void CMyListEx::Unlock()
{
	if (this->length == 0) {
		cout << "������ ������ ����" << endl;
		return;
	}

	Node* pre = this->Head;
	Node* temp = pre->Right;
	for(int i = 0; i < this->length; i++){
		cout << pre->_Num << "�� ���� ���� ����" << endl;
		delete pre;
		pre = temp;
		temp = temp->Right;
	}
	this->Head = nullptr;
	this->Tail = nullptr;
	return;
}
