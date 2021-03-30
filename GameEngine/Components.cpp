#include "Components.h"

bool ESGI::Components::Deserialize(const std::string& s)
{
	rapidjson::Document doc;
	if (!InitDocument(s, doc))
		return false;

	if (!doc.IsArray())
		return false;

	for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End(); ++itr)
	{
		Component co;
		co.Deserialize(*itr);
		components.push_back(co);
	}

	return true;
}

bool ESGI::Components::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	return false;
}
