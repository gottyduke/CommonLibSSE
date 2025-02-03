#pragma once
#include "RE/B/bhkSerializable.h"

namespace RE
{
	class bhkCharacterRigidBody : public bhkSerializable
	{
	public:
		void Unk_2E(void) override;  // 2E
		void Unk_2F(void) override;  // 2F

		bhkRigidBody*              rigidBody;                       // 20
		NiAVObject*                unk28;                           // 28 - MarkerX ??
		bhkCharacterPointCollector ignoredCollisionStartCollector;  // 30
	};
	static_assert(offsetof(bhkCharacterRigidBody, ignoredCollisionStartCollector) == 0x30);
}
