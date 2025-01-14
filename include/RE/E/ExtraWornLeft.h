#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraWornLeft : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWornLeft;
		inline static auto           EXTRADATATYPE = ExtraDataType::kWornLeft;

		ExtraWornLeft() = default;
		~ExtraWornLeft() = default;  // 00

		// override (BSExtraData)
		[[nodiscard]] ExtraDataType GetType() const override { return ExtraDataType::kWornLeft; };  // 01 - { return kWorn; }
	};
	static_assert(sizeof(ExtraWornLeft) == 0x10);
}
