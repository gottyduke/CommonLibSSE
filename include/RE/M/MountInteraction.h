#pragma once

#include "RE/B/BSTArray.h"
#include "RE/R/RefrInteraction.h"

namespace RE
{
	class BSAnimationGraphChannel;

	class MountInteraction : public RefrInteraction
	{
	public:
		inline static constexpr auto RTTI = RTTI_MountInteraction;
		inline static constexpr auto VTABLE = VTABLE_MountInteraction;

		~MountInteraction() override;  // 00

		// override (SyncQueueObj)
		SYNC_STATUS QueuedSync() override;  // 01

		// override (RefrInteraction)
		ActorHandle     GetTargetActorHandle() const override;                                                    // 02
		INTERACT_METHOD QInteractMethod() const override;                                                         // 03
		bool            CanInteractionTeleport() const override;                                                  // 04
		void            AssignInteractionImpl(const BSTSmartPointer<RefrInteraction>& new_interaction) override;  // 06
		SYNC_STATUS     SyncImpl() override;                                                                      // 08
		bool            DesyncImpl(bool not_clear_behavior, bool clear_synced) override;                          // 09
		void            FinishLoadGameImpl() override;                                                            // 0C
		SIT_SLEEP_STATE QExpectedSitSleepState() const override;                                                  // 0D
		SYNC_STATUS     BeginInteractionImpl(TESActionData& adata, bool a3) override;                             // 0E
		bool            EndInteractionImpl(TESActionData& adata, bool a3) override;                               // 0F

		// add
		virtual bool CanBeginInteractionImpl2(RE::Actor* a) const;  // 10

		// members
		BSTArray<BSTSmartPointer<BSAnimationGraphChannel>> channels;  // 20
	};
	static_assert(sizeof(MountInteraction) == 0x38);
}
