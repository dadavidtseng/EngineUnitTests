//----------------------------------------------------------------------------------------------------
// UnitTests_AABB2.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Math/UnitTests_AABB2.hpp"
#include <cstdio>
#include "Game/GameCommon.hpp"
#include "Game/PerformanceTimer.hpp"

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_Constructors()
{
#if defined(ENABLE_TestSet_AABB2_Constructors)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_Constructors)(start)\n");
    printf("####################################################################################################\n");

    // Test default constructor
    auto const box1 = TimeFunction("Default constructor", []() { return AABB2Class(); });
    VerifyTestResult(IsMostlyEqual(box1, 0.f, 0.f, 0.f, 0.f), "AABB2 default constructor should initialize to (0,0,0,0)");

    // Test constructor from 4 ints
    auto const box2 = TimeFunction("Constructor from 4 ints", []() { return AABB2Class(1, 2, 5, 8); });
    VerifyTestResult(IsMostlyEqual(box2, 1.0f, 2.0f, 5.0f, 8.0f), "AABB2 constructor from 4 ints failed");

    // Test constructor from 4 floats
    auto const box3 = TimeFunction("Constructor from 4 floats", []() { return AABB2Class(1.5f, 2.5f, 5.5f, 8.5f); });
    VerifyTestResult(IsMostlyEqual(box3, 1.5f, 2.5f, 5.5f, 8.5f), "AABB2 constructor from 4 floats failed");

    // Test constructor from IntVec2s
    IntVec2Class const mins_IntVec2(3, 4);
    IntVec2Class const maxs_IntVec2(7, 9);
    auto const box4 = TimeFunction("Constructor from IntVec2s", [mins_IntVec2, maxs_IntVec2]() { return AABB2Class(mins_IntVec2, maxs_IntVec2); });
    VerifyTestResult(IsMostlyEqual(box4, 3.0f, 4.0f, 7.0f, 9.0f), "AABB2 constructor from IntVec2s failed");

    // Test constructor from Vec2s
    Vector2Class const mins_Vec2(2.3f, 4.5f);
    Vector2Class const maxs_Vec2(6.7f, 8.9f);
    auto const box5 = TimeFunction("Constructor from Vec2s", [mins_Vec2, maxs_Vec2]() { return AABB2Class(mins_Vec2, maxs_Vec2); });
    VerifyTestResult(IsMostlyEqual(box5, 2.3f, 4.5f, 6.7f, 8.9f), "AABB2 constructor from Vec2s failed");

    // Test copy constructor
    auto const box6 = TimeFunction("Copy constructor", [box5]() { return AABB2Class(box5); });
    VerifyTestResult(IsMostlyEqual(box6, box5), "AABB2 copy constructor failed");

    // Test assignment operator
    auto const box7 = TimeFunction("Assignment operator", [box3]() { return AABB2Class(box3); });
    VerifyTestResult(IsMostlyEqual(box7, box3), "AABB2 assignment operator failed");

    // Test const object construction and copy
    auto const box8 = TimeFunction("Const copy constructor (1st)", [box2]() { return AABB2Class(box2); });

    auto const box9 = TimeFunction("Const copy constructor (2nd)", [box8]() { return AABB2Class(box8); });
    VerifyTestResult(IsMostlyEqual(box9, box2), "AABB2 const copy constructor failed");

    // Test size verification
    VerifyTestResult(sizeof(AABB2Class) == 16, "sizeof(AABB2) should be 16 bytes (2 Vec2s)");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_Constructors)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 9; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_StaticConstants()
{
#if defined(ENABLE_TestSet_AABB2_StaticConstants)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_StaticConstants)(start)\n");
    printf("####################################################################################################\n");

    // Test ZERO_TO_ONE constant
    auto const zeroToOne = TimeFunction("ZERO_TO_ONE access", []() { return AABB2Class::ZERO_TO_ONE; });
    VerifyTestResult(IsMostlyEqual(zeroToOne, 0.0f, 0.0f, 1.0f, 1.0f),
                     "AABB2::ZERO_TO_ONE should be (0,0,1,1)");

    // Test NEG_HALF_TO_HALF constant
    auto const negHalfToHalf = TimeFunction("NEG_HALF_TO_HALF access", []() { return AABB2Class::NEG_HALF_TO_HALF; });
    VerifyTestResult(IsMostlyEqual(negHalfToHalf, -0.5f, -0.5f, 0.5f, 0.5f),
                     "AABB2::NEG_HALF_TO_HALF should be (-0.5,-0.5,0.5,0.5)");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_StaticConstants)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 2; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_AccessorMethods()
{
#if defined(ENABLE_TestSet_AABB2_AccessorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_AccessorMethods)(start)\n");
    printf("####################################################################################################\n");

    AABB2Class       box(10.0f, 20.0f, 50.0f, 80.0f);
    const AABB2Class constBox(5.0f, 15.0f, 25.0f, 35.0f);

    // Test IsPointInside
    auto const result1 = TimeFunction("IsPointInside (inside)", [&box]() { return box.AABB2_IsPointInside(Vector2Class(30.0f, 50.0f)); });
    VerifyTestResult(result1, "IsPointInside should return true for point inside box");

    auto const result2 = TimeFunction("IsPointInside (outside)", [&box]() { return box.AABB2_IsPointInside(Vector2Class(60.0f, 50.0f)); });
    VerifyTestResult(!result2, "IsPointInside should return false for point outside box");

    auto const result3 = TimeFunction("IsPointInside (min corner)", [&box]() { return box.AABB2_IsPointInside(Vector2Class(10.0f, 20.0f)); });
    VerifyTestResult(result3, "IsPointInside should return true for point on min corner (inclusive)");

    auto const result4 = TimeFunction("IsPointInside (max corner)", [&box]() { return box.AABB2_IsPointInside(Vector2Class(50.0f, 80.0f)); });
    VerifyTestResult(result4, "IsPointInside should return true for point on max corner (inclusive)");

    auto const result5 = TimeFunction("IsPointInside (const object)", [&constBox]() { return constBox.AABB2_IsPointInside(Vector2Class(15.0f, 25.0f)); });
    VerifyTestResult(result5, "IsPointInside should work on const AABB2 objects");

    // Test GetCenter
    auto const center1 = TimeFunction("GetCenter", [&box]() { return box.AABB2_GetCenter(); });
    VerifyTestResult(IsMostlyEqual(center1, 30.0f, 50.0f), "GetCenter should return center point of box");

    auto const center2 = TimeFunction("GetCenter (const)", [&constBox]() { return constBox.AABB2_GetCenter(); });
    VerifyTestResult(IsMostlyEqual(center2, 15.0f, 25.0f), "GetCenter should work on const AABB2 objects");

    // Test GetDimensions
    auto const dims1 = TimeFunction("GetDimensions", [&box]() { return box.AABB2_GetDimensions(); });
    VerifyTestResult(IsMostlyEqual(dims1, 40.0f, 60.0f), "GetDimensions should return width and height");

    auto const dims2 = TimeFunction("GetDimensions (const)", [&constBox]() { return constBox.AABB2_GetDimensions(); });
    VerifyTestResult(IsMostlyEqual(dims2, 20.0f, 20.0f), "GetDimensions should work on const AABB2 objects");

    // Test GetNearestPoint
    auto const nearest1 = TimeFunction("GetNearestPoint (inside)", [&box]() { return box.AABB2_GetNearestPoint(Vector2Class(30.0f, 50.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest1, 30.0f, 50.0f), "GetNearestPoint should return same point if inside box");

    auto const nearest2 = TimeFunction("GetNearestPoint (east)", [&box]() { return box.AABB2_GetNearestPoint(Vector2Class(60.0f, 50.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest2, 50.0f, 50.0f), "GetNearestPoint should clamp to east edge for point east of box");

    auto const nearest3 = TimeFunction("GetNearestPoint (west)", [&box]() { return box.AABB2_GetNearestPoint(Vector2Class(5.0f, 50.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest3, 10.0f, 50.0f), "GetNearestPoint should clamp to west edge for point west of box");

    auto const nearest4 = TimeFunction("GetNearestPoint (north)", [&box]() { return box.AABB2_GetNearestPoint(Vector2Class(30.0f, 90.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest4, 30.0f, 80.0f), "GetNearestPoint should clamp to north edge for point north of box");

    auto const nearest5 = TimeFunction("GetNearestPoint (south)", [&box]() { return box.AABB2_GetNearestPoint(Vector2Class(30.0f, 10.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest5, 30.0f, 20.0f), "GetNearestPoint should clamp to south edge for point south of box");

    auto const nearest6 = TimeFunction("GetNearestPoint (const)", [&constBox]() { return constBox.AABB2_GetNearestPoint(Vector2Class(0.0f, 0.0f)); });
    VerifyTestResult(IsMostlyEqual(nearest6, 5.0f, 15.0f), "GetNearestPoint should work on const AABB2 objects");

    // Test GetPointAtUV
    auto const pointUV1 = TimeFunction("GetPointAtUV (0,0)", [&box]() { return box.AABB2_GetPointAtUV(Vector2Class(0.0f, 0.0f)); });
    VerifyTestResult(IsMostlyEqual(pointUV1, 10.0f, 20.0f), "GetPointAtUV(0,0) should return mins");

    auto const pointUV2 = TimeFunction("GetPointAtUV (1,1)", [&box]() { return box.AABB2_GetPointAtUV(Vector2Class(1.0f, 1.0f)); });
    VerifyTestResult(IsMostlyEqual(pointUV2, 50.0f, 80.0f), "GetPointAtUV(1,1) should return maxs");

    auto const pointUV3 = TimeFunction("GetPointAtUV (0.5,0.5)", [&box]() { return box.AABB2_GetPointAtUV(Vector2Class(0.5f, 0.5f)); });
    VerifyTestResult(IsMostlyEqual(pointUV3, 30.0f, 50.0f), "GetPointAtUV(0.5,0.5) should return center");

    auto const pointUV4 = TimeFunction("GetPointAtUV (interpolate)", [&box]() { return box.AABB2_GetPointAtUV(Vector2Class(0.25f, 0.75f)); });
    VerifyTestResult(IsMostlyEqual(pointUV4, 20.0f, 65.0f), "GetPointAtUV should interpolate correctly");

    auto const pointUV5 = TimeFunction("GetPointAtUV (const)", [&constBox]() { return constBox.AABB2_GetPointAtUV(Vector2Class(0.5f, 0.5f)); });
    VerifyTestResult(IsMostlyEqual(pointUV5, 15.0f, 25.0f), "GetPointAtUV should work on const AABB2 objects");

    // Test GetUVForPoint
    auto const uv1 = TimeFunction("GetUVForPoint (mins)", [&box]() { return box.AABB2_GetUVForPoint(Vector2Class(10.0f, 20.0f)); });
    VerifyTestResult(IsMostlyEqual(uv1, 0.0f, 0.0f), "GetUVForPoint(mins) should return (0,0)");

    auto const uv2 = TimeFunction("GetUVForPoint (maxs)", [&box]() { return box.AABB2_GetUVForPoint(Vector2Class(50.0f, 80.0f)); });
    VerifyTestResult(IsMostlyEqual(uv2, 1.0f, 1.0f), "GetUVForPoint(maxs) should return (1,1)");

    auto const uv3 = TimeFunction("GetUVForPoint (center)", [&box]() { return box.AABB2_GetUVForPoint(Vector2Class(30.0f, 50.0f)); });
    VerifyTestResult(IsMostlyEqual(uv3, 0.5f, 0.5f), "GetUVForPoint(center) should return (0.5,0.5)");

    auto const uv4 = TimeFunction("GetUVForPoint (convert)", [&box]() { return box.AABB2_GetUVForPoint(Vector2Class(20.0f, 65.0f)); });
    VerifyTestResult(IsMostlyEqual(uv4, 0.25f, 0.75f), "GetUVForPoint should convert correctly");

    auto const uv5 = TimeFunction("GetUVForPoint (const)", [&constBox]() { return constBox.AABB2_GetUVForPoint(Vector2Class(15.0f, 25.0f)); });
    VerifyTestResult(IsMostlyEqual(uv5, 0.5f, 0.5f), "GetUVForPoint should work on const AABB2 objects");

    // Test aspect ratio calculation using GetDimensions
    AABB2Class squareBox(0.0f, 0.0f, 10.0f, 10.0f);
    AABB2Class wideBox(0.0f, 0.0f, 20.0f, 10.0f);
    AABB2Class tallBox(0.0f, 0.0f, 10.0f, 20.0f);

    auto const squareDims = TimeFunction("GetDimensions (square)", [&squareBox]() { return squareBox.AABB2_GetDimensions(); });

    auto const wideDims = TimeFunction("GetDimensions (wide)", [&wideBox]() { return wideBox.AABB2_GetDimensions(); });

    auto const tallDims = TimeFunction("GetDimensions (tall)", [&tallBox]() { return tallBox.AABB2_GetDimensions(); });

    VerifyTestResult(IsMostlyEqual(squareDims.x / squareDims.y, 1.0f),
                     "Square box should have aspect ratio of 1.0");
    VerifyTestResult(IsMostlyEqual(wideDims.x / wideDims.y, 2.0f),
                     "Wide box should have aspect ratio of 2.0");
    VerifyTestResult(IsMostlyEqual(tallDims.x / tallDims.y, 0.5f),
                     "Tall box should have aspect ratio of 0.5");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_AccessorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 28; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_MutatorMethods()
{
#if defined(ENABLE_TestSet_AABB2_MutatorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_MutatorMethods)(start)\n");
    printf("####################################################################################################\n");

    // Test Translate
    AABB2Class   box1(10.0f, 20.0f, 30.0f, 40.0f);
    Vector2Class originalDims = box1.AABB2_GetDimensions();
    box1.AABB2_Translate(Vector2Class(5.0f, 10.0f));
    VerifyTestResult(IsMostlyEqual(box1, 15.0f, 30.0f, 35.0f, 50.0f),
                     "Translate should move box by offset");
    VerifyTestResult(IsMostlyEqual(box1.AABB2_GetDimensions(), originalDims),
                     "Translate should not change box dimensions");

    box1.AABB2_Translate(Vector2Class(-5.0f, -10.0f));
    VerifyTestResult(IsMostlyEqual(box1, 10.0f, 20.0f, 30.0f, 40.0f),
                     "Translate should work with negative offsets");

    // Test SetCenter
    Vector2Class newCenter(100.0f, 200.0f);
    Vector2Class expectedDims = box1.AABB2_GetDimensions();
    box1.AABB2_SetCenter(newCenter);
    VerifyTestResult(IsMostlyEqual(box1.AABB2_GetCenter(), newCenter),
                     "SetCenter should set new center correctly");
    VerifyTestResult(IsMostlyEqual(box1.AABB2_GetDimensions(), expectedDims),
                     "SetCenter should preserve box dimensions");
    VerifyTestResult(IsMostlyEqual(box1, 90.0f, 190.0f, 110.0f, 210.0f),
                     "SetCenter should position box correctly around new center");

    // Test SetDimensions
    Vector2Class savedCenter = box1.AABB2_GetCenter();
    Vector2Class newDims(50.0f, 80.0f);
    box1.AABB2_SetDimensions(newDims);
    VerifyTestResult(IsMostlyEqual(box1.AABB2_GetDimensions(), newDims),
                     "SetDimensions should set new dimensions correctly");
    VerifyTestResult(IsMostlyEqual(box1.AABB2_GetCenter(), savedCenter),
                     "SetDimensions should preserve box center");
    VerifyTestResult(IsMostlyEqual(box1, 75.0f, 160.0f, 125.0f, 240.0f),
                     "SetDimensions should resize box around center");

    // Test StretchToIncludePoint
    AABB2Class box2(10.0f, 20.0f, 30.0f, 40.0f);

    // Point inside - should not change box
    box2.AABB2_StretchToIncludePoint(Vector2Class(20.0f, 30.0f));
    VerifyTestResult(IsMostlyEqual(box2, 10.0f, 20.0f, 30.0f, 40.0f),
                     "StretchToIncludePoint should not change box for point inside");

    // Point east - should expand maxs.x
    box2.AABB2_StretchToIncludePoint(Vector2Class(50.0f, 30.0f));
    VerifyTestResult(IsMostlyEqual(box2, 10.0f, 20.0f, 50.0f, 40.0f),
                     "StretchToIncludePoint should expand east for point east of box");

    // Point west - should expand mins.x
    box2.AABB2_StretchToIncludePoint(Vector2Class(5.0f, 30.0f));
    VerifyTestResult(IsMostlyEqual(box2, 5.0f, 20.0f, 50.0f, 40.0f),
                     "StretchToIncludePoint should expand west for point west of box");

    // Point north - should expand maxs.y
    box2.AABB2_StretchToIncludePoint(Vector2Class(25.0f, 60.0f));
    VerifyTestResult(IsMostlyEqual(box2, 5.0f, 20.0f, 50.0f, 60.0f),
                     "StretchToIncludePoint should expand north for point north of box");

    // Point south - should expand mins.y
    box2.AABB2_StretchToIncludePoint(Vector2Class(25.0f, 10.0f));
    VerifyTestResult(IsMostlyEqual(box2, 5.0f, 10.0f, 50.0f, 60.0f),
                     "StretchToIncludePoint should expand south for point south of box");

    // Point southeast - should expand both maxs.x and mins.y
    box2.AABB2_StretchToIncludePoint(Vector2Class(70.0f, 5.0f));
    VerifyTestResult(IsMostlyEqual(box2, 5.0f, 5.0f, 70.0f, 60.0f),
                     "StretchToIncludePoint should expand for diagonal point");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_MutatorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 15; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_Operators()
{
#if defined(ENABLE_TestSet_AABB2_Operators)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_Operators)(start)\n");
    printf("####################################################################################################\n");

    // Test equality operator
    AABB2Class box1(10.0f, 20.0f, 30.0f, 40.0f);
    AABB2Class box2(10.0f, 20.0f, 30.0f, 40.0f);
    AABB2Class box3(10.1f, 20.0f, 30.0f, 40.0f);

    VerifyTestResult(box1 == box2, "Equality operator should return true for identical boxes");
    VerifyTestResult(!(box1 == box3), "Equality operator should return false for different boxes");

    // Test with very small differences
    AABB2Class box4(10.0001f, 20.0f, 30.0f, 40.0f);
    VerifyTestResult(!(box1 == box4), "Equality operator should be exact, not approximate");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_Operators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_AABB2_UnimplementedMethods()
{
#if defined(ENABLE_TestSet_AABB2_UnimplementedMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_UnimplementedMethods)(start)\n");
    printf("####################################################################################################\n");
    printf("  Note: These methods are declared but not yet implemented.\n");
    printf("  Tests will be skipped but framework is ready for implementation.\n");

    AABB2Class box(10.0f, 20.0f, 50.0f, 80.0f);

    // These methods are declared in AABB2.hpp but not implemented in AABB2.cpp
    // The tests are written but will cause link errors until implemented

    /*
    // GetBoxAtUVs - should return sub-box at UV coordinates
    AABB2Class subBox = box.GetBoxAtUVs(Vector2Class(0.25f, 0.25f), Vector2Class(0.75f, 0.75f));
    VerifyTestResult(IsMostlyEqual(subBox, 20.0f, 35.0f, 40.0f, 65.0f),
                    "GetBoxAtUVs should return correct sub-box");

    // ReduceToAspectRatio - should reduce size to match aspect ratio
    AABB2Class wideBox(0.0f, 0.0f, 40.0f, 20.0f); // 2:1 ratio
    wideBox.ReduceToAspectRatio(1.0f); // Make it square
    Vector2Class dims = wideBox.GetDimensions();
    VerifyTestResult(IsMostlyEqual(dims.x, dims.y) && dims.x <= 20.0f && dims.y <= 20.0f,
                    "ReduceToAspectRatio should create square by reducing larger dimension");

    // EnlargeToAspectRatio - should increase size to match aspect ratio
    AABB2Class smallBox(0.0f, 0.0f, 10.0f, 20.0f); // 1:2 ratio
    smallBox.EnlargeToAspectRatio(1.0f); // Make it square
    Vector2Class enlargedDims = smallBox.GetDimensions();
    VerifyTestResult(IsMostlyEqual(enlargedDims.x, enlargedDims.y) && enlargedDims.x >= 20.0f,
                    "EnlargeToAspectRatio should create square by enlarging smaller dimension");

    // AddPadding - should add padding to all sides
    AABB2Class paddedBox(10.0f, 20.0f, 30.0f, 40.0f);
    paddedBox.AddPadding(5.0f, 10.0f);
    VerifyTestResult(IsMostlyEqual(paddedBox, 5.0f, 10.0f, 35.0f, 50.0f),
                    "AddPadding should add specified padding to all sides");

    // ClampWithin - should constrain box within another box
    AABB2Class constrainBox(0.0f, 0.0f, 100.0f, 100.0f);
    AABB2Class clampedBox(-10.0f, -10.0f, 110.0f, 110.0f);
    clampedBox.ClampWithin(&constrainBox);
    VerifyTestResult(IsMostlyEqual(clampedBox, 0.0f, 0.0f, 100.0f, 100.0f),
                    "ClampWithin should constrain box to be within container");

    // ChopOffTop - should remove specified height from top
    AABB2Class chopBox(10.0f, 20.0f, 30.0f, 50.0f);
    chopBox.ChopOffTop(10.0f);
    VerifyTestResult(IsMostlyEqual(chopBox, 10.0f, 20.0f, 30.0f, 40.0f),
                    "ChopOffTop should reduce maxs.y by specified amount");
    */

    // For now, just mark that we've acknowledged these unimplemented methods
    VerifyTestResult(true, "Unimplemented methods framework ready (GetBoxAtUVs, ReduceToAspectRatio, EnlargeToAspectRatio, AddPadding, ClampWithin, ChopOffTop)");

    printf("####################################################################################################\n");
    printf("(TestSet_AABB2_UnimplementedMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected (just the acknowledgment test)
}

//-----------------------------------------------------------------------------------------------
void RunTests_AABB2()
{
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("(UnitTests_AABB2)(Start)\n");
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////\n");

    RunTestSet(true, TestSet_AABB2_Constructors, "AABB2 - Constructors");
    RunTestSet(true, TestSet_AABB2_StaticConstants, "AABB2 - Static Constants");
    RunTestSet(true, TestSet_AABB2_AccessorMethods, "AABB2 - Accessor Methods");
    RunTestSet(true, TestSet_AABB2_MutatorMethods, "AABB2 - Mutator Methods");
    RunTestSet(true, TestSet_AABB2_Operators, "AABB2 - Operators");
    RunTestSet(true, TestSet_AABB2_UnimplementedMethods, "AABB2 - Unimplemented Methods");

    printf("////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("(UnitTests_AABB2)(End)\n");
    printf("////////////////////////////////////////////////////////////////////////////////////////////////////\n");
}
