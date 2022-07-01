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
	//정적 멤버 변수
	//포인터 변수(메모리 동적할당 및 해제)
	Node* Head;
	Node* Tail;
	int _Grade;
	int _Class;

public:
	//생성자 다중화
	CMyList();
	CMyList(int g, int c);

	//메서드 재정의
	void Menu();
	void Insert();
	void Delete();
	//가상함수
	virtual void Unlock();
	//멤버 함수 상수화
	void Print() const;
	void Print_Class() const;
	bool Search(Node* rn) const;
	//연산자 다중정의
};

class CMyListEx :public CMyList {
private:
	int length;
	double Class_Average[7];
public:
	CMyListEx(int g, int c);

	void GetInfo();
	//메서드 재정의
	void Menu();
	void Insert();
	void Delete();
	//상속 가상함수
	virtual void Unlock() override;
};
