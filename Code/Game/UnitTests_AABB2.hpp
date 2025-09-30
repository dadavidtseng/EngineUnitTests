//-----------------------------------------------------------------------------------------------
// UnitTests_AABB2.hpp - Comprehensive unit tests for all AABB2 functions
//
#pragma once
#include "Game/GameCommon.hpp"

//-----------------------------------------------------------------------------------------------
void RunTests_AABB2();

//-----------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_AABB2_Constructors();
int TestSet_AABB2_StaticConstants();
int TestSet_AABB2_AccessorMethods();
int TestSet_AABB2_MutatorMethods();
int TestSet_AABB2_Operators();
int TestSet_AABB2_UnimplementedMethods();
int TestSet_AABB2_Performance_Comprehensive();

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
// Performance test configuration
//
#define AABB2_PERFORMANCE_TEST_ITERATIONS 500000
#define AABB2_PERFORMANCE_WARMUP_ITERATIONS 5000