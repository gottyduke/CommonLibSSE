#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class TESObjectREFR;
	class NiAVObject;
	class NiTransform;

	namespace TESObjectREFRSync
	{
		void Add(TESObjectREFR* rider, const ObjectRefHandle& horse, NiAVObject* some_node = nullptr);
		bool Add(TESObjectREFR* rider, TESObjectREFR* horse, NiAVObject* saddle, const NiTransform& transform, bool a6);
		void Remove(TESObjectREFR* rider);
	}
}
