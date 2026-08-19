#include "RE/T/TESObjectREFRSync.h"

#include "RE/N/NiNode.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	namespace TESObjectREFRSync
	{
		void Add(TESObjectREFR* rider, const ObjectRefHandle& horse_handle, NiAVObject* some_node)
		{
			auto    horse = horse_handle.get();
			NiNode* horse_root_ninode = nullptr;

			if (some_node)
				horse_root_ninode = some_node->AsNode();
			else if (horse) {
				if (auto horse_root = horse->Get3D())
					horse_root_ninode = horse_root->AsNode();
			}

			RE::NiTransform transform;
			Add(rider, horse.get(), horse_root_ninode, transform, some_node == nullptr);
		}

		bool Add(TESObjectREFR* rider, TESObjectREFR* horse, NiAVObject* saddle, const NiTransform& transform, bool a6)
		{
			using func_t = bool(TESObjectREFR * rider, TESObjectREFR * horse, NiAVObject * saddle, const NiTransform& transform, bool a6);
			REL::Relocation<func_t> func{ RELOCATION_ID(19910, 20312) };
			return func(rider, horse, saddle, transform, a6);
		}

		void Remove(TESObjectREFR* rider)
		{
			using func_t = decltype(Remove);
			REL::Relocation<func_t> func{ RELOCATION_ID(19911, 20313) };
			return func(rider);
		}
	}
}
