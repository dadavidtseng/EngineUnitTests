//----------------------------------------------------------------------------------------------------
// GameCommon.hpp
//----------------------------------------------------------------------------------------------------
#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//	DO NOT MODIFY ANY CODE BELOW HERE WITHOUT EXPRESS PERMISSION FROM YOUR PROFESSOR
//	(as doing so will be considered cheating and have serious academic consequences)
//
/////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------------------------
// Global typedefs
//
typedef int (TestSetFunctionType)(); // Function signature type for all test functions

//-----------------------------------------------------------------------------------------------
// Functions provided by Main.cpp, but globally accessible to all test files
//
void RunTestSet(bool isGraded, TestSetFunctionType testSetFunction, char const* testSetName);
void VerifyTestResult(bool isCorrect, char const* testName);
