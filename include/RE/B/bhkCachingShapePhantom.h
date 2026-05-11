#pragma once

#include "RE/B/bhkShapePhantom.h"

namespace RE
{
	class bhkCachingShapePhantom : public bhkShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCachingShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCachingShapePhantom;

		~bhkCachingShapePhantom() override;  // 00

		// override (bhkShapePhantom)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
	};
	static_assert(sizeof(bhkCachingShapePhantom) == 0x30);
}
