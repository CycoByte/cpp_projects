#pragma once

#include <string>
#include<optional>

class OptionalData {

	std::string mName;

public:

	OptionalData(std::optional<std::string> name) {
		//check if the optional data is set or has_value() and set the data.
		//The data is passed similar to a smart pointer, so to access the optional data use -> or *
		if (name)
			mName = *name;

		//can also do:
		mName = name.value_or(""); //this will run if there is no value, this assigns a default value when nothing it present

	}

	std::optional<std::string> getClassName() {
		if (mName.length() <= 0) {
			//if the string is empty return empty brakets for no optional arguments
			return {};
		}
		else 
		{
			//return the name
			return mName;
		}
	}

};