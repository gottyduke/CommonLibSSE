#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSynchronizedClipGenerator.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class hkbCharacter;

	struct CharacterData
	{
		// members
		ObjectRefHandle              handle;     // 00
		uint8_t                      pad4[4];    // 04
		BSSynchronizedClipGenerator* sync_clip;  // 08
		hkbCharacter*                hchar;      // 10
	};
	static_assert(sizeof(CharacterData) == 0x18);

	class BGSSynchronizedAnimationInstance : public BSSynchronizedClipGenerator::hkbSynchronizedAnimationScene
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSSynchronizedAnimationInstance;
		inline static constexpr auto VTABLE = VTABLE_BGSSynchronizedAnimationInstance;

		// members
		uint64_t                          lock;                   // 10
		float                             val;                    // 18
		uint32_t                          actors_need_to_update;  // 1C
		BSTSmallArray<CharacterData, 3>   characters;             // 20
		BSTSmallArray<ObjectRefHandle, 2> handles;                // 78
		int32_t                           actors_count;           // 90
		uint32_t                          field94;                // 94
		uint32_t                          field98;                // 98
		uint8_t                           pad9C[4];               // 9C
	};
	static_assert(sizeof(BGSSynchronizedAnimationInstance) == 0xA0);
}
