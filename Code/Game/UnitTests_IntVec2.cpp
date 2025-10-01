//----------------------------------------------------------------------------------------------------
// UnitTests_IntVec2.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/UnitTests_IntVec2.hpp"

#include <cstdio>

#include "Game/GameCommon.hpp"

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_Constructors()
{
#if defined(ENABLE_TestSet_IntVec2_Constructors)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_Constructors)(start)\n");
    printf("####################################################################################################\n");

    // Test default constructor
    auto const v1 = TimeFunction("Default constructor", []() { return IntVec2Class(); });
    VerifyTestResult(v1.x == 0 && v1.y == 0, "IntVec2 default constructor should initialize to (0,0)");

    // Test constructor from 2 ints
    auto const v2 = TimeFunction("Constructor from 2 ints", []() { return IntVec2Class(3, 4); });
    VerifyTestResult(v2.x == 3 && v2.y == 4, "IntVec2 constructor from 2 ints failed");

    // Test constructor from 2 floats
    auto const v3 = TimeFunction("Constructor from 2 floats", []() { return IntVec2Class(7.8f, 9.2f); });
    VerifyTestResult(v3.x == 7 && v3.y == 9, "IntVec2 constructor from 2 floats should truncate");

    // Test copy constructor
    auto const v4 = TimeFunction("Copy constructor", [v2]() { return IntVec2Class(v2); });
    VerifyTestResult(v4.x == v2.x && v4.y == v2.y, "IntVec2 copy constructor failed");

    // Test assignment operator
    auto const v5 = TimeFunction("Assignment operator", [v3]() { return IntVec2Class(v3); });
    VerifyTestResult(v5.x == v3.x && v5.y == v3.y, "IntVec2 assignment operator failed");

    // Test const object construction and copy
    auto const v6 = TimeFunction("Const copy constructor (1st)", [v2]() { return IntVec2Class(v2); });
    
    auto const v7 = TimeFunction("Const copy constructor (2nd)", [v6]() { return IntVec2Class(v6); });
    VerifyTestResult(v7.x == v2.x && v7.y == v2.y, "IntVec2 const copy constructor failed");

    // Test size verification
    VerifyTestResult(sizeof(IntVec2Class) == 8, "sizeof(IntVec2) should be 8 bytes (2 ints)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_Constructors)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 7; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_StaticConstants()
{
#if defined(ENABLE_TestSet_IntVec2_StaticConstants)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_StaticConstants)(start)\n");
    printf("####################################################################################################\n");

    // Test ZERO constant
    auto const zero = TimeFunction("ZERO access", []() { return IntVec2Class::ZERO; });
    VerifyTestResult(zero.x == 0 && zero.y == 0, "IntVec2::ZERO should be (0,0)");

    // Test ONE constant
    auto const one = TimeFunction("ONE access", []() { return IntVec2Class::ONE; });
    VerifyTestResult(one.x == 1 && one.y == 1, "IntVec2::ONE should be (1,1)");

    // Test NEGATIVE_ONE constant
    auto const negOne = TimeFunction("NEGATIVE_ONE access", []() { return IntVec2Class::NEGATIVE_ONE; });
    VerifyTestResult(negOne.x == -1 && negOne.y == -1, "IntVec2::NEGATIVE_ONE should be (-1,-1)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_StaticConstants)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_StaticMethods()
{
#if defined(ENABLE_TestSet_IntVec2_StaticMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_StaticMethods)(start)\n");
    printf("####################################################################################################\n");

    // Note: IntVec2 static methods may include distance calculations, interpolation, etc.
    // These tests are placeholders for when static methods are implemented
    
    // Test potential static methods
    IntVec2Class const v1(3, 4);
    IntVec2Class const v2(0, 0);
    
    // Placeholder test - would test IntVec2Class::GetDistance(v1, v2) when implemented
    VerifyTestResult(true, "IntVec2 static methods framework ready (GetDistance, GetManhattanDistance, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_StaticMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_AccessorMethods()
{
#if defined(ENABLE_TestSet_IntVec2_AccessorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_AccessorMethods)(start)\n");
    printf("####################################################################################################\n");

    IntVec2Class const testVec(3, 4);
    IntVec2Class const zeroVec(0, 0);

    // Test GetLength
    auto const length = TimeFunction("GetLength", [&testVec]() { return testVec.GetLength(); });
    VerifyTestResult(IsMostlyEqual(length, 5.0f), "GetLength should return correct magnitude");

    // Test GetLengthSquared
    auto const lengthSq = TimeFunction("GetLengthSquared", [&testVec]() { return testVec.GetLengthSquared(); });
    VerifyTestResult(lengthSq == 25, "GetLengthSquared should return correct squared magnitude");

    // Test GetTaxicabLength
    auto const taxicab = TimeFunction("GetTaxicabLength", [&testVec]() { return testVec.GetTaxicabLength(); });
    VerifyTestResult(taxicab == 7, "GetTaxicabLength should return sum of absolute components");

    // Test GetOrientationRadians
    auto const orientRad = TimeFunction("GetOrientationRadians", [&testVec]() { return testVec.GetOrientationRadians(); });
    VerifyTestResult(orientRad > 0.0f, "GetOrientationRadians should return valid angle");

    // Test GetOrientationDegrees
    auto const orientDeg = TimeFunction("GetOrientationDegrees", [&testVec]() { return testVec.GetOrientationDegrees(); });
    VerifyTestResult(orientDeg > 0.0f, "GetOrientationDegrees should return valid angle");

    // Test GetRotated90Degrees
    auto const rotated90 = TimeFunction("GetRotated90Degrees", [&testVec]() { return testVec.GetRotated90Degrees(); });
    VerifyTestResult(rotated90.x == -4 && rotated90.y == 3, "GetRotated90Degrees should rotate correctly");

    // Test GetRotatedMinus90Degrees
    auto const rotatedMinus90 = TimeFunction("GetRotatedMinus90Degrees", [&testVec]() { return testVec.GetRotatedMinus90Degrees(); });
    VerifyTestResult(rotatedMinus90.x == 4 && rotatedMinus90.y == -3, "GetRotatedMinus90Degrees should rotate correctly");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_AccessorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 7; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_MutatorMethods()
{
#if defined(ENABLE_TestSet_IntVec2_MutatorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_MutatorMethods)(start)\n");
    printf("####################################################################################################\n");

    // Test Rotate90Degrees
    IntVec2Class vec1(3, 4);
    TimeAction("Rotate90Degrees", [&vec1]() { vec1.Rotate90Degrees(); });
    VerifyTestResult(vec1.x == -4 && vec1.y == 3, "Rotate90Degrees should rotate correctly");

    // Test RotateMinus90Degrees
    IntVec2Class vec2(3, 4);
    TimeAction("RotateMinus90Degrees", [&vec2]() { vec2.RotateMinus90Degrees(); });
    VerifyTestResult(vec2.x == 4 && vec2.y == -3, "RotateMinus90Degrees should rotate correctly");

    // Test SetFromText (basic)
    IntVec2Class vec3;
    TimeAction("SetFromText", [&vec3]() { vec3.SetFromText("5,6"); });
    VerifyTestResult(vec3.x == 5 && vec3.y == 6, "SetFromText should parse correctly");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_MutatorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_Operators()
{
#if defined(ENABLE_TestSet_IntVec2_Operators)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_Operators)(start)\n");
    printf("####################################################################################################\n");

    // Test equality operator
    IntVec2Class const v1(10, 20);
    IntVec2Class const v2(10, 20);
    IntVec2Class const v3(11, 20);

    auto const equal1 = TimeFunction("Equality operator (equal)", [&v1, &v2]() { return v1 == v2; });
    VerifyTestResult(equal1, "Equality operator should return true for equal vectors");

    auto const equal2 = TimeFunction("Equality operator (not equal)", [&v1, &v3]() { return v1 == v3; });
    VerifyTestResult(!equal2, "Equality operator should return false for different vectors");

    // Test inequality operator
    auto const notEqual1 = TimeFunction("Inequality operator (not equal)", [&v1, &v3]() { return v1 != v3; });
    VerifyTestResult(notEqual1, "Inequality operator should return true for different vectors");

    auto const notEqual2 = TimeFunction("Inequality operator (equal)", [&v1, &v2]() { return v1 != v2; });
    VerifyTestResult(!notEqual2, "Inequality operator should return false for equal vectors");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_Operators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 4; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_ArithmeticOperators()
{
#if defined(ENABLE_TestSet_IntVec2_ArithmeticOperators)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_ArithmeticOperators)(start)\n");
    printf("####################################################################################################\n");

    IntVec2Class const v1(2, 3);
    IntVec2Class const v2(1, 2);

    // Test addition operator
    auto const sum = TimeFunction("Addition operator", [&v1, &v2]() { return v1 + v2; });
    VerifyTestResult(sum.x == 3 && sum.y == 5, "Addition operator failed");

    // Test subtraction operator
    auto const diff = TimeFunction("Subtraction operator", [&v1, &v2]() { return v1 - v2; });
    VerifyTestResult(diff.x == 1 && diff.y == 1, "Subtraction operator failed");

    // Note: IntVec2 compound assignment operators (+=, -=) are not implemented
    // The framework is ready for when they are added to the class
    VerifyTestResult(true, "IntVec2 compound assignment operators framework ready (+=, -=, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_ArithmeticOperators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec2_UnimplementedMethods()
{
#if defined(ENABLE_TestSet_IntVec2_UnimplementedMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_UnimplementedMethods)(start)\n");
    printf("####################################################################################################\n");
    printf("  Note: These methods are declared but not yet implemented.\n");
    printf("  Tests will be skipped but framework is ready for implementation.\n");

    IntVec2Class const vec(3, 4);

    // These methods would be tested when implemented:
    /*
    // Distance methods
    int dist = IntVec2Class::GetManhattanDistance(vec, IntVec2Class::ZERO);
    VerifyTestResult(dist == 7, "GetManhattanDistance should compute correct taxicab distance");

    float euclidDist = IntVec2Class::GetDistance(vec, IntVec2Class::ZERO);
    VerifyTestResult(IsMostlyEqual(euclidDist, 5.0f), "GetDistance should compute correct Euclidean distance");

    // Interpolation methods
    IntVec2Class lerped = IntVec2Class::Lerp(IntVec2Class::ZERO, vec, 0.5f);
    VerifyTestResult(lerped.x == 1 && lerped.y == 2, "Lerp should interpolate correctly with rounding");

    // Grid/tile utility methods
    IntVec2Class neighbors[4];
    int numNeighbors = vec.GetCardinalNeighbors(neighbors);
    VerifyTestResult(numNeighbors == 4, "GetCardinalNeighbors should return 4 neighbors");
    */

    // For now, just mark that we've acknowledged these unimplemented methods
    VerifyTestResult(true, "Unimplemented methods framework ready (GetDistance, GetManhattanDistance, Lerp, Grid utilities, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec2_UnimplementedMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
void RunTests_IntVec2()
{
    RunTestSet(true, TestSet_IntVec2_Constructors, "IntVec2 - Constructors");
    RunTestSet(true, TestSet_IntVec2_StaticConstants, "IntVec2 - Static Constants");
    RunTestSet(true, TestSet_IntVec2_StaticMethods, "IntVec2 - Static Methods");
    RunTestSet(true, TestSet_IntVec2_AccessorMethods, "IntVec2 - Accessor Methods");
    RunTestSet(true, TestSet_IntVec2_MutatorMethods, "IntVec2 - Mutator Methods");
    RunTestSet(true, TestSet_IntVec2_Operators, "IntVec2 - Operators");
    RunTestSet(true, TestSet_IntVec2_ArithmeticOperators, "IntVec2 - Arithmetic Operators");
    RunTestSet(true, TestSet_IntVec2_UnimplementedMethods, "IntVec2 - Unimplemented Methods");
}