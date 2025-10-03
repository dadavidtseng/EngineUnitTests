//----------------------------------------------------------------------------------------------------
// UnitTests_Vec3.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_Vec3();

//----------------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_Vec3_Constructors();
int TestSet_Vec3_StaticConstants();
int TestSet_Vec3_StaticMethods();
int TestSet_Vec3_AccessorMethods();
int TestSet_Vec3_MutatorMethods();
int TestSet_Vec3_Operators();
int TestSet_Vec3_ArithmeticOperators();
int TestSet_Vec3_UnimplementedMethods();
int TestSet_Vec3_Performance_Comprehensive();

//----------------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_Vec3_Constructors
#define ENABLE_TestSet_Vec3_StaticConstants
#define ENABLE_TestSet_Vec3_StaticMethods
#define ENABLE_TestSet_Vec3_AccessorMethods
#define ENABLE_TestSet_Vec3_MutatorMethods
#define ENABLE_TestSet_Vec3_Operators
#define ENABLE_TestSet_Vec3_ArithmeticOperators
#define ENABLE_TestSet_Vec3_UnimplementedMethods
#define ENABLE_TestSet_Vec3_Performance_Comprehensive

//----------------------------------------------------------------------------------------------------
// Performance test configuration
//
#define VEC3_PERFORMANCE_TEST_ITERATIONS 1000000
#define VEC3_PERFORMANCE_WARMUP_ITERATIONS 10000