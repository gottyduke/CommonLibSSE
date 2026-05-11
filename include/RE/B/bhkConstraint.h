#pragma once

#include "RE/B/bhkSerializable.h"

namespace RE
{
	class hkpEntity;

	class bhkConstraint : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkConstraint;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkConstraint;

		~bhkConstraint() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object);                       // 1C

		// override (bhkRefObject)
		void SetReferencedObject(hkReferencedObject* a_object) override;  // 25
		void AdjustRefCount(bool a_increment) override;                   // 26

		// override (bhkSerializable)
		hkpWorld*  GetWorld1() override;                     // 27
		ahkpWorld* GetWorld2() override;                     // 28
		void       MoveToWorld(bhkWorld* a_world) override;  // 29
		void       RemoveFromCurrentWorld() override;        // 2A
		void       Unk_2D(void) override;                    // 2D
		void       CreateHavokObject(void* cdata) override;  // 2E

		// add
		virtual void       SetEntityA(hkpEntity* entityA);
		virtual void       SetEntityB(hkpEntity* entityB);
		virtual hkpEntity* GetEntityA() const;
		virtual hkpEntity* GetEntityB() const;
		virtual void       AddOrRemoveToWorld(void* world, bool add);
	};
	static_assert(sizeof(bhkConstraint) == 0x20);
}
