#pragma once

#include "RE/B/bhkWorldObject.h"

namespace RE
{
	class bhkEntity : public bhkWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkEntity;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkEntity;

		~bhkEntity() override;  // 00

		// override(NiObject)
		const NiRTTI* GetRTTI() const override;  // 02

		// override(NiObject)
		void LoadBinary(NiStream& a_stream) override;  // 18
		void SaveBinary(NiStream& a_stream) override;  // 1B

		// override(bhkSerializable)
		void RemoveFromCurrentWorld() override;  // 2A
		void Clear2() override;                  // 30
	};
	static_assert(sizeof(bhkEntity) == 0x28);
}
