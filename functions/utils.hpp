#pragma once

#include "../api.hpp"

OMPRS_API(void,Print(StringView text))
{
	OMPRSComponent::Get()->GetCore()->printLn("%s",text.to_string().c_str());
}
