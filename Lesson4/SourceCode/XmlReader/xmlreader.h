
#include "pch.h"

class XMLREADER_API XmlReader
{
public:
	void LoadFile(const std::string& name);
	using EntityComponents = std::vector<std::pair<std::string, std::string>>;
	std::vector<EntityComponents> ParseFile();
	template<int n>
	static std::array<float, n> ParseLine(const std::string& s);

private:
	tinyxml2::XMLDocument doc;
};

template<int n>
static std::array<float, n> XmlReader::ParseLine(const std::string& s)
{
	std::string tmp = "";
	std::array<float, n> vec = { 0.0f };
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			tmp += s[i];
		else
		{
			vec[j] = (float)std::stof(tmp);
			j++;
			tmp = "";
		}
	}
	return vec;
}