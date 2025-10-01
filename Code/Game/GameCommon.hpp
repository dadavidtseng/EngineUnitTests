//----------------------------------------------------------------------------------------------------
// GameCommon.hpp
//----------------------------------------------------------------------------------------------------
#pragma once
#include "PerformanceTimer.hpp"

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
void RunTestSet(bool bIsGraded, TestSetFunctionType* const testSetFunction, char const* testSetName);
void VerifyTestResult(bool bIsCorrect, char const* testName);
//-----------------------------------------------------------------------------------------------
// YOU MAY CHANGE any of these #includes to match your engine filenames
//
#include "Engine/Math/AABB2.hpp"      // #include for your Vec2 struct/class
#include "Engine/Math/Vec2.hpp"      // #include for your Vec2 struct/class
#include "Engine/Math/Vec3.hpp"      // #include for your Vec2 struct/class
#include "Engine/Math/Vec4.hpp"      // #include for your Vec2 struct/class
#include "Engine/Math/IntVec2.hpp"   // #include for your IntVec2 struct/class
#include "Engine/Math/IntVec3.hpp"   // #include for your IntVec3 struct/class
#include "Engine/Input/InputSystem.hpp"


//-----------------------------------------------------------------------------------------------
// YOU MAY CHANGE the "Your Name" column of these #defines to match your own classes / functions
//
//		Test name							Your name
//		~~~~~~~~~							~~~~~~~~~
#define Vector2Class						Vec2
#define Vector3Class						Vec3
#define Vector4Class						Vec4
#define IntVec2Class						IntVec2
#define IntVec3Class						IntVec3
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

#define InputSystemClass                    InputSystem
#define InputSystemConfig                   sInputSystemConfig
#define XboxControllerClass                 XboxController
#define sKeyButtonStateClass                sKeyButtonState
#define AnalogJoystickClass                 AnalogJoystick
#define EventArgsClass                 EventArgs

//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(float a, float b, float epsilon = 0.001f);
bool IsMostlyEqual(const Vector2Class& vec2, float x, float y);
bool IsMostlyEqual(const Vector2Class& vec2a, const Vector2Class& vec2b);
bool IsMostlyEqual(const AABB2Class& box1, const AABB2Class& box2);
bool IsMostlyEqual(const AABB2Class& box, float minX, float minY, float maxX, float maxY);

template <typename Func>
decltype(auto) TimeFunction(char const* description, Func&& func)
{
    PerformanceTimer timer;
    timer.Start();
    decltype(auto) result = std::forward<Func>(func)();
    timer.Stop();
    printf("    %s: %.6f us\n", description, timer.GetElapsedMicroseconds());
    return result;
}

template <typename Func>
void TimeAction(char const* description, Func&& func)
{
    PerformanceTimer timer;
    timer.Start();
    std::forward<Func>(func)();
    timer.Stop();
    printf("    %s: %.6f us\n", description, timer.GetElapsedMicroseconds());
}
