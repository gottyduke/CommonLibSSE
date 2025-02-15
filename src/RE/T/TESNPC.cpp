#include "RE/T/TESNPC.h"

#include "RE/T/TESRace.h"

namespace RE
{
	TESNPC::HeadRelatedData::HeadRelatedData() :
		hairColor(nullptr),
		faceDetails(nullptr)
	{}

	void TESNPC::CopyPerkRankArray(const std::vector<PerkRankData>& a_copiedData)
	{
		const auto oldData = perks;

		const auto newSize = a_copiedData.size();
		const auto newData = calloc<PerkRankData>(newSize);
		std::ranges::copy(a_copiedData, newData);

		perkCount = static_cast<std::uint32_t>(newSize);
		perks = newData;

		free(oldData);
	}

	bool TESNPC::AddPerk(BGSPerk* a_perk, std::int8_t a_rank)
	{
		if (!GetPerkIndex(a_perk)) {
			const auto                newPerk = new PerkRankData(a_perk, a_rank);
			std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
			copiedData.push_back(*newPerk);
			CopyPerkRankArray(copiedData);
			return true;
		}

		return false;
	}

	bool TESNPC::AddPerks(const std::vector<BGSPerk*>& a_perks, std::int8_t a_rank)
	{
		std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
		std::ranges::for_each(a_perks, [&](auto& perk) {
			if (!GetPerkIndex(perk)) {
				const auto newPerk = new PerkRankData(perk, a_rank);
				copiedData.push_back(*newPerk);
			}
		});
		CopyPerkRankArray(copiedData);
		return true;
	}

	void TESNPC::ChangeHeadPart(BGSHeadPart* a_target)
	{
		using func_t = decltype(&TESNPC::ChangeHeadPart);
		REL::Relocation<func_t> func{ Offset::TESNPC::ChangeHeadPart };
		return func(this, a_target);
	}

	bool TESNPC::ContainsKeyword(std::string_view a_editorID)
	{
		if (ContainsKeywordString(a_editorID)) {
			return true;
		}
		if (auto npcRace = GetRace(); npcRace && npcRace->ContainsKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	BGSHeadPart** TESNPC::GetBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetBaseOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::GetBaseOverlays };
		return func(this);
	}

	const float TESNPC::GetBaseScale() const
	{
		if (race) {
			return race->data.height[GetSex()];
		}

		return 1.f;
	}

	std::optional<std::uint32_t> TESNPC::GetPerkIndex(BGSPerk* a_perk) const
	{
		if (perks) {
			for (std::uint32_t i = 0; i < perkCount; i++) {
				if (perks[i].perk == a_perk) {
					return i;
				}
			}
		}
		return std::nullopt;
	}

	SEX TESNPC::GetSex() const
	{
		return IsFemale() ? SEX::kFemale : SEX::kMale;
	}

	BGSHeadPart* TESNPC::GetCurrentHeadPartByType(HeadPartType a_type)
	{
		return HasOverlays() ? GetHeadPartOverlayByType(a_type) : GetHeadPartByType(a_type);
	}

	BGSHeadPart* TESNPC::GetHeadPartByType(HeadPartType a_type)
	{
		if (headParts) {
			for (std::int8_t i = 0; i < numHeadParts; ++i) {
				if (headParts[i] && headParts[i]->type == a_type) {
					return headParts[i];
				}
			}
		}
		return nullptr;
	}

	BGSHeadPart* TESNPC::GetHeadPartOverlayByType(HeadPartType a_type)
	{
		const auto numOverlays = GetNumBaseOverlays();
		auto       overlays = GetBaseOverlays();
		if (overlays) {
			for (std::uint32_t i = 0; i < numOverlays; ++i) {
				if (overlays[i]->type == a_type) {
					return overlays[i];
				}
			}
		}
		return nullptr;
	}

	float TESNPC::GetHeight() const
	{
		if (!race) {
			return height;
		}

		const auto sex = GetSex();
		switch (sex) {
		case SEX::kMale:
		case SEX::kFemale:
			return race->data.height[sex] * height;
		default:
			return 0.0;
		}
	}

	std::uint32_t TESNPC::GetNumBaseOverlays() const
	{
		using func_t = decltype(&TESNPC::GetNumBaseOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::GetNumBaseOverlays };
		return func(this);
	}

	TESSpellList::SpellData* TESNPC::GetSpellList()
	{
		if (!actorEffects) {
			actorEffects = new SpellData();
		}
		return actorEffects;
	}

	TESRace* TESNPC::GetRace()
	{
		return race;
	}

	TESNPC* TESNPC::GetRootFaceNPC()
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}

	const TESNPC* TESNPC::GetRootFaceNPC() const
	{
		auto iter = this;
		while (iter->faceNPC) {
			iter = iter->faceNPC;
		}
		return iter;
	}

	float TESNPC::Layer::GetInterpolationValue() const
	{
		return static_cast<float>(interpolationValue) / static_cast<float>(100.0);
	}

	bool TESNPC::HasApplicableKeywordString(std::string_view a_editorID)
	{
		if (HasKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetRace(); npcRace && npcRace->HasKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::HasOverlays()
	{
		using func_t = decltype(&TESNPC::HasOverlays);
		REL::Relocation<func_t> func{ Offset::TESNPC::HasOverlays };
		return func(this);
	}

	bool TESNPC::IsInFaction(TESFaction* a_faction) const
	{
		return std::ranges::any_of(factions, [&](const auto& faction) {
			return faction.faction == a_faction && faction.rank > -1;
		});
	}

	bool TESNPC::RemovePerk(BGSPerk* a_perk)
	{
		if (const auto index = GetPerkIndex(a_perk); index.has_value()) {
			std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
			copiedData.erase(copiedData.cbegin() + *index);
			CopyPerkRankArray(copiedData);
			return true;
		}
		return false;
	}

	bool TESNPC::RemovePerks(const std::vector<BGSPerk*>& a_perks)
	{
		std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
		if (std::erase_if(copiedData, [&](auto& perkRank) { return std::ranges::find(a_perks, perkRank.perk) != a_perks.end(); }) > 0) {
			CopyPerkRankArray(copiedData);
			return true;
		}
		return false;
	}

	bool TESNPC::SetDefaultOutfit(BGSOutfit* a_outfit)
	{
		defaultOutfit = a_outfit;
		return AddChange(ChangeFlags::kDefaultOutfit);
	}

	void TESNPC::SetFaceTexture(BGSTextureSet* a_textureSet)
	{
		if (!headRelatedData && a_textureSet) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->faceDetails = a_textureSet;
		}
	}

	void TESNPC::SetHairColor(BGSColorForm* a_hairColor)
	{
		if (!headRelatedData && a_hairColor) {
			headRelatedData = new HeadRelatedData();
		}

		if (headRelatedData) {
			headRelatedData->hairColor = a_hairColor;
		}
	}

	void TESNPC::SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, bool a_fromTint)
	{
		using func_t = decltype(&TESNPC::SetSkinFromTint);
		REL::Relocation<func_t> func{ Offset::TESNPC::SetSkinFromTint };
		return func(this, a_result, a_tintMask, a_fromTint);
	}

	bool TESNPC::SetSleepOutfit(BGSOutfit* a_outfit)
	{
		sleepOutfit = a_outfit;
		return AddChange(ChangeFlags::kSleepOutfit);
	}

	void TESNPC::UpdateNeck(BSFaceGenNiNode* a_faceNode)
	{
		using func_t = decltype(&TESNPC::UpdateNeck);
		REL::Relocation<func_t> func{ Offset::TESNPC::UpdateNeck };
		return func(this, a_faceNode);
	}
}
