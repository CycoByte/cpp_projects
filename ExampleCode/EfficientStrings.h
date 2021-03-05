#pragma once

#include <string>

class EfficientStrings
{
public:
	EfficientStrings(const char * val) : m_Val(val) {}

	std::string_view getSubstring(int startIndex, int endIndex) 
	{
		//std::string_view does not create a new string thus allocating new memory on heap,
		//this simply returns a pointer to the beginning and end of the new string using the existing memory of the initial string
		//std::string substring = m_Val.substr(startIndex, endIndex); allocates memory on head for substring
		return std::string_view(m_Val + startIndex, endIndex);
	}
	

private: 
	const char* m_Val;
	
};

