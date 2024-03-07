#pragma once

#include "../api.hpp"

OMPRS_API(void,Print(const char* text))
{
	OMPRSComponent::Get()->GetCore()->printLn("%s",text);
}
