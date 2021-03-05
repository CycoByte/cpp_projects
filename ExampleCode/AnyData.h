#pragma once

#include<any> //use variant instead, its safer than any
#include<string>
#include<variant>

//Tutorials:
//https://www.youtube.com/watch?v=6uqU9Y578n4
//https://www.youtube.com/watch?v=7nPrUBNGRAk&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=79



enum class ErrCodezz {
	CZZ_NONE = 0,
	CZZ_NOT_FOUND,
	CZZ_PARSE_ERROR,
	CZZ_READ_ERROR,
};


class AnyData {

public:

	std::variant<std::string, ErrCodezz> multibleReturnValues() {
		//NOTE: variant uses the same memory as all the types added together
		/*HOW TO USE*/
		std::variant<std::string, ErrCodezz> test;
		//can assign one of the two values and reassign to another
		test = "some string";
		test = ErrCodezz::CZZ_NOT_FOUND;

		//way A to check for data types 
		if (test.index() == 0) {
			//treat as string because its at index 0 of declaration		
		}
		if (test.index() == 1) {
			//treat as int because its at index 1 of declaration
		}
		//way B to check for data types 
		if (auto value = std::get_if<std::string>(&test)) {
			//this checks if its a string type. If it is a string it returns a pointer to the string else it returns null
		}
		if (auto value = std::get_if<ErrCodezz>(&test)) {
			//this checks if its a ErrCodezz type. If it is a ErrCodezz it returns a pointer to the ErrCodezz else it returns null
		}
		/*HOW TO END*/

		//returning a valid string
		return "a string if there is no problem";
		//returning an error code instead
		return ErrCodezz::CZZ_PARSE_ERROR;

	}

};