#pragma once

#include "RE/B/bhkConstraint.h"

namespace RE
{
	class bhkPrismaticConstraint : public bhkConstraint
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkPrismaticConstraint;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkPrismaticConstraint;
	};
	static_assert(sizeof(bhkPrismaticConstraint) == 0x20);
}
