#pragma once

#include<cstring>
#include<cstdio>
#include<memory>

class String {

private:
	size_t m_Len = 0;
	char* m_Str = nullptr;

public:

	String() = default;

	//constructor
	String(const char* str)
	{
		printf("String Created!\n");
		m_Len = strlen(str);
		m_Str = new char[m_Len];
		std::memcpy(m_Str, str, m_Len);
	}

	//copy constructor
	String(const String& other)
	{
		printf("String Copied!\n");
		if (this != &other)
		{
			if (m_Str != nullptr)
			{
				delete[] m_Str;
 			}
			this->m_Len = other.m_Len;
			this->m_Str = new char[m_Len];
			std::memcpy(m_Str, other.m_Str, m_Len);
		}
	}

	//copy = operator
	String operator = (const String& other)
	{
		printf("String Copied! =\n");
		if (this != &other)
		{
			if (m_Str != nullptr)
			{
				delete[] m_Str;
			}
			this->m_Len = other.m_Len;
			this->m_Str = new char[m_Len];
			std::memcpy(m_Str, other.m_Str, m_Len);
		}
		return *this;
	}

	//move constructor
	String(String&& other) noexcept
	{
		printf("String Moved!\n");
		if (this != &other)
		{
			if (m_Str != nullptr)
			{
				delete[] m_Str;
			}
			this->m_Len = std::move(other.m_Len);
			this->m_Str = other.m_Str;
			
			other.m_Str = nullptr;
			other.m_Len = 0;
		}
	}

	//move = operator
	String& operator = (String&& other) noexcept
	{
		printf("String Moved! =\n");
		if (this != &other)
		{
			if (m_Str != nullptr)
			{
				delete[] m_Str;
			}
			this->m_Len = std::move(other.m_Len);
			this->m_Str = other.m_Str;

			other.m_Str = nullptr;
			other.m_Len = 0;
		}
		return *this;
	}

	void PrintStr()
	{
		if (m_Len == 0)
		{
			printf("Nothing to print!\n");
			return;
		}
		for (size_t i = 0; i < m_Len; i++)
		{
			printf("%c", m_Str[i]);
		}
		printf("\n");
	}

	virtual ~String()
	{
		printf("String Destroyed!\n");
		delete[] m_Str;
		m_Len = 0;
	}

};
