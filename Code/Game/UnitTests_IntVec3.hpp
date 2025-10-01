//----------------------------------------------------------------------------------------------------
// UnitTests_IntVec3.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_IntVec3();

//----------------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_IntVec3_Constructors();
int TestSet_IntVec3_StaticConstants();
int TestSet_IntVec3_StaticMethods();
int TestSet_IntVec3_AccessorMethods();
int TestSet_IntVec3_MutatorMethods();
int TestSet_IntVec3_Operators();
int TestSet_IntVec3_ArithmeticOperators();
int TestSet_IntVec3_UnimplementedMethods();

//----------------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_IntVec3_Constructors
#define ENABLE_TestSet_IntVec3_StaticConstants
#define ENABLE_TestSet_IntVec3_StaticMethods
#define ENABLE_TestSet_IntVec3_AccessorMethods
#define ENABLE_TestSet_IntVec3_MutatorMethods
#define ENABLE_TestSet_IntVec3_Operators
#define ENABLE_TestSet_IntVec3_ArithmeticOperators
#define ENABLE_TestSet_IntVec3_UnimplementedMethods