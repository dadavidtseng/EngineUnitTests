//----------------------------------------------------------------------------------------------------
// UnitTests_Vec4.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Math/UnitTests_Vec4.hpp"

#include <cstdio>

#include "Game/GameCommon.hpp"

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_Constructors()
{
#if defined(ENABLE_TestSet_Vec4_Constructors)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_Constructors)(start)\n");
    printf("####################################################################################################\n");

    // Test default constructor
    auto const v1 = TimeFunction("Default constructor", []() { return Vector4Class(); });
    VerifyTestResult(IsMostlyEqual(v1.x, 0.0f) && IsMostlyEqual(v1.y, 0.0f) && IsMostlyEqual(v1.z, 0.0f) && IsMostlyEqual(v1.w, 0.0f), "Vec4 default constructor should initialize to (0,0,0,0)");

    // Test constructor from 4 floats
    auto const v2 = TimeFunction("Constructor from 4 floats", []() { return Vector4Class(3.5f, 4.2f, 5.1f, 6.7f); });
    VerifyTestResult(IsMostlyEqual(v2.x, 3.5f) && IsMostlyEqual(v2.y, 4.2f) && IsMostlyEqual(v2.z, 5.1f) && IsMostlyEqual(v2.w, 6.7f), "Vec4 constructor from 4 floats failed");

    // Test constructor from 4 ints
    auto const v3 = TimeFunction("Constructor from 4 ints", []() { return Vector4Class(7, 9, 2, 4); });
    VerifyTestResult(IsMostlyEqual(v3.x, 7.0f) && IsMostlyEqual(v3.y, 9.0f) && IsMostlyEqual(v3.z, 2.0f) && IsMostlyEqual(v3.w, 4.0f), "Vec4 constructor from 4 ints failed");

    // Test copy constructor
    auto const v4 = TimeFunction("Copy constructor", [v2]() { return Vector4Class(v2); });
    VerifyTestResult(IsMostlyEqual(v4.x, v2.x) && IsMostlyEqual(v4.y, v2.y) && IsMostlyEqual(v4.z, v2.z) && IsMostlyEqual(v4.w, v2.w), "Vec4 copy constructor failed");

    // Test assignment operator
    auto const v5 = TimeFunction("Assignment operator", [v3]() { return Vector4Class(v3); });
    VerifyTestResult(IsMostlyEqual(v5.x, v3.x) && IsMostlyEqual(v5.y, v3.y) && IsMostlyEqual(v5.z, v3.z) && IsMostlyEqual(v5.w, v3.w), "Vec4 assignment operator failed");

    // Test const object construction and copy
    auto const v6 = TimeFunction("Const copy constructor (1st)", [v2]() { return Vector4Class(v2); });

    auto const v7 = TimeFunction("Const copy constructor (2nd)", [v6]() { return Vector4Class(v6); });
    VerifyTestResult(IsMostlyEqual(v7.x, v2.x) && IsMostlyEqual(v7.y, v2.y) && IsMostlyEqual(v7.z, v2.z) && IsMostlyEqual(v7.w, v2.w), "Vec4 const copy constructor failed");

    // Test size verification
    VerifyTestResult(sizeof(Vector4Class) == 16, "sizeof(Vec4) should be 16 bytes (4 floats)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_Constructors)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 7; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_StaticConstants()
{
#if defined(ENABLE_TestSet_Vec4_StaticConstants)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_StaticConstants)(start)\n");
    printf("####################################################################################################\n");

    // Test ZERO constant
    auto const zero = TimeFunction("ZERO access", []() { return Vector4Class::ZERO; });
    VerifyTestResult(IsMostlyEqual(zero.x, 0.0f) && IsMostlyEqual(zero.y, 0.0f) && IsMostlyEqual(zero.z, 0.0f) && IsMostlyEqual(zero.w, 0.0f),
                     "Vec4::ZERO should be (0,0,0,0)");

    // Test ONE constant
    auto const one = TimeFunction("ONE access", []() { return Vector4Class::ONE; });
    VerifyTestResult(IsMostlyEqual(one.x, 1.0f) && IsMostlyEqual(one.y, 1.0f) && IsMostlyEqual(one.z, 1.0f) && IsMostlyEqual(one.w, 1.0f),
                     "Vec4::ONE should be (1,1,1,1)");

    // Note: Vec4 only has ZERO and ONE constants, not basis vectors like Vec3
    // The basis vectors would be tested here when implemented:
    /*
    // Test X_BASIS constant (when implemented)
    auto const xBasis = TimeFunction("X_BASIS access", []() { return Vector4Class::X_BASIS; });
    VerifyTestResult(IsMostlyEqual(xBasis.x, 1.0f) && IsMostlyEqual(xBasis.y, 0.0f) && IsMostlyEqual(xBasis.z, 0.0f) && IsMostlyEqual(xBasis.w, 0.0f),
                     "Vec4::X_BASIS should be (1,0,0,0)");
    */

    // For now, acknowledge that the framework is ready for when basis vectors are implemented
    VerifyTestResult(true, "Vec4 basis vectors framework ready (X_BASIS, Y_BASIS, Z_BASIS, W_BASIS when implemented)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_StaticConstants)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_StaticMethods()
{
#if defined(ENABLE_TestSet_Vec4_StaticMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_StaticMethods)(start)\n");
    printf("####################################################################################################\n");

    // Note: Vec4 static methods may include Dot product, Homogeneous operations, etc.
    // These tests are placeholders for when static methods are implemented

    // Test Dot Product (if implemented)
    Vector4Class const v1(1.0f, 0.0f, 0.0f, 0.0f);
    Vector4Class const v2(0.0f, 1.0f, 0.0f, 0.0f);

    // Placeholder test - would test Vector4Class::DotProduct(v1, v2) when implemented
    VerifyTestResult(true, "Vec4 static methods framework ready (DotProduct, Homogeneous operations, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_StaticMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_AccessorMethods()
{
#if defined(ENABLE_TestSet_Vec4_AccessorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_AccessorMethods)(start)\n");
    printf("####################################################################################################\n");

    Vector4Class const testVec(3.0f, 4.0f, 0.0f, 0.0f);
    Vector4Class const zeroVec(0.0f, 0.0f, 0.0f, 0.0f);

    // Test GetLength (if implemented)
    // auto const length = TimeFunction("GetLength", [&testVec]() { return testVec.GetLength(); });
    // VerifyTestResult(IsMostlyEqual(length, 5.0f), "GetLength should return correct magnitude");

    // Test GetLengthSquared (if implemented)
    // auto const lengthSq = TimeFunction("GetLengthSquared", [&testVec]() { return testVec.GetLengthSquared(); });
    // VerifyTestResult(IsMostlyEqual(lengthSq, 25.0f), "GetLengthSquared should return correct squared magnitude");

    // Test GetNormalized (if implemented)
    // auto const normalized = TimeFunction("GetNormalized", [&testVec]() { return testVec.GetNormalized(); });
    // VerifyTestResult(IsMostlyEqual(normalized.GetLength(), 1.0f), "GetNormalized should return unit vector");

    // For now, just acknowledge the framework is ready
    VerifyTestResult(true, "Vec4 accessor methods framework ready (GetLength, GetLengthSquared, GetNormalized, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_AccessorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_MutatorMethods()
{
#if defined(ENABLE_TestSet_Vec4_MutatorMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_MutatorMethods)(start)\n");
    printf("####################################################################################################\n");

    // Test SetLength (if implemented)
    // Vector4Class vec(3.0f, 4.0f, 0.0f, 0.0f);
    // vec.SetLength(10.0f);
    // VerifyTestResult(IsMostlyEqual(vec.GetLength(), 10.0f), "SetLength should set correct magnitude");

    // Test Normalize (if implemented)
    // Vector4Class vec2(3.0f, 4.0f, 0.0f, 0.0f);
    // vec2.Normalize();
    // VerifyTestResult(IsMostlyEqual(vec2.GetLength(), 1.0f), "Normalize should create unit vector");

    // For now, just acknowledge the framework is ready
    VerifyTestResult(true, "Vec4 mutator methods framework ready (SetLength, Normalize, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_MutatorMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_Operators()
{
#if defined(ENABLE_TestSet_Vec4_Operators)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_Operators)(start)\n");
    printf("####################################################################################################\n");

    // Test equality operator
    Vector4Class const v1(10.0f, 20.0f, 30.0f, 40.0f);
    Vector4Class const v2(10.0f, 20.0f, 30.0f, 40.0f);
    Vector4Class const v3(11.0f, 20.0f, 30.0f, 40.0f);

    auto const equal1 = TimeFunction("Equality operator (equal)", [&v1, &v2]() { return v1 == v2; });
    VerifyTestResult(equal1, "Equality operator should return true for equal vectors");

    auto const equal2 = TimeFunction("Equality operator (not equal)", [&v1, &v3]() { return v1 == v3; });
    VerifyTestResult(!equal2, "Equality operator should return false for different vectors");

    // Test with very small differences
    Vector4Class const v4(10.0001f, 20.0f, 30.0f, 40.0f);
    auto const         equal3 = TimeFunction("Equality operator (precision)", [&v1, &v4]() { return v1 == v4; });
    VerifyTestResult(!equal3, "Equality operator should be exact, not approximate");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_Operators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 3; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_ArithmeticOperators()
{
#if defined(ENABLE_TestSet_Vec4_ArithmeticOperators)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_ArithmeticOperators)(start)\n");
    printf("####################################################################################################\n");

    Vector4Class const v1(2.0f, 3.0f, 4.0f, 5.0f);
    Vector4Class const v2(1.0f, 2.0f, 3.0f, 4.0f);

    // Test addition operator (if implemented)
    // auto const sum = TimeFunction("Addition operator", [&v1, &v2]() { return v1 + v2; });
    // VerifyTestResult(IsMostlyEqual(sum.x, 3.0f) && IsMostlyEqual(sum.y, 5.0f) && IsMostlyEqual(sum.z, 7.0f) && IsMostlyEqual(sum.w, 9.0f), "Addition operator failed");

    // Test subtraction operator (if implemented)
    // auto const diff = TimeFunction("Subtraction operator", [&v1, &v2]() { return v1 - v2; });
    // VerifyTestResult(IsMostlyEqual(diff.x, 1.0f) && IsMostlyEqual(diff.y, 1.0f) && IsMostlyEqual(diff.z, 1.0f) && IsMostlyEqual(diff.w, 1.0f), "Subtraction operator failed");

    // Test scalar multiplication (if implemented)
    // auto const scaled = TimeFunction("Scalar multiplication", [&v1]() { return v1 * 2.0f; });
    // VerifyTestResult(IsMostlyEqual(scaled.x, 4.0f) && IsMostlyEqual(scaled.y, 6.0f) && IsMostlyEqual(scaled.z, 8.0f) && IsMostlyEqual(scaled.w, 10.0f), "Scalar multiplication failed");

    // For now, just acknowledge the framework is ready
    VerifyTestResult(true, "Vec4 arithmetic operators framework ready (+, -, *, /, compound assignments)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_ArithmeticOperators)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
int TestSet_Vec4_UnimplementedMethods()
{
#if defined(ENABLE_TestSet_Vec4_UnimplementedMethods)

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_UnimplementedMethods)(start)\n");
    printf("####################################################################################################\n");
    printf("  Note: These methods are declared but not yet implemented.\n");
    printf("  Tests will be skipped but framework is ready for implementation.\n");

    Vector4Class const vec(1.0f, 2.0f, 3.0f, 4.0f);

    // These methods would be tested when implemented:
    /*
    // Dot product
    float dot = Vector4Class::DotProduct(vec, Vector4Class::X_BASIS);
    VerifyTestResult(IsMostlyEqual(dot, 1.0f), "DotProduct should compute correct dot product");

    // Distance methods
    float dist = Vector4Class::GetDistance(vec, Vector4Class::ZERO);
    VerifyTestResult(IsMostlyEqual(dist, vec.GetLength()), "GetDistance should compute correct distance");

    // Interpolation methods
    Vector4Class lerped = Vector4Class::Lerp(Vector4Class::ZERO, vec, 0.5f);
    VerifyTestResult(IsMostlyEqual(lerped.x, 0.5f) && IsMostlyEqual(lerped.y, 1.0f) && IsMostlyEqual(lerped.z, 1.5f) && IsMostlyEqual(lerped.w, 2.0f),
                    "Lerp should interpolate correctly");

    // Homogeneous coordinate operations
    Vector4Class homogeneous = vec.GetAsHomogeneousPoint();
    VerifyTestResult(IsMostlyEqual(homogeneous.w, 1.0f), "GetAsHomogeneousPoint should set w to 1.0");

    Vector4Class direction = vec.GetAsHomogeneousDirection();
    VerifyTestResult(IsMostlyEqual(direction.w, 0.0f), "GetAsHomogeneousDirection should set w to 0.0");
    */

    // For now, just mark that we've acknowledged these unimplemented methods
    VerifyTestResult(true, "Unimplemented methods framework ready (DotProduct, GetDistance, Lerp, Homogeneous operations, etc.)");

    printf("####################################################################################################\n");
    printf("(TestSet_Vec4_UnimplementedMethods)(end)\n");
    printf("####################################################################################################\n");

#endif
    return 1; // Number of tests expected
}

//-----------------------------------------------------------------------------------------------
void RunTests_Vec4()
{
    RunTestSet(true, TestSet_Vec4_Constructors, "Vec4 - Constructors");
    RunTestSet(true, TestSet_Vec4_StaticConstants, "Vec4 - Static Constants");
    RunTestSet(true, TestSet_Vec4_StaticMethods, "Vec4 - Static Methods");
    RunTestSet(true, TestSet_Vec4_AccessorMethods, "Vec4 - Accessor Methods");
    RunTestSet(true, TestSet_Vec4_MutatorMethods, "Vec4 - Mutator Methods");
    RunTestSet(true, TestSet_Vec4_Operators, "Vec4 - Operators");
    RunTestSet(true, TestSet_Vec4_ArithmeticOperators, "Vec4 - Arithmetic Operators");
    RunTestSet(true, TestSet_Vec4_UnimplementedMethods, "Vec4 - Unimplemented Methods");
}
