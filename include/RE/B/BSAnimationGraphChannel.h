#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class BSAnimationGraphChannel : public BSIntrusiveRefCounted
	{
	public:
		union Value_t
		{
			int32_t i;
			float f;
		};
		
		inline static constexpr auto RTTI = RTTI_BSAnimationGraphChannel;

		BSAnimationGraphChannel(const BSFixedString& name) :
			channelName(name), value{} {}

		virtual ~BSAnimationGraphChannel() = default;  // 00

		// add
		virtual void PollChannelUpdateImpl(bool a_arg1) = 0;  // 01
		virtual void ResetImpl() = 0;                         // 02

		// members
		std::uint32_t       pad0C;        // 0C
		const BSFixedString channelName;  // 10
		Value_t             value;        // 18
		std::uint32_t       pad1C;        // 1C
	};
	static_assert(sizeof(BSAnimationGraphChannel) == 0x20);
}
