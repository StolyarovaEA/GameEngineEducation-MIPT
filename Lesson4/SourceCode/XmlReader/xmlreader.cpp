#include "pch.h"
#include <fstream>
#include "xmlreader.h"

void XmlReader::LoadFile(const std::string& name)
{
	doc.LoadFile(name.c_str());
    assert(!doc.Error());
}


std::vector<XmlReader::EntityComponents> XmlReader::ParseFile()
{
    std::vector<XmlReader::EntityComponents> entities;
    auto entityElements = doc.FirstChildElement("entities");
    if (entityElements)
    {
        auto entityElement = entityElements->FirstChildElement("entity");
        while (entityElement)
        {
            auto& entity = entities.emplace_back();
            auto component = entityElement->FirstChildElement();
            while (component)
            {
                auto text = component->GetText();
                if (!text)
                    entity.emplace_back(component->Name(), "");
                else
                    entity.emplace_back(component->Name(), text);

                component = component->NextSiblingElement();
            }
            entityElement = entityElement->NextSiblingElement("entity");
        }
    }
    return entities;
}



