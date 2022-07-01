#pragma once

struct Node {
	int _Num;
	double _Korean, _Math, _Social, _Science;
	double _English, _Major1, _Major2;
	Node* Left;
	Node* Right;
};

void line();
void Input(Node* N);

class CMyList
{
protected:
	//���� ��� ����
	//������ ����(�޸� �����Ҵ� �� ����)
	Node* Head;
	Node* Tail;
	int _Grade;
	int _Class;

public:
	//������ ����ȭ
	CMyList();
	CMyList(int g, int c);

	//�޼��� ������
	void Menu();
	void Insert();
	void Delete();
	//�����Լ�
	virtual void Unlock();
	//��� �Լ� ���ȭ
	void Print() const;
	void Print_Class() const;
	bool Search(Node* rn) const;
	//������ ��������
};

class CMyListEx :public CMyList {
private:
	int length;
	double Class_Average[7];
public:
	CMyListEx(int g, int c);

	void GetInfo();
	//�޼��� ������
	void Menu();
	void Insert();
	void Delete();
	//��� �����Լ�
	virtual void Unlock() override;
};
