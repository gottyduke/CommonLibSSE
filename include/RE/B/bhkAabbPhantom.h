#pragma once

#include "RE/B/bhkPhantom.h"
#include "RE/H/hkAabb.h"
#include "RE/H/hkArray.h"
#include "RE/H/hkpWorldObject.h"

namespace RE
{
	class hkpShape;

	// inherited from something
	struct bhkAabbPhantomCinfo
	{
		// members
		uint32_t                       collisionFilterInfo{};  // 00
		uint8_t                        pad04[4];               // 04
		hkpShape*                      shape{};                // 08
		hkpWorldObject::BroadPhaseType broadPhaseType{};       // 10
		uint8_t                        pad11[7];               // 11
		hkArray<void*>                 array;                  // 18 - last field of parent
		uint8_t                        pad28[8];               // 28
		hkAabb                         aabb;                   // 30
	};
	static_assert(sizeof(bhkAabbPhantomCinfo) == 0x50);

	class bhkAabbPhantom : public bhkPhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkAabbPhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkAabbPhantom;
		inline static constexpr auto VTABLE = VTABLE_bhkAabbPhantom;

		static bhkAabbPhantom* Create()
		{
			using func_t = decltype(&bhkAabbPhantom::Create);
			REL::Relocation<func_t> func{ RELOCATION_ID(76811, 78696) };
			return func();
		}
	};
	static_assert(sizeof(bhkAabbPhantom) == 0x30);
}
