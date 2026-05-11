#pragma once

#include "RE/B/bhkRefObject.h"

namespace RE
{
	class ahkpWorld;
	class hkpWorld;
	class bhkWorld;

	class bhkSerializable : public bhkRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSerializable;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSerializable;

		~bhkSerializable() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;  // 02

		// override (NiObject)
		void LoadBinary(NiStream& a_stream) override;           // 18
		void LinkObject(NiStream& a_stream) override;           // 19
		bool RegisterStreamables(NiStream& a_stream) override;  // 1A
		void SaveBinary(NiStream& a_stream) override;           // 1B

		// override (bhkRefObject)
		void SetReferencedObject(hkReferencedObject* a_object) override;  // 25

		// add
		virtual hkpWorld*  GetWorld1();                         // 27
		virtual ahkpWorld* GetWorld2();                         // 28
		virtual void       MoveToWorld(bhkWorld* a_world);      // 29
		virtual void       RemoveFromCurrentWorld();            // 2A
		virtual void       ClearData(bool free);                // 2B
		virtual uint32_t   GetSaveType() const;                 // 2C
		virtual void       Unk_2D(void);                        // 2D
		virtual void       CreateHavokObject(void* cdata) = 0;  // 2E -- hkpConstraintData **__shifted(hkConstraintCinfo,8) cdata
		virtual void       Unk_2F(void) = 0;                    // 2F
		virtual void       Clear2();                            // 30
		virtual void       Clear3(void*);                       // 31

		// members
		bhkSerializable* serializable;  // 18
	};
	static_assert(sizeof(bhkSerializable) == 0x20);
}
