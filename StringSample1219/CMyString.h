#pragma once
class CMyString
{
public:
	CMyString();
	//#3
	CMyString(const CMyString& rkr);
	CMyString& operator=(const CMyString& rkr);
	//#4
	explicit CMyString(const char* str);
	operator char*() const;
	//#5
	CMyString(CMyString&& rhs) noexcept;
	//#6
	CMyString& operator=(CMyString&& rhs) noexcept;
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	~CMyString();
private:
	char* m_pszData;
	int m_nLength;
public:
	//#2
	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	//#6
	int GetLength() const;
	int Append(const char* pszParam);
};