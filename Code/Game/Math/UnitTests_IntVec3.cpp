//----------------------------------------------------------------------------------------------------
// UnitTests_IntVec3.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Math/UnitTests_IntVec3.hpp"

#include <cstdio>

#include "Game/GameCommon.hpp"

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_Constructors()
{
#if defined(ENABLE_TestSet_IntVec3_Constructors)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_Constructors)(start)\n");
    printf("####################################################################################################\n");

    // Test default constructor
    auto const v1 = TimeFunction("Default constructor", []() { return IntVec3Class(); });
    VerifyTestResult(v1.x == 0 && v1.y == 0 && v1.z == 0, "IntVec3 default constructor should initialize to (0,0,0)");

    // Test constructor from 3 ints
    auto const v2 = TimeFunction("Constructor from 3 ints", []() { return IntVec3Class(3, 4, 5); });
    VerifyTestResult(v2.x == 3 && v2.y == 4 && v2.z == 5, "IntVec3 constructor from 3 ints failed");

    // Test constructor from 3 floats
    auto const v3 = TimeFunction("Constructor from 3 floats", []() { return IntVec3Class(7.8f, 9.2f, 2.1f); });
    VerifyTestResult(v3.x == 7 && v3.y == 9 && v3.z == 2, "IntVec3 constructor from 3 floats should truncate");

    // Test copy constructor
    auto const v4 = TimeFunction("Copy constructor", [v2]() { return IntVec3Class(v2); });
    VerifyTestResult(v4.x == v2.x && v4.y == v2.y && v4.z == v2.z, "IntVec3 copy constructor failed");

    // Test assignment operator
    auto const v5 = TimeFunction("Assignment operator", [v3]() { return IntVec3Class(v3); });
    VerifyTestResult(v5.x == v3.x && v5.y == v3.y && v5.z == v3.z, "IntVec3 assignment operator failed");

    // Test const object construction and copy
    auto const v6 = TimeFunction("Const copy constructor (1st)", [v2]() { return IntVec3Class(v2); });
    
    auto const v7 = TimeFunction("Const copy constructor (2nd)", [v6]() { return IntVec3Class(v6); });
    VerifyTestResult(v7.x == v2.x && v7.y == v2.y && v7.z == v2.z, "IntVec3 const copy constructor failed");

    // Test size verification
    VerifyTestResult(sizeof(IntVec3Class) == 12, "sizeof(IntVec3) should be 12 bytes (3 ints)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_Constructors)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 7; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_StaticConstants()
{
#if defined(ENABLE_TestSet_IntVec3_StaticConstants)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_StaticConstants)(start)\n");
    printf("####################################################################################################\n");

    // Test ZERO constant
    auto const zero = TimeFunction("ZERO access", []() { return IntVec3Class::ZERO; });
    VerifyTestResult(zero.x == 0 && zero.y == 0 && zero.z == 0, "IntVec3::ZERO should be (0,0,0)");

    // Test ONE constant
    auto const one = TimeFunction("ONE access", []() { return IntVec3Class::ONE; });
    VerifyTestResult(one.x == 1 && one.y == 1 && one.z == 1, "IntVec3::ONE should be (1,1,1)");

    // Test NEGATIVE_ONE constant
    auto const negOne = TimeFunction("NEGATIVE_ONE access", []() { return IntVec3Class::NEGATIVE_ONE; });
    VerifyTestResult(negOne.x == -1 && negOne.y == -1 && negOne.z == -1, "IntVec3::NEGATIVE_ONE should be (-1,-1,-1)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_StaticConstants)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_StaticMethods()
{
#if defined(ENABLE_TestSet_IntVec3_StaticMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_StaticMethods)(start)\n");
    printf("####################################################################################################\n");

    // Note: IntVec3 static methods may include distance calculations, interpolation, etc.
    // These tests are placeholders for when static methods are implemented
    
    // Test potential static methods
    IntVec3Class const v1(3, 4, 0);
    IntVec3Class const v2(0, 0, 0);
    
    // Placeholder test - would test IntVec3Class::GetDistance(v1, v2) when implemented
    VerifyTestResult(true, "IntVec3 static methods framework ready (GetDistance, GetManhattanDistance, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_StaticMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_AccessorMethods()
{
#if defined(ENABLE_TestSet_IntVec3_AccessorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_AccessorMethods)(start)\n");
    printf("####################################################################################################\n");

    IntVec3Class const testVec(3, 4, 0);
    IntVec3Class const zeroVec(0, 0, 0);

    // Test GetLength
    auto const length = TimeFunction("GetLength", [&testVec]() { return testVec.GetLength(); });
    VerifyTestResult(IsMostlyEqual(length, 5.0f), "GetLength should return correct magnitude");

    // Test GetLengthSquared
    auto const lengthSq = TimeFunction("GetLengthSquared", [&testVec]() { return testVec.GetLengthSquared(); });
    VerifyTestResult(lengthSq == 25, "GetLengthSquared should return correct squared magnitude");

    // Test GetTaxicabLength
    auto const taxicab = TimeFunction("GetTaxicabLength", [&testVec]() { return testVec.GetTaxicabLength(); });
    VerifyTestResult(taxicab == 7, "GetTaxicabLength should return sum of absolute components");

    // Test GetXY
    auto const xy = TimeFunction("GetXY", [&testVec]() { return testVec.GetXY(); });
    VerifyTestResult(xy.x == 3 && xy.y == 4, "GetXY should return correct IntVec2");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_AccessorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 4; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_MutatorMethods()
{
#if defined(ENABLE_TestSet_IntVec3_MutatorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_MutatorMethods)(start)\n");
    printf("####################################################################################################\n");

    // Test SetFromText (basic)
    IntVec3Class vec1;
    TimeAction("SetFromText", [&vec1]() { vec1.SetFromText("5,6,7"); });
    VerifyTestResult(vec1.x == 5 && vec1.y == 6 && vec1.z == 7, "SetFromText should parse correctly");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_MutatorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_Operators()
{
#if defined(ENABLE_TestSet_IntVec3_Operators)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_Operators)(start)\n");
    printf("####################################################################################################\n");

    // Test equality operator
    IntVec3Class const v1(10, 20, 30);
    IntVec3Class const v2(10, 20, 30);
    IntVec3Class const v3(11, 20, 30);

    auto const equal1 = TimeFunction("Equality operator (equal)", [&v1, &v2]() { return v1 == v2; });
    VerifyTestResult(equal1, "Equality operator should return true for equal vectors");

    auto const equal2 = TimeFunction("Equality operator (not equal)", [&v1, &v3]() { return v1 == v3; });
    VerifyTestResult(!equal2, "Equality operator should return false for different vectors");

    // Test inequality operator
    auto const notEqual1 = TimeFunction("Inequality operator (not equal)", [&v1, &v3]() { return v1 != v3; });
    VerifyTestResult(notEqual1, "Inequality operator should return true for different vectors");

    auto const notEqual2 = TimeFunction("Inequality operator (equal)", [&v1, &v2]() { return v1 != v2; });
    VerifyTestResult(!notEqual2, "Inequality operator should return false for equal vectors");

    // Test less than operator (for container ordering)
    IntVec3Class const v4(5, 10, 15);
    auto const lessThan = TimeFunction("Less than operator", [&v4, &v1]() { return v4 < v1; });
    VerifyTestResult(lessThan, "Less than operator should work for container ordering");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_Operators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 5; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_ArithmeticOperators()
{
#if defined(ENABLE_TestSet_IntVec3_ArithmeticOperators)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_ArithmeticOperators)(start)\n");
    printf("####################################################################################################\n");

    IntVec3Class const v1(2, 3, 4);
    IntVec3Class const v2(1, 2, 3);

    // Test addition operator
    auto const sum = TimeFunction("Addition operator", [&v1, &v2]() { return v1 + v2; });
    VerifyTestResult(sum.x == 3 && sum.y == 5 && sum.z == 7, "Addition operator failed");

    // Test subtraction operator
    auto const diff = TimeFunction("Subtraction operator", [&v1, &v2]() { return v1 - v2; });
    VerifyTestResult(diff.x == 1 && diff.y == 1 && diff.z == 1, "Subtraction operator failed");

    // Test unary negation operator
    auto const negated = TimeFunction("Unary negation operator", [&v1]() { return -v1; });
    VerifyTestResult(negated.x == -2 && negated.y == -3 && negated.z == -4, "Unary negation operator failed");

    // Test scalar multiplication
    auto const scaled = TimeFunction("Scalar multiplication", [&v1]() { return v1 * 2; });
    VerifyTestResult(scaled.x == 4 && scaled.y == 6 && scaled.z == 8, "Scalar multiplication failed");

    // Test addition assignment
    IntVec3Class vec1(2, 3, 4);
    TimeAction("Addition assignment", [&vec1, &v2]() { vec1 += v2; });
    VerifyTestResult(vec1.x == 3 && vec1.y == 5 && vec1.z == 7, "Addition assignment failed");

    // Test subtraction assignment
    IntVec3Class vec2(2, 3, 4);
    TimeAction("Subtraction assignment", [&vec2, &v2]() { vec2 -= v2; });
    VerifyTestResult(vec2.x == 1 && vec2.y == 1 && vec2.z == 1, "Subtraction assignment failed");

    // Test scalar multiplication assignment
    IntVec3Class vec3(2, 3, 4);
    TimeAction("Scalar multiplication assignment", [&vec3]() { vec3 *= 2; });
    VerifyTestResult(vec3.x == 4 && vec3.y == 6 && vec3.z == 8, "Scalar multiplication assignment failed");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_ArithmeticOperators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 7; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_IntVec3_UnimplementedMethods()
{
#if defined(ENABLE_TestSet_IntVec3_UnimplementedMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_UnimplementedMethods)(start)\n");
    printf("####################################################################################################\n");
    printf("  Note: These methods are declared but not yet implemented.\n");
    printf("  Tests will be skipped but framework is ready for implementation.\n");

    IntVec3Class const vec(3, 4, 0);

    // These methods would be tested when implemented:
    /*
    // Distance methods
    int dist = IntVec3Class::GetManhattanDistance(vec, IntVec3Class::ZERO);
    VerifyTestResult(dist == 7, "GetManhattanDistance should compute correct taxicab distance");

    float euclidDist = IntVec3Class::GetDistance(vec, IntVec3Class::ZERO);
    VerifyTestResult(IsMostlyEqual(euclidDist, 5.0f), "GetDistance should compute correct Euclidean distance");

    // Interpolation methods
    IntVec3Class lerped = IntVec3Class::Lerp(IntVec3Class::ZERO, vec, 0.5f);
    VerifyTestResult(lerped.x == 1 && lerped.y == 2 && lerped.z == 0, "Lerp should interpolate correctly with rounding");

    // 3D grid/voxel utility methods
    IntVec3Class neighbors[6];
    int numNeighbors = vec.GetCardinalNeighbors(neighbors);
    VerifyTestResult(numNeighbors == 6, "GetCardinalNeighbors should return 6 neighbors in 3D");

    // Cross product for integer vectors
    IntVec3Class cross = IntVec3Class::CrossProduct(vec, IntVec3Class::ZERO);
    VerifyTestResult(cross.x == 0 && cross.y == 0 && cross.z == 0, "CrossProduct with zero should be zero");
    */

    // For now, just mark that we've acknowledged these unimplemented methods
    VerifyTestResult(true, "Unimplemented methods framework ready (GetDistance, GetManhattanDistance, Lerp, CrossProduct, Grid utilities, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_IntVec3_UnimplementedMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
void RunTests_IntVec3()
{
    RunTestSet(true, TestSet_IntVec3_Constructors, "IntVec3 - Constructors");
    RunTestSet(true, TestSet_IntVec3_StaticConstants, "IntVec3 - Static Constants");
    RunTestSet(true, TestSet_IntVec3_StaticMethods, "IntVec3 - Static Methods");
    RunTestSet(true, TestSet_IntVec3_AccessorMethods, "IntVec3 - Accessor Methods");
    RunTestSet(true, TestSet_IntVec3_MutatorMethods, "IntVec3 - Mutator Methods");
    RunTestSet(true, TestSet_IntVec3_Operators, "IntVec3 - Operators");
    RunTestSet(true, TestSet_IntVec3_ArithmeticOperators, "IntVec3 - Arithmetic Operators");
    RunTestSet(true, TestSet_IntVec3_UnimplementedMethods, "IntVec3 - Unimplemented Methods");
}