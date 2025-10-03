//----------------------------------------------------------------------------------------------------
// UnitTests_Vec2.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_Vec2();

//----------------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_Vec2_Constructors();
int TestSet_Vec2_StaticConstants();
int TestSet_Vec2_StaticMethods();
int TestSet_Vec2_AccessorMethods();
int TestSet_Vec2_MutatorMethods();
int TestSet_Vec2_Operators();
int TestSet_Vec2_ArithmeticOperators();
int TestSet_Vec2_UnimplementedMethods();
int TestSet_Vec2_Performance_Comprehensive();

//----------------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_Vec2_Constructors
#define ENABLE_TestSet_Vec2_StaticConstants
#define ENABLE_TestSet_Vec2_StaticMethods
#define ENABLE_TestSet_Vec2_AccessorMethods
#define ENABLE_TestSet_Vec2_MutatorMethods
#define ENABLE_TestSet_Vec2_Operators
#define ENABLE_TestSet_Vec2_ArithmeticOperators
#define ENABLE_TestSet_Vec2_UnimplementedMethods
#define ENABLE_TestSet_Vec2_Performance_Comprehensive

//----------------------------------------------------------------------------------------------------
// Performance test configuration
//
#define VEC2_PERFORMANCE_TEST_ITERATIONS 1000000
#define VEC2_PERFORMANCE_WARMUP_ITERATIONS 10000