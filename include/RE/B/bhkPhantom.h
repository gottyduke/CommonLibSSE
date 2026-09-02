#pragma once

#include "RE/B/bhkWorldObject.h"

namespace RE
{
	class bhkPhantom : public bhkWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkPhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkPhantom;

		~bhkPhantom() override;  // 00

		// override (bhkWorldObject)
		const NiRTTI* GetRTTI() const override;           // 02
		void          RemoveFromCurrentWorld() override;  // 2A

		// members
		uint8_t unk28;     // 28
		uint8_t pad29[7];  // 29
	};
	static_assert(sizeof(bhkPhantom) == 0x30);
}
