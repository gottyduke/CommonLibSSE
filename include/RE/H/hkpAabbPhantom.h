#pragma once

#include "RE/H/hkpPhantom.h"

namespace RE
{
	class hkAabb;
	class hkpCollidable;
	class hkpRayHitCollector;
	struct hkpWorldRayCastInput;

	class hkpAabbPhantom : public hkpPhantom
	{
	public:
		void castRay(const hkpWorldRayCastInput& input, hkpRayHitCollector& collector) const
		{
			using func_t = void(const hkpAabbPhantom* _this, const hkpWorldRayCastInput& input, hkpRayHitCollector& collector);
			REL::Relocation<func_t> func{ RELOCATION_ID(60173, 60941) };
			return func(this, input, collector);
		}

		void setAabb(const hkAabb& newAabb)
		{
			using func_t = decltype(&hkpAabbPhantom::setAabb);
			REL::Relocation<func_t> func{ RELOCATION_ID(60181, 60949) };
			return func(this, newAabb);
		}

		// members
		hkAabb                  aabb;                    // 0F0
		hkArray<hkpCollidable*> overlappingCollidables;  // 110
		bool                    orderDirty;              // 120
		uint8_t                 pad121[7];               // 121
	};
	static_assert(sizeof(hkpAabbPhantom) == 0x130);
}
