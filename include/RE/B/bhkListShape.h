#pragma once

#include "RE/B/bhkShapeCollection.h"

namespace RE
{
	class bhkListShape : public bhkShapeCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkListShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkListShape;

		~bhkListShape() override;  // 00

		// override (bhkShapeCollection)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		void          AdjustRefCount(bool a_increment) override;          // 26

		// members
		std::uint64_t unk28;  // 28
	};
	static_assert(sizeof(bhkListShape) == 0x30);
}
