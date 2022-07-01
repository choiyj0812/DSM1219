#pragma warning(disable:4996)
#pragma warning(disable:6001)
#include "CMyString.h"
#include <string.h>
#include <iostream>

CMyString::CMyString() :m_nLength(0), m_pszData(nullptr)
{
}

CMyString::CMyString(const CMyString& rkr)
{
	SetString(rkr.m_pszData);
}

CMyString& CMyString::operator=(const CMyString& rkr)
{
	if (m_pszData) delete[] m_pszData;
	SetString(rkr.m_pszData);
	return *this;
}

CMyString::CMyString(const char* str)
{
	SetString(str);
}

CMyString::operator char*() const
{
	return this->m_pszData;
}

CMyString::CMyString(CMyString&& rhs) noexcept
{
	std::cout << "CMyString 이동생성자 호출 " << std::endl;

	this->m_pszData = rhs.m_pszData;
	this->m_nLength = rhs.m_nLength;

	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString& CMyString::operator=(CMyString&& rhs) noexcept
{
	this->m_nLength = rhs.m_nLength;
	this->m_pszData = rhs.m_pszData;

	rhs.m_nLength = 0;
	rhs.m_pszData = nullptr;

	return *this;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	CMyString tmp(*this);
	tmp.Append(rhs.m_pszData);
	return tmp;
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
	Append(rhs.m_pszData);
	return *this;
}

CMyString::~CMyString()
{
	Release();
}


int CMyString::SetString(const char* pszParam)
{
	m_nLength = strlen(pszParam);
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);
	return 0;
}


const char* CMyString::GetString() const
{
	if (m_nLength == 0) {
		return "CMyString is Empty\n";
	}
	return m_pszData;
}


void CMyString::Release()
{
	delete[] m_pszData;
	m_pszData = nullptr;
	m_nLength = 0;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	if (pszParam == nullptr)
		return 0;
	int nLenCur = m_nLength;
	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;
	if (m_pszData == nullptr)
	{
		SetString(pszParam);
		return m_nLength;
	}
	char* pszResult = new char[nLenCur + nLenParam + 1];
	strcpy(pszResult, m_pszData);
	strcpy(pszResult + nLenCur, pszParam);
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;
	return m_nLength;
}
