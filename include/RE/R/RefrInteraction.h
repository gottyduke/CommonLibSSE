#pragma once

#include "RE/A/ActorState.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/S/SyncQueueObj.h"

namespace RE
{
	class BGSSaveFormBuffer;
	class BGSLoadFormBuffer;
	class TESActionData;

	class RefrInteraction : public SyncQueueObj
	{
	public:
		inline static constexpr auto RTTI = RTTI_RefrInteraction;
		inline static constexpr auto VTABLE = VTABLE_RefrInteraction;

		enum class INTERACT_METHOD : uint32_t
		{
			Method_0
		};

		~RefrInteraction() override;  // 00

		// add
		virtual ActorHandle     GetTargetActorHandle() const;                                                    // 02
		virtual INTERACT_METHOD QInteractMethod() const = 0;                                                     // 03
		virtual bool            CanInteractionTeleport() const = 0;                                              // 04
		virtual uint32_t        GetFurnMarkerIndex() const;                                                      // 05
		virtual void            AssignInteractionImpl(const BSTSmartPointer<RefrInteraction>& new_interaction);  // 06
		virtual bool            CanBeginInteractionImpl(Actor* a) const;                                         // 07
		virtual SYNC_STATUS     SyncImpl();                                                                      // 08
		virtual bool            DesyncImpl(bool not_clear_behavior, bool clear_synced);                          // 09
		virtual void            SaveGameImpl(BGSSaveFormBuffer* buf) const;                                      // 0A
		virtual bool            LoadGameImpl(BGSLoadFormBuffer* buf);                                            // 0B
		virtual void            FinishLoadGameImpl();                                                            // 0C
		virtual SIT_SLEEP_STATE QExpectedSitSleepState() const = 0;                                              // 0D
		virtual SYNC_STATUS     BeginInteractionImpl(TESActionData& adata, bool a3) = 0;                         // 0E
		virtual bool            EndInteractionImpl(TESActionData& adata, bool a3) = 0;                           // 0F

		// members
		ObjectRefHandle target;    // 10
		ActorHandle     actor;     // 14
		bool            synced;    // 18
		std::uint8_t    pad19[7];  // 19
	};
	static_assert(sizeof(RefrInteraction) == 0x20);
}
