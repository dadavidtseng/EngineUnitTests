//-----------------------------------------------------------------------------------------------
// UnitTests_AABB2.hpp - Comprehensive unit tests for all AABB2 functions
//
#pragma once
#include "Game/GameCommon.hpp"

//-----------------------------------------------------------------------------------------------
void RunTests_AABB2();

//-----------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_AABB2_Constructors
#define ENABLE_TestSet_AABB2_StaticConstants
#define ENABLE_TestSet_AABB2_AccessorMethods
#define ENABLE_TestSet_AABB2_MutatorMethods
#define ENABLE_TestSet_AABB2_Operators
#define ENABLE_TestSet_AABB2_UnimplementedMethods
#define ENABLE_TestSet_AABB2_Performance_Comprehensive

//-----------------------------------------------------------------------------------------------
// YOU MAY CHANGE any of these #includes to match your engine filenames
//
#include "Engine/Math/Vec2.hpp"      // #include for your Vec2 struct/class
#include "Engine/Math/IntVec2.hpp"   // #include for your IntVec2 struct/class
#include "Engine/Math/AABB2.hpp"     // #include for your AABB2 struct/class

//-----------------------------------------------------------------------------------------------
// YOU MAY CHANGE the "Your Name" column of these #defines to match your own classes / functions
//
//		Test name							Your name
//		~~~~~~~~~							~~~~~~~~~
#define Vector2Class						Vec2
#define IntVec2Class						IntVec2
#define AABB2Class							AABB2
#define AABB2_Mins							m_mins		// e.g. "mins" if your AABB2 is used as "myBox.mins"
#define AABB2_Maxs							m_maxs		// e.g. "maxs" if your AABB2 is used as "myBox.maxs"

#define AABB2_IsPointInside					IsPointInside
#define AABB2_GetCenter						GetCenter
#define AABB2_GetDimensions					GetDimensions
#define AABB2_GetNearestPoint				GetNearestPoint
#define AABB2_GetPointAtUV					GetPointAtUV
#define AABB2_GetUVForPoint					GetUVForPoint
#define AABB2_Translate						Translate
#define AABB2_SetCenter						SetCenter
#define AABB2_SetDimensions					SetDimensions
#define AABB2_StretchToIncludePoint			StretchToIncludePoint

//-----------------------------------------------------------------------------------------------
// Performance test configuration
//
#define AABB2_PERFORMANCE_TEST_ITERATIONS 500000
#define AABB2_PERFORMANCE_WARMUP_ITERATIONS 5000