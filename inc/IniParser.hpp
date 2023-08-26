#ifndef INIPARSER_HPP
#define INIPARSER_HPP

#include <string>
#include <map>
#include <sstream>

class IniParser
{
public:
	IniParser();
	bool LoadFromFile(const std::string& filename);
	bool SaveToFile(const std::string& filename);
	void SeekSection(const std::string& section_name);
	const std::string& Get(const std::string& key) const;
	/*template <class T>
	T Get(const std::string& key, const T& default_value) const;*/
	// sintaxe alternativa
	template <class T>
	bool Get(const std::string& key, T& output_value) const;
	template <class T>
	void Set(const std::string& key, const T& value);

private:
	void ClearString(std::string& line) const;

	typedef std::map<std::string, std::string> Section;
	typedef std::map<std::string, Section> Entry;

	Entry entries_;
	Section* cursor_;
};

/*
template <class T>
T IniParser::Get(const std::string& key, const T& default_value) const
{
	std::istringstream iss(Get(key));
	T value;
	if (iss >> value)
		return value;
	return default_value;
}
*/

template <class T>
bool IniParser::Get(const std::string& key, T& value) const
{
	std::istringstream iss(Get(key));
	if (!iss.str().empty())
	{
		iss >> value;
		return true;
	}
	return false;
}


template <class T>
void IniParser::Set(const std::string& key, const T& value)
{
	if (cursor_ != NULL)
	{
		std::ostringstream oss;
		oss << value;
		(*cursor_)[key] = oss.str();
	}
}

#endif // INIPARSER_HPP
