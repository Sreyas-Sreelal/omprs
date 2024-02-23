#include "api.hpp"

OMPRS_API void OMPRS_Print(const char* text) {
	OMPRSComponent::Get()->GetCore()->printLn(text);
}
