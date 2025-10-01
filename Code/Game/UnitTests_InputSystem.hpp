//----------------------------------------------------------------------------------------------------
// UnitTests_InputSystem.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//----------------------------------------------------------------------------------------------------
void RunTests_InputSystem();

//-----------------------------------------------------------------------------------------------
// Forward declarations for all test sets
//
int TestSet_InputSystem_Construction();
int TestSet_InputSystem_KeyboardInput();
int TestSet_InputSystem_XboxController();
int TestSet_InputSystem_CursorManagement();
int TestSet_InputSystem_FrameManagement();
int TestSet_InputSystem_EventHandling();
int TestSet_InputSystem_StateTracking();
int TestSet_InputSystem_UnimplementedMethods();

//-----------------------------------------------------------------------------------------------
// YOU MAY COMMENT THESE OUT TEMPORARILY to disable certain test sets while you work.
// For every assignment submission, all test sets must be enabled.
//
#define ENABLE_TestSet_InputSystem_Construction
#define ENABLE_TestSet_InputSystem_KeyboardInput
#define ENABLE_TestSet_InputSystem_XboxController
#define ENABLE_TestSet_InputSystem_CursorManagement
#define ENABLE_TestSet_InputSystem_FrameManagement
#define ENABLE_TestSet_InputSystem_EventHandling
#define ENABLE_TestSet_InputSystem_StateTracking
#define ENABLE_TestSet_InputSystem_UnimplementedMethods
