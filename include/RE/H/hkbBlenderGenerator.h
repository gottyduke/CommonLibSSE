#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbBoneWeightArray;

	class hkbBlenderGeneratorChild : public hkbBindable
	{
	public:
		// members
		hkbGenerator*                generator;             // 30
		hkRefPtr<hkbBoneWeightArray> boneWeights;           // 38
		float                        weight;                // 40
		float                        worldFromModelWeight;  // 44
		uint64_t                     field_48;              // 48
	};
	static_assert(sizeof(hkbBlenderGeneratorChild) == 0x50);

	/// A generator which performs a blend between an arbitrary number of children.
	///
	/// Each child has a blend weight between 0 and 1.   Each child can also have a blend weight for each bone.
	/// The two weights are multiplied to get the per-child per-bone weight.  For each bone, the weights
	/// across all of the children are normalized to sum to 1.  If the sum of the weights falls below
	/// the threshold specified in m_referencePoseWeightThreshold, the reference pose is
	/// blended in.
	///
	/// When the FLAG_PARAMETRIC_BLEND flag is set the blender generator works as a parametric blender. The parametric
	/// blend can be cyclic or acyclic. Cyclic and acyclic differs in the way the boundary conditions are handled.
	///
	/// During a parametric blend the child generator weights represents the sample points on a line. Based on the value of
	/// m_blendParameter an interval is computed such that the parametric blend lies within this interval and the animations
	/// that bound the interval are blended. There can be multiple animations with the same weight. If that happens then
	/// we have a convention the interval is chosen such that the highest child generator index bounds it on the left side.
	///
	/// In case of a acyclic parametric blend whenever the value of m_blendParameter is less than the value of first child
	/// then the interval between the first and second child is chosen and when it is greater then the value of its last child
	/// then the interval between the second last child and the last child is chosen. The same thing happens in cyclic mode
	/// when the first child weight is equal to the m_minBlendParameter and the last child weight is equal to m_maxBlendParameter.
	/// If that is not the case then when the m_blendParameter goes beyond the first child and m_minBlendParameter is less than
	/// the first child weight or m_blendParameter goes beyond the last child weight and m_maxBlendParameter is greater than
	/// the last child weight the interval is between the first and the last children.
	class hkbBlenderGenerator : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBlenderGenerator;
		inline static constexpr auto VTABLE = VTABLE_hkbBlenderGenerator;

		struct ChildInternalState
		{
			bool isActive;       // 00
			bool syncNextFrame;  // 01
		};
		static_assert(sizeof(ChildInternalState) == 0x2);

		static const hkClass& staticClass()
		{
			return *REL::Relocation<hkClass*>(REL::ID(521195));
		}

		hkbBlenderGenerator() { stl::emplace_vtable(this); };
		~hkbBlenderGenerator() override;  // 00

		// override (hkReferencedObject)
		const hkClass* GetClassType() const override { return &staticClass(); }  // 01

		// override (hkbBindable)
		void collectBindables(hkbBindableCollector& collector) override;  // 03

		// override (hkbNode)
		void                Activate(const hkbContext& a_context) override;                      // 04
		void                Update(const hkbContext& a_context, float a_timestep) override;      // 05
		void                Deactivate(const hkbContext& a_context) override;                    // 07
		int32_t             getMaxNumChildren(GET_CHILDREN_FLAGS flags) override;                // 08
		void                getChildren(GET_CHILDREN_FLAGS flags, ChildrenInfo& ans) override;   // 09
		bool                isValid(hkStringPtr& err) const override;                            // 0A
		hkbNode*            cloneNode(hkbBehaviorGraph& rootBehavior) const override;            // 0C
		hkReferencedObject* createInternalState() override;                                      // 0D
		void                getInternalState(hkReferencedObject& internalState) const override;  // 0E
		void                setInternalState(const hkReferencedObject& internalState) override;  // 10

		// override (hkbGenerator)
		void generate(const hkbContext& a_context, const hkbGeneratorOutput** activeChildrenOutput, hkbGeneratorOutput& output, float timeOffset = 0.0f) const override;  // 17
		bool canRecycleOutput() const override;                                                                                                                           // 18
		void updateSync(const hkbContext& a_context, hkbNodeInfo& info) override;                                                                                         // 19
		void startEcho() override;                                                                                                                                        // 1B

		// Set a child generator
		void setGenerator(int32_t generatorIndex, hkbGenerator* generator);

		// Set the weight associated with a bone and a generator
		void setBoneWeight(int32_t generatorIndex, int32_t boneIndex, float weight = 1);

		// members
		float                              referencePoseWeightThreshold{ 0 };  // 48 - If the sum of non-additive generator weights falls below this threshold, the reference pose is blended in
		float                              blendParameter{ 0 };                // 4C - This value controls the parametric blend
		float                              minCyclicBlendParameter{ 0 };       // 50 - The minimum value the blend parameter can have when doing a cyclic parametric blend
		float                              maxCyclicBlendParameter{ 1 };       // 54 - The maximum value the blend parameter can have when doing a cyclic parametric blend
		int16_t                            indexOfSyncMasterChild{ -1 };       // 58 - If you want a particular child's duration to be used to sync all of the other children, set this to the index of the child.  Otherwise, set it to -1.
		uint16_t                           flags{};                            // 5A - The flags affecting specialized behavior
		uint32_t                           field5C{};                          // 5C
		hkArray<hkbBlenderGeneratorChild*> children;                           // 60 - The children and their info
		hkArray<ChildInternalState>        childrenInternalStates;             // 70 - Information about the state of each child
		hkArray<uint16_t>                  sortedChildren;                     // 80 - The indices of the children sorted according to weight
		float                              endIntervalWeight{};                // 90 - During a parametric blend we compute between which two sample points(animations) does the m_blendParameter lie and store the weight associated with the end sample point
		uint32_t                           numActiveChildren{};                // 94 - The number of active children (those with nonzero weight)
		uint16_t                           beginIntervalIndex{};               // 98 - When parametric blending, this is the index of the child at the beginning of the current interval
		uint16_t                           endIntervalIndex{};                 // 9A - When parametric blending, this is the index of the child at the end of the current interval
		bool                               initSync{};                         // 9C - Whether to start synching on the next updateSync()
		bool                               doSubtractiveBlend{};               // 9D - Whether you want to subtract the last child or not
		char                               pad9E[2];                           // 9D
	};
	static_assert(sizeof(hkbBlenderGenerator) == 0xA0);
}
