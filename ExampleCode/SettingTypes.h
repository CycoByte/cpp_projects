#pragma once
#include<vector>
#include <string>
#include <sstream>

#include <memory>

namespace Untether {

	template<typename _SetElem>
	class SettingIterator;
	struct SettingsBuilder;

	struct SettingsElement {

		std::string m_Name;
		std::string m_Value;
		std::vector<SettingsElement> m_Elements;

		friend std::ostream& operator << (std::ostream& os, const SettingsElement& elem)
		{
			if (elem.m_Value.length() > 0)
			{
				os << elem.m_Name << "=" << elem.m_Value << "\n";
			}
			else
			{
				os << elem.m_Name << "\n";
			}
			if (elem.m_Elements.size() > 0)
			{
				for (const auto& child : elem.m_Elements)
					os << child;
			}
			return os;
		}
		static std::unique_ptr<SettingsBuilder> build(const std::string root_name)
		{
			return std::make_unique<SettingsBuilder>(root_name);
		}

		size_t getElementsSize()
		{
			m_Elements.size();
		}

	private:
		SettingsElement() {}
		SettingsElement(const std::string& name, const std::string& value) : m_Name(name), m_Value(value) {}

		friend class SettingsBuilder;
	};


	struct SettingsBuilder {

		SettingsBuilder(const std::string& name)
		{
			m_Root.m_Name = name;
		}

		//fluent function - can be chained
		SettingsBuilder& addSetting(const std::string& name, const std::string& value)
		{
			SettingsElement temp(name, value);
			m_Root.m_Elements.push_back(temp);
			return *this;
		}

		//fluent function - can be chained
		SettingsBuilder& addSetting(const SettingsElement& settings)
		{
			m_Root.m_Elements.push_back(settings);
			return *this;
		}

		operator SettingsElement() const { return m_Root; }
		SettingsElement m_Root;
	};

}