#pragma once

#include "RE/C/CombatBehavior.h"
#include "RE/C/CombatPath.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatBehaviorSurround : public CombatBehaviorAction
	{
	public:
		void Enter();
		void Update();

		// members
		NiPointer<CombatPath> path;  // 00
	};
	static_assert(sizeof(CombatBehaviorSurround) == 0x8);
}
