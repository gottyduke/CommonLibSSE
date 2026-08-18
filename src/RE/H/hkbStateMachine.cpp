#include "RE/H/hkbStateMachine.h"
#include "RE/H/hkMap.h"

namespace RE
{
	hkbStateMachine::TransitionInfo::TransitionInfo(int32_t a_eventId, int32_t a_toStateId, hkbTransitionEffect* a_transition, hkbCondition* condition) :
		triggerInterval(), initiateInterval(), transition(a_transition), condition(condition), eventId(a_eventId), toStateId(a_toStateId), fromNestedStateId(), toNestedStateId(), priority(), flags()
	{
	}

	hkbStateMachine::~hkbStateMachine()
	{
		for (auto& transition : activeTransitions) {
			transition.transitionEffect->RemoveReference();
		}

		for (auto state : states) {
			state->RemoveReference();
		}
	}

	void hkbStateMachine::CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const
	{
		using func_t = decltype(&hkbStateMachine::CalcContentStatistics);
		REL::Relocation<func_t> func{ RELOCATION_ID(58713, 0) };
		return func(this, a_collector, a_class);
	}

	void hkbStateMachine::collectBindables(hkbBindableCollector& collector)
	{
		collector.collectBindable(this);
		for (auto state : states) {
			state->collectBindables(collector);
		}
	}

	void hkbStateMachine::Activate(const hkbContext& a_context)
	{
		using func_t = decltype(&hkbStateMachine::Activate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58679, 0) };
		return func(this, a_context);
	}

	void hkbStateMachine::Update(const hkbContext& a_context, float a_timestep)
	{
		using func_t = decltype(&hkbStateMachine::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(58680, 0) };
		return func(this, a_context, a_timestep);
	}

	void hkbStateMachine::handleEvent(const hkbContext& ctx, hkbEvent& event)
	{
		using func_t = decltype(&hkbStateMachine::handleEvent);
		REL::Relocation<func_t> func{ RELOCATION_ID(58681, 0) };
		return func(this, ctx, event);
	}

	void hkbStateMachine::Deactivate(const hkbContext& a_context)
	{
		using func_t = decltype(&hkbStateMachine::Deactivate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58682, 0) };
		return func(this, a_context);
	}

	int32_t hkbStateMachine::getMaxNumChildren(GET_CHILDREN_FLAGS flags)
	{
		using func_t = decltype(&hkbStateMachine::getMaxNumChildren);
		REL::Relocation<func_t> func{ RELOCATION_ID(58683, 0) };
		return func(this, flags);
	}

	void hkbStateMachine::getChildren(GET_CHILDREN_FLAGS flags, ChildrenInfo& ans)
	{
		using func_t = decltype(&hkbStateMachine::getChildren);
		REL::Relocation<func_t> func{ RELOCATION_ID(58684, 0) };
		return func(this, flags, ans);
	}

	bool hkbStateMachine::isValid(hkStringPtr& err) const
	{
		using func_t = decltype(&hkbStateMachine::isValid);
		REL::Relocation<func_t> func{ RELOCATION_ID(58685, 0) };
		return func(this, err);
	}

	hkbNode* hkbStateMachine::cloneNode(hkbBehaviorGraph& rootBehavior) const
	{
		using func_t = decltype(&hkbStateMachine::cloneNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(58686, 0) };
		return func(this, rootBehavior);
	}

	hkReferencedObject* hkbStateMachine::createInternalState()
	{
		using func_t = decltype(&hkbStateMachine::createInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(59335, 0) };
		return func(this);
	}

	void hkbStateMachine::getInternalState(hkReferencedObject& internalState) const
	{
		using func_t = decltype(&hkbStateMachine::getInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(59336, 0) };
		return func(this, internalState);
	}

	void hkbStateMachine::getInternalStateUser(const hkbBehaviorGraph& rootBehavior, hkReferencedObject& internalState) const
	{
		using func_t = decltype(&hkbStateMachine::getInternalStateUser);
		REL::Relocation<func_t> func{ RELOCATION_ID(58687, 0) };
		return func(this, rootBehavior, internalState);
	}

	void hkbStateMachine::setInternalState(const hkReferencedObject& internalState)
	{
		using func_t = decltype(&hkbStateMachine::setInternalState);
		REL::Relocation<func_t> func{ RELOCATION_ID(59337, 0) };
		return func(this, internalState);
	}

	void hkbStateMachine::setInternalStateUser(const hkbContext& context, const hkReferencedObject& internalState, void* nodeIdToInternalStateMap)
	{
		using func_t = decltype(&hkbStateMachine::setInternalStateUser);
		REL::Relocation<func_t> func{ RELOCATION_ID(58688, 0) };
		return func(this, context, internalState, nodeIdToInternalStateMap);
	}

	void hkbStateMachine::getActiveEvents(void* activeEvents) const
	{
		using func_t = decltype(&hkbStateMachine::getActiveEvents);
		REL::Relocation<func_t> func{ RELOCATION_ID(58689, 0) };
		return func(this, activeEvents);
	}

	void hkbStateMachine::getActiveVariablesSpecial(void* activeVariables) const
	{
		using func_t = decltype(&hkbStateMachine::getActiveVariablesSpecial);
		REL::Relocation<func_t> func{ RELOCATION_ID(58690, 0) };
		return func(this, activeVariables);
	}

	void hkbStateMachine::generate(const hkbContext& a_context, const hkbGeneratorOutput** activeChildrenOutput, hkbGeneratorOutput& output, float timeOffset) const
	{
		using func_t = decltype(&hkbStateMachine::generate);
		REL::Relocation<func_t> func{ RELOCATION_ID(58691, 0) };
		return func(this, a_context, activeChildrenOutput, output, timeOffset);
	}

	bool hkbStateMachine::canRecycleOutput() const
	{
		return true;
	}

	void hkbStateMachine::updateSync(const hkbContext& a_context, hkbNodeInfo& info)
	{
		using func_t = decltype(&hkbStateMachine::updateSync);
		REL::Relocation<func_t> func{ RELOCATION_ID(58693, 0) };
		return func(this, a_context, info);
	}

	void hkbStateMachine::startEcho()
	{
		echoNextUpdate = true;
	}

	void hkbStateMachine::addState(int32_t stateId, hkbGenerator* generator, char const* stateName)
	{
		REL::Relocation<void(hkbStateMachine*, int32_t, hkbGenerator*, char const*)> func(RELOCATION_ID(58706, 0));  // I do not know for AE
		return func(this, stateId, generator, stateName);
	}

	int32_t hkbStateMachine::addState(RE::hkbGenerator* generator, const char* stateName)
	{
		int32_t stateID = getUnusedStateId();
		addState(stateID, generator, stateName);
		return stateID;
	}

	hkbStateMachine::TransitionInfo* hkbStateMachine::addTransition(int32_t eventId, int32_t fromStateId, int32_t toStateId, hkbTransitionEffect* transition, hkbCondition* condition)
	{
		auto& from_state = getStateInfoById(fromStateId);
		if (!from_state.transitions)
			from_state.transitions = make_hkref<hkbStateMachine::TransitionInfoArray>();

		return addTransitionInternal(eventId, toStateId, transition, condition, from_state.transitions->transitions);
	}

	hkbStateMachine::TransitionInfo* hkbStateMachine::addTransitionInternal(int32_t eventId, int32_t toStateId, hkbTransitionEffect* transition, hkbCondition* condition, hkArray<TransitionInfo>& transitions)
	{
		transitions.push_back({ eventId, toStateId, transition, condition });
		return &transitions.back();
	}

	uint16_t hkbStateMachine::getCurrentStateIndex() const
	{
		return currentStateIndexAndEntered >> 1;
	}

	hkbStateMachine* hkbStateMachine::getNestedStateMachineClone(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex)
	{
		if (auto nodeTemplate = getNestedStateMachineTemplate(behaviorGraph, stateIndex)) {
			return static_cast<hkbStateMachine*>(behaviorGraph.getNodeClone(nodeTemplate));
		} else {
			return nullptr;
		}
	}

	hkbBehaviorGraph::StateMachineInfo* hkbStateMachine::getNestedStateMachineInfo(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex)
	{
		if (auto global_transition_data = behaviorGraph.globalTransitionData.get()) {
			auto     this_template = static_cast<hkbStateMachine*>(behaviorGraph.getNodeTemplate(this));
			uint64_t statemachine_info_ind = global_transition_data->stateMachineTemplateToIndexMap.getWithDefault(this_template, -1);
			if (statemachine_info_ind >= 0) {
				if (auto childStateMachineInfoIndices = global_transition_data->stateMachineInfos[static_cast<uint32_t>(statemachine_info_ind)].childStateMachineInfoIndices) {
					if (auto statemachine_infos_ind = (*childStateMachineInfoIndices)[stateIndex]; statemachine_infos_ind != -1) {
						return &global_transition_data->stateMachineInfos[statemachine_infos_ind];
					}
				}
			}
		}

		return nullptr;
	}

	hkbStateMachine* hkbStateMachine::getNestedStateMachineTemplate(const hkbBehaviorGraph& behaviorGraph, int32_t stateIndex)
	{
		if (auto info = getNestedStateMachineInfo(behaviorGraph, stateIndex)) {
			return info->stateMachineTemplate;
		} else {
			return nullptr;
		}
	}

	int32_t hkbStateMachine::getStateIndex(int32_t stateID) const
	{
		if (stateID)
			return static_cast<int32_t>(stateIDToIndexMap->getWithDefault(stateID, -1));
		if (states.empty() || states[0]->id != 0)
			return -1;
		return 0;
	}

	hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoById(int32_t stateId)
	{
		return *states[getStateIndex(stateId)];
	}

	const hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoById(int32_t stateId) const
	{
		return *states[getStateIndex(stateId)];
	}

	hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoByIndex(int32_t stateIndex)
	{
		return *states[stateIndex];
	}

	const hkbStateMachine::StateInfo& hkbStateMachine::getStateInfoByIndex(int32_t stateIndex) const
	{
		return *states[stateIndex];
	}

	int32_t hkbStateMachine::getUnusedStateId() const
	{
		int32_t i = 0;
		while (getStateIndex(i) != -1) ++i;
		return i;
	}

	hkbStateMachine::StateInfo::StateInfo()
	{
		stl::emplace_vtable(this);
	}

	hkbStateMachine::StateInfo::~StateInfo()
	{
		for (auto listener : listeners) {
			listener->RemoveReference();
		}
	}

	void hkbStateMachine::StateInfo::addEnterNotifyEvent(int32_t eventId, hkbEventPayload* eventPayload)
	{
		using func_t = decltype(&hkbStateMachine::StateInfo::addEnterNotifyEvent);
		REL::Relocation<func_t> func{ RELOCATION_ID(58701, 0) };
		return func(this, eventId, eventPayload);
	}

	void hkbStateMachine::StateInfo::addExitNotifyEvent(int32_t eventId, hkbEventPayload* eventPayload)
	{
		using func_t = decltype(&hkbStateMachine::StateInfo::addExitNotifyEvent);
		REL::Relocation<func_t> func{ RELOCATION_ID(58702, 0) };
		return func(this, eventId, eventPayload);
	}
}
