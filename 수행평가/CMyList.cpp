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
	cout << "0 종료" << endl;
	cout << "1 등록" << endl;
	cout << "2 출력" << endl;
	cout << "3 삭제" << endl;
	line();
	cout << "메뉴 선택 : ";
	return;
}

void CMyList::Insert()
{
	Node* N = new Node;
	N->Left = nullptr;
	N->Right = nullptr;
	Input(N);

	//리스트가 비어있을 때
	if (this->Head == nullptr) {
		this->Head = N;
		this->Tail = N;
		cout << "등록 완료" << endl;
		return;
	}

	//같은 학번이 있을 때
	if (this->Search(N) == false) {
		cout << "같은 학번이 존재합니다." << endl;
		return;
	}

	//맨 앞에 추가
	if (this->Head->_Num > N->_Num) {
		N->Right = this->Head;
		this->Head->Left = N;
		this->Head = N;
		cout << "등록 완료" << endl;
		return;
	}

	//맨 뒤에 추가
	if (this->Tail->_Num < N->_Num) {
		N->Left = this->Tail;
		this->Tail->Right = N;
		this->Tail = N;
		cout << "등록 완료" << endl;
		return;
	}

	//중간에 추가
	Node* tmp = this->Head;
	while (tmp != nullptr) {
		if (tmp->_Num > N->_Num) {
			N->Left = tmp->Left;
			N->Right = tmp;
			tmp->Left->Right = N;
			tmp->Left = N;
			cout << "등록 완료" << endl;
			return;
		}
		tmp = tmp->Right;
	}
	return;
}

void CMyList::Delete()
{
	//리스트가 비어있을 때
	if (this->Head == nullptr) {
		cout << "리스트가 비어있습니다." << endl;
		cout << "정보를 등록 후 실행해주십시오." << endl;
		return;
	}

	int Delete_num;
	cout << "삭제할 노드의 학번은? : ";
	cin >> Delete_num;

	//남은 노드가 1개일 때
	if (this->Head == this->Tail) {
		delete this->Head;
		this->Head = this->Tail = nullptr;
		cout << "삭제 완료" << endl;
		return;
	}

	Node* Del;

	//맨 앞의 노드 삭제
	if (this->Head->_Num == Delete_num) {
		Del = this->Head;
		Del->Right->Left = nullptr;
		this->Head = Del->Right;
		delete Del;
		Del = nullptr;
		cout << "삭제 완료" << endl;
		return;
	}

	//맨 뒤의 노드 삭제
	if (this->Tail->_Num == Delete_num) {
		Del = this->Tail;
		Del->Left->Right = nullptr;
		this->Tail = Del->Left;
		delete Del;
		Del = nullptr;
		cout << "삭제 완료" << endl;
		return;
	}

	//중간의 노드 삭제
	Del = this->Head->Right;
	while (Del != nullptr) {
		if (Del->_Num == Delete_num) {
			Del->Left->Right = Del->Right;
			Del->Right->Left = Del->Left;
			delete Del;
			Del = nullptr;
			cout << "삭제 완료" << endl;
			return;
		}
		if (Del->_Num > Delete_num) {
			cout << "삭제 실패" << endl;
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
		cout << pre->_Num << "번 노드 해제" << endl;
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
		cout << "등록된 정보가 존재하지 않습니다." << endl;
		return;
	}

	Node* tmp = this->Head;
	while (1) {
		if (tmp == nullptr) break;
		line();
		cout << " 번호 : " << tmp->_Num << endl;
		cout << " 국어 : " << tmp->_Korean << endl;
		cout << " 수학 : " << tmp->_Math << endl;
		cout << " 사회 : " << tmp->_Social << endl;
		cout << " 과학 : " << tmp->_Science << endl;
		cout << " 영어 : " << tmp->_English << endl;
		cout << "전공1 : " << tmp->_Major1 << endl;
		cout << "전공2 : " << tmp->_Major2 << endl;
		tmp = tmp->Right;
	}
	return;
}

void CMyList::Print_Class() const
{
	line();
	cout << this->_Grade << "학년 ";
	cout << this->_Class << "반\n";
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
	cout << "  번 호   : ";
	cin >> N->_Num;

	cout << " 국어점수 : ";
	cin >> N->_Korean;

	cout << " 수학점수 : ";
	cin >> N->_Math;

	cout << " 사회점수 : ";
	cin >> N->_Social;

	cout << " 과학점수 : ";
	cin >> N->_Science;

	cout << " 영어점수 : ";
	cin >> N->_English;

	cout << "전공1점수 : ";
	cin >> N->_Major1;

	cout << "전공2점수 : ";
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
		cout << "현재 등록된 정보가 없습니다." << endl;
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
	cout << "등록된 정보 갯수 : " << this->length << endl;
	cout << this->_Grade << "학년 " << this->_Class << "반" << endl;
	cout << " 국어 평균 : " << Class_Average[0] / this->length << endl;
	cout << " 수학 평균 : " << Class_Average[1] / this->length << endl;
	cout << " 사회 평균 : " << Class_Average[2] / this->length << endl;
	cout << " 과학 평균 : " << Class_Average[3] / this->length << endl;
	cout << " 영어 평균 : " << Class_Average[4] / this->length << endl;
	cout << "전공1 평균 : " << Class_Average[5] / this->length << endl;
	cout << "전공2 평균 : " << Class_Average[6] / this->length << endl;
	return;
}

void CMyListEx::Menu()
{
	line();
	cout << "List Menu" << endl;
	cout << "0 종료" << endl;
	cout << "1 등록" << endl;
	cout << "2 출력" << endl;
	cout << "3 삭제" << endl;
	cout << "4 정보" << endl;
	line();
	cout << "메뉴 선택 : ";
	return;
}

void CMyListEx::Insert()
{
	Node* N = new Node;
	N->Left = nullptr;
	N->Right = nullptr;
	Input(N);

	//리스트가 비어있을 때
	if (this->length == 0) {
		this->Head = N;
		this->Tail = N;
		this->length++;
		cout << "등록 완료" << endl;
		return;
	}

	//같은 학번이 있을 때
	if (this->Search(N) == false) {
		cout << "같은 학번이 존재합니다." << endl;
		return;
	}

	//맨 앞에 추가
	if (this->Head->_Num > N->_Num) {
		N->Right = this->Head;
		this->Head->Left = N;
		this->Head = N;
		this->length++;
		cout << "등록 완료" << endl;
		return;
	}

	//맨 뒤에 추가
	if (this->Tail->_Num < N->_Num) {
		N->Left = this->Tail;
		this->Tail->Right = N;
		this->Tail = N;
		this->length++;
		cout << "등록 완료" << endl;
		return;
	}

	//중간에 추가
	Node* tmp = this->Head;
	for (int i = 1; i <= this->length; i++) {
		if (tmp->_Num > N->_Num) {
			N->Left = tmp->Left;
			N->Right = tmp;
			tmp->Left->Right = N;
			tmp->Left = N;
			this->length++;
			cout << "등록 완료" << endl;
			return;
		}
		tmp = tmp->Right;
	}
	return;
}

void CMyListEx::Delete()
{
	//리스트가 비어있을 때
	if (this->length == 0) {
		cout << "리스트가 비어있습니다." << endl;
		cout << "정보를 등록 후 실행해주십시오." << endl;
		return;
	}

	int Delete_num;
	cout << "삭제할 노드의 번호은? : ";
	cin >> Delete_num;

	//남은 노드가 1개일 때
	if (this->length == 1) {
		delete this->Head;
		this->Head = this->Tail = nullptr;
		this->length--;
		cout << "삭제 완료" << endl;
		return;
	}

	Node* Del;

	//맨 앞의 노드 삭제
	if (this->Head->_Num == Delete_num) {
		Del = this->Head;
		Del->Right->Left = nullptr;
		this->Head = Del->Right;
		delete Del;
		Del = nullptr;
		this->length--;
		cout << "삭제 완료" << endl;
		return;
	}

	//맨 뒤의 노드 삭제
	if (this->Tail->_Num == Delete_num) {
		Del = this->Tail;
		Del->Left->Right = nullptr;
		this->Tail = Del->Left;
		delete Del;
		Del = nullptr;
		this->length--;
		cout << "삭제 완료" << endl;
		return;
	}

	//중간의 노드 삭제
	Del = this->Head->Right;
	for (int i = 1; i < this->length; i++) {
		if (Del->_Num == Delete_num) {
			Del->Left->Right = Del->Right;
			Del->Right->Left = Del->Left;
			delete Del;
			Del = nullptr;
			this->length--;
			cout << "삭제 완료" << endl;
			return;
		}
		if (Del->_Num > Delete_num) {
			cout << "삭제 실패" << endl;
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
		cout << "해제할 데이터 없음" << endl;
		return;
	}

	Node* pre = this->Head;
	Node* temp = pre->Right;
	for(int i = 0; i < this->length; i++){
		cout << pre->_Num << "번 정보 영구 삭제" << endl;
		delete pre;
		pre = temp;
		temp = temp->Right;
	}
	this->Head = nullptr;
	this->Tail = nullptr;
	return;
}
