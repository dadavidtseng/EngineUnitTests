//----------------------------------------------------------------------------------------------------
// UnitTests_IntVec2.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_IntVec2();

//----------------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_IntVec2_Constructors();
int TestSet_IntVec2_StaticConstants();
int TestSet_IntVec2_StaticMethods();
int TestSet_IntVec2_AccessorMethods();
int TestSet_IntVec2_MutatorMethods();
int TestSet_IntVec2_Operators();
int TestSet_IntVec2_ArithmeticOperators();
int TestSet_IntVec2_UnimplementedMethods();

//----------------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_IntVec2_Constructors
#define ENABLE_TestSet_IntVec2_StaticConstants
#define ENABLE_TestSet_IntVec2_StaticMethods
#define ENABLE_TestSet_IntVec2_AccessorMethods
#define ENABLE_TestSet_IntVec2_MutatorMethods
#define ENABLE_TestSet_IntVec2_Operators
#define ENABLE_TestSet_IntVec2_ArithmeticOperators
#define ENABLE_TestSet_IntVec2_UnimplementedMethods