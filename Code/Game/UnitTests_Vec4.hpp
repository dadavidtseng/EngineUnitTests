//----------------------------------------------------------------------------------------------------
// UnitTests_Vec4.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_Vec4();

//----------------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_Vec4_Constructors();
int TestSet_Vec4_StaticConstants();
int TestSet_Vec4_StaticMethods();
int TestSet_Vec4_AccessorMethods();
int TestSet_Vec4_MutatorMethods();
int TestSet_Vec4_Operators();
int TestSet_Vec4_ArithmeticOperators();
int TestSet_Vec4_UnimplementedMethods();

//----------------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_Vec4_Constructors
#define ENABLE_TestSet_Vec4_StaticConstants
#define ENABLE_TestSet_Vec4_StaticMethods
#define ENABLE_TestSet_Vec4_AccessorMethods
#define ENABLE_TestSet_Vec4_MutatorMethods
#define ENABLE_TestSet_Vec4_Operators
#define ENABLE_TestSet_Vec4_ArithmeticOperators
#define ENABLE_TestSet_Vec4_UnimplementedMethods