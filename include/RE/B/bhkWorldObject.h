#pragma once

#include "RE/B/bhkSerializable.h"
#include "RE/H/hkpProperty.h"
#include "RE/H/hkpWorldObject.h"

namespace RE
{
	class bhkWorldObject : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorldObject;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorldObject;

		~bhkWorldObject() override;  // 00

		// override(NiObject)
		const NiRTTI* GetRTTI() const override;  // 02

		// override (NiObject)
		void LoadBinary(NiStream& a_stream) override;           // 18
		void LinkObject(NiStream& a_stream) override;           // 19
		bool RegisterStreamables(NiStream& a_stream) override;  // 1A
		void SaveBinary(NiStream& a_stream) override;           // 1B

		// override(bhkRefObject)
		void AdjustRefCount(bool a_increment) override;  // 26

		// override(bhkSerializable)
		hkpWorld*  GetWorld1() override;                     // 27 - { return world; }
		ahkpWorld* GetWorld2() override;                     // 28 - { return world; }
		void       MoveToWorld(bhkWorld* a_world) override;  // 29

		// add
		virtual void MoveToWorld2(void*);  // 32

		hkpPropertyValue GetProperty(uint32_t key) const { return static_cast<hkpWorldObject*>(referencedObject.get())->GetProperty(key); }

		// members
		hkpWorld* world;  // 20
	};
	static_assert(sizeof(bhkWorldObject) == 0x28);
}
