#include "RE/H/hkbBlenderGenerator.h"

namespace RE
{
	hkbBlenderGenerator::~hkbBlenderGenerator()
	{
		if (memSizeAndFlags & hkReferencedObject::kMemSize) {
			for (auto ch : children) {
				if (ch) {
					if (auto gen = ch->generator)
						gen->RemoveReference();
					ch->RemoveReference();
				}
			}
		}
	}

	void hkbBlenderGenerator::collectBindables(hkbBindableCollector& collector)
	{
		collector.collectBindable(this);
		for (auto ch : children) {
			ch->collectBindables(collector);
		}
	}

	void hkbBlenderGenerator::Activate(const hkbContext& a_context)
	{
		using func_t = decltype(&hkbBlenderGenerator::Activate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58855, 0) };
		return func(this, a_context);
	}

	void hkbBlenderGenerator::Update(const hkbContext& a_context, float a_timestep)
	{
		using func_t = decltype(&hkbBlenderGenerator::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(58856, 0) };
		return func(this, a_context, a_timestep);
	}

	void hkbBlenderGenerator::Deactivate(const hkbContext& a_context)
	{
		using func_t = decltype(&hkbBlenderGenerator::Deactivate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58857, 0) };
		return func(this, a_context);
	}

	int32_t hkbBlenderGenerator::getMaxNumChildren(GET_CHILDREN_FLAGS a_flags)
	{
		if (a_flags.any(RE::hkbNode::GetChildrenFlagBits::kActiveOnly))
			return numActiveChildren;
		else
			return children.size();
	}

	void hkbBlenderGenerator::getChildren(GET_CHILDREN_FLAGS a_flags, ChildrenInfo& ans)
	{
		using func_t = decltype(&hkbBlenderGenerator::getChildren);
		REL::Relocation<func_t> func{ RELOCATION_ID(58859, 0) };
		return func(this, a_flags, ans);
	}

	bool hkbBlenderGenerator::isValid(hkStringPtr& err) const
	{
		using func_t = decltype(&hkbBlenderGenerator::isValid);
		REL::Relocation<func_t> func{ RELOCATION_ID(58860, 0) };
		return func(this, err);
	}

	hkbNode* hkbBlenderGenerator::cloneNode(hkbBehaviorGraph& rootBehavior) const
	{
		using func_t = decltype(&hkbBlenderGenerator::cloneNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(58861, 0) };
		return func(this, rootBehavior);
	}

	hkReferencedObject* hkbBlenderGenerator::createInternalState()
	{
		using func_t = decltype(&hkbBlenderGenerator::createInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(58872, 0) };
		return func(this);
	}

	void hkbBlenderGenerator::getInternalState(hkReferencedObject& internalState) const
	{
		using func_t = decltype(&hkbBlenderGenerator::getInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(58873, 0) };
		return func(this, internalState);
	}

	void hkbBlenderGenerator::setInternalState(const hkReferencedObject& internalState)
	{
		using func_t = decltype(&hkbBlenderGenerator::setInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(58874, 0) };
		return func(this, internalState);
	}

	void hkbBlenderGenerator::generate(const hkbContext& a_context, const hkbGeneratorOutput** activeChildrenOutput, hkbGeneratorOutput& output, float timeOffset) const
	{
		using func_t = decltype(&hkbBlenderGenerator::generate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58862, 0) };
		return func(this, a_context, activeChildrenOutput, output, timeOffset);
	}

	bool hkbBlenderGenerator::canRecycleOutput() const
	{
		return numActiveChildren == 1 && referencePoseWeightThreshold == 0;
	}

	void hkbBlenderGenerator::updateSync(const hkbContext& a_context, hkbNodeInfo& info)
	{
		using func_t = decltype(&hkbBlenderGenerator::updateSync);
		REL::Relocation<func_t> func{ RELOCATION_ID(58864, 0) };
		return func(this, a_context, info);
	}

	void hkbBlenderGenerator::startEcho()
	{
		initSync = true;
	}

	void hkbBlenderGenerator::setGenerator(int32_t generatorIndex, hkbGenerator* generator)
	{
		using func_t = decltype(&hkbBlenderGenerator::setGenerator);
		REL::Relocation<func_t> func{ RELOCATION_ID(58866, 0) };
		return func(this, generatorIndex, generator);
	}

	void hkbBlenderGenerator::setBoneWeight(int32_t generatorIndex, int32_t boneIndex, float weight)
	{
		using func_t = decltype(&hkbBlenderGenerator::setBoneWeight);
		REL::Relocation<func_t> func{ RELOCATION_ID(58867, 0) };
		return func(this, generatorIndex, boneIndex, weight);
	}
}
