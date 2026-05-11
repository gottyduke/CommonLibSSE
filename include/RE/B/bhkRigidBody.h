#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/bhkEntity.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class hkAabb;
	class hkTransform;
	class hkQuaternion;
	class hkVector4;

	class bhkRigidBody : public bhkEntity
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkRigidBody;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkRigidBody;

		~bhkRigidBody() override;  // 00

		// override(NiObject)
		const NiRTTI* GetRTTI() const override;  // 02

		// override(NiObject)
		bhkRigidBody* AsBhkRigidBody() override;                          // 15 - { return this; }
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// override(bhkSerializable)
		void     MoveToWorld(bhkWorld* a_world) override;  // 29
		void     RemoveFromCurrentWorld() override;        // 2A
		void     ClearData(bool free) override;            // 2B
		uint32_t GetSaveType() const override;             // 2C - { return 0x110; }
		void     Unk_2D(void) override;                    // 2D
		void     CreateHavokObject(void* cdata) override;  // 2E
		void     Unk_2F(void) override;                    // 2F
		void     Clear2() override;                        // 30

		// override(bhkWorldObject)
		void MoveToWorld2(void*) override;  // 32

		// add
		virtual void GetPosition(hkVector4& a_outPosition);                                    // 33
		virtual void GetRotation(hkQuaternion& a_outRotation);                                 // 34
		virtual void SetPosition(hkVector4& a_position);                                       // 35
		virtual void SetRotation(hkQuaternion& a_rotation);                                    // 36
		virtual void SetPositionAndRotation(hkVector4& a_position, hkQuaternion& a_rotation);  // 37
		virtual void GetCenterOfMassLocal(hkVector4& a_outCenterOfMassLocal);                  // 38
		virtual void GetCenterOfMassWorld(hkVector4& a_outCenterOfMassWorld);                  // 39
		virtual void GetTransform(hkTransform& a_outTransform);                                // 3A
		virtual void GetAabbWorldspace(hkAabb& a_outAabb);                                     // 3B
		virtual void Unk_3C(void);                                                             // 3C

		void SetAngularImpulse(const hkVector4& a_impulse);
		void SetAngularVelocity(const hkVector4& a_newVel);
		void SetLinearImpulse(const hkVector4& a_impulse);
		void SetLinearVelocity(const hkVector4& a_newVel);

		// members
		BSTArray<NiPointer<bhkSerializable>> actions_and_constraints;  // 28
	};
	static_assert(sizeof(bhkRigidBody) == 0x40);
}
