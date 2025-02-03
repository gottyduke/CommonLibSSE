#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkContactPoint.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpEntityListener.h"
#include "RE/H/hkpWorldPostSimulationListener.h"

namespace RE
{
	class hkpRigidBody;
	class hkpShape;
	class hkpCdPointCollector;
	class hkpCharacterRigidBodyListener;
	class hkpSimpleConstraintContactMgr;

	class hkpCharacterRigidBody : hkReferencedObject, hkpEntityListener, hkpWorldPostSimulationListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCharacterRigidBody;

		~hkpCharacterRigidBody();

		struct VertPointInfo
		{
			hkContactPoint                 vertPoint;
			hkpSimpleConstraintContactMgr* mgr;
		};

		void SetLinearVelocity(const hkVector4& a_newVel, float a_timestep);

		hkpRigidBody*                  character;                    //20
		hkpCharacterRigidBodyListener* listener;                     //28
		hkVector4                      up;                           //30
		float                          unweldingHeightOffsetFactor;  //40
		float                          maxSlopeCosine;               //44
		float                          maxSpeedForSimplexSolver;     //48
		float                          supportDistance;              //4C
		float                          hardSupportDistance;          //50
		hkVector4                      acceleration;                 //60
		float                          maxForce;                     //70
		hkArray<VertPointInfo>         verticalContactPoints;        //78
	};
	static_assert(sizeof(hkpCharacterRigidBody) == 0x90);

}
