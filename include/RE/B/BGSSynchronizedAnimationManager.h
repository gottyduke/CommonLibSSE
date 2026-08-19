#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSSynchronizedAnimationManager
	{
	public:
		static BGSSynchronizedAnimationManager& GetSingleton()
		{
			return **REL::Relocation<BGSSynchronizedAnimationManager**>(REL::ID(514960));
		}

		ObjectRefHandle GetLeadForSceneContaining(const ObjectRefHandle& handle) const
		{
			using func_t = decltype(&BGSSynchronizedAnimationManager::GetLeadForSceneContaining);
			REL::Relocation<func_t> func{ RELOCATION_ID(32056, 0) };
			return func(this, handle);
		}

		// members
		uint64_t                                             field00;    // 00
		BSTArray<hkRefPtr<BGSSynchronizedAnimationInstance>> instances;  // 08
		uint64_t                                             lock1;      // 20
		uint64_t                                             lock2;      // 28
	};
	static_assert(sizeof(BGSSynchronizedAnimationManager) == 0x30);
}
