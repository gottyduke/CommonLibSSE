#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class SyncQueueObj : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_SyncQueueObj;
		inline static constexpr auto VTABLE = VTABLE_SyncQueueObj;

		enum class SYNC_STATUS : uint32_t
		{
			Status_0,
			Status_1,
			Status_2
		};

		virtual ~SyncQueueObj();  // 00

		// add
		virtual SYNC_STATUS QueuedSync() = 0;  // 01

		// members
		uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(SyncQueueObj) == 0x10);
}
