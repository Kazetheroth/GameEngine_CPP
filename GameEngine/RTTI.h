#pragma once

#include <string>

struct RTTI
{
	RTTI(const char* name, const RTTI& parent_type);

	std::string type;
	const RTTI& parent;

	bool IsExactlyA(const RTTI& other) const {
		return type == other.type;
	}

	bool IsA(const RTTI& other) const
	{
		const RTTI* p = this;
		do
		{
			if (p->IsExactlyA(other))
				return true;
			p = &(p->parent);
		} while (p != nullptr);

		return false;
	}

	static RTTI Default;
};

#define RTTI_DECLARATION \
	static RTTI rtti; 

#define RTTI_DEFINITION_BASE(type) \
	RTTI type::rtti(#type);

#define RTTI_DEFINITION(type, parent) \
	RTTI type::rtti(#type, parent::rtti);
