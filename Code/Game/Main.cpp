//----------------------------------------------------------------------------------------------------
// Main.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include <algorithm>
#include <cstdio>

#include "Game/GameCommon.hpp"
#include "Game/UnitTests_AABB2.hpp"
#include "Game/UnitTests_InputSystem.hpp"
#include "Game/UnitTests_Vec2.hpp"

//----------------------------------------------------------------------------------------------------
void RunTestSets()
{
    RunTests_AABB2();
    RunTests_Vec2();
    RunTests_InputSystem();
}

//-----------------------------------------------------------------------------------------------
// Global variables for test result tracking
//
int g_numTotalTestsPassed   = 0;
int g_numTotalTestsFailed   = 0;
int g_numTotalTestsExpected = 0;
int g_numTotalTestsSkipped  = 0;

int g_numGradedTestsPassed   = 0;
int g_numGradedTestsFailed   = 0;
int g_numGradedTestsExpected = 0;
int g_numGradedTestsSkipped  = 0;

int g_numNonGradedTestsPassed   = 0;
int g_numNonGradedTestsFailed   = 0;
int g_numNonGradedTestsExpected = 0;
int g_numNonGradedTestsSkipped  = 0;

//-----------------------------------------------------------------------------------------------
void VerifyTestResult(bool const  bIsCorrect,
                      char const* testName)
{
    if (bIsCorrect)
    {
        ++g_numTotalTestsPassed;
    }
    else
    {
        ++g_numTotalTestsFailed;
        printf("TEST FAILED: %s\n", testName);
    }
}

//-----------------------------------------------------------------------------------------------
void RunTestSet(bool const                 bIsGraded,
                TestSetFunctionType* const testSetFunction,
                char const*                testSetName)
{
    printf("\n");

    char const* gradedText = bIsGraded ? "graded" : "non-graded";
    printf("Running %s test set \"%s\"... \n", gradedText, testSetName);

    int const numTestsPassedBefore = g_numTotalTestsPassed;
    int const numTestsFailedBefore = g_numTotalTestsFailed;

    // RUN THE ACTUAL TEST SET; tests modify g_numTotalTestsPassed & Failed directly
    int const numTestsExpected = testSetFunction();

    int const numTestsJustPassed  = g_numTotalTestsPassed - numTestsPassedBefore;
    int const numTestsJustFailed  = g_numTotalTestsFailed - numTestsFailedBefore;
    int const numTestsJustTried   = numTestsJustPassed + numTestsJustFailed;
    int       numTestsJustSkipped = numTestsExpected - numTestsJustTried;

    // Check for error in test set reporting (expected vs. attempted # of tests, etc.)
    bool bWasError = false;
    if (numTestsJustSkipped < 0)
    {
        bWasError           = true;
        numTestsJustSkipped = 0;
    }
    else if (numTestsJustTried > 0 && numTestsJustTried != numTestsExpected)
    {
        bWasError = true;
    }

    if (bWasError)
    {
        printf("\n\n");
        printf("########################################################################################\n");
        printf("ERROR: Test set \"%s\"\n", testSetName);
        printf("  said it expected %i test(s), but it actually ran %i test(s)!\n", numTestsExpected, numTestsJustTried);
        printf("  Please change the return value for that test set function from %i to %i.\n", numTestsExpected,
               numTestsJustTried);
        printf("########################################################################################\n");
    }

    // Update global test stats based on this test set's results
    g_numTotalTestsSkipped += numTestsJustSkipped;
    if (bIsGraded)
    {
        g_numGradedTestsExpected += numTestsExpected;
        g_numGradedTestsPassed += numTestsJustPassed;
        g_numGradedTestsFailed += numTestsJustFailed;
        g_numGradedTestsSkipped += numTestsJustSkipped;
    }
    else
    {
        g_numNonGradedTestsExpected += numTestsExpected;
        g_numNonGradedTestsPassed += numTestsJustPassed;
        g_numNonGradedTestsFailed += numTestsJustFailed;
        g_numNonGradedTestsSkipped += numTestsJustSkipped;
    }

    // Report test set summary; for actual failures, skip this part, since each failure prints its own message
    if (numTestsExpected == 0)
    {
        printf("(0 tests)");
    }
    else if (numTestsJustSkipped > 0)
    {
        printf("test set DISABLED; %i tests SKIPPED", numTestsJustSkipped);
    }
    else if (numTestsJustFailed == 0)
    {
        printf("all %i tests passed", numTestsJustPassed);
    }

    printf("\n");
}

//-----------------------------------------------------------------------------------------------
int main(int, char**)
{
    // Run test sets
    printf("Welcome to EngineUnitTests!\n");
    printf("This project aims to perform unit tests on Damon Engine's C++ and JavaScript.\n\n");

    RunTestSets();

    // Report results
    int const pointsOffPerIncorrectTest = 2;
    int const numGradedIncorrect        = g_numGradedTestsFailed + g_numGradedTestsSkipped;
    int const assignmentGradePenalty    = pointsOffPerIncorrectTest * numGradedIncorrect;
    int       assignmentGrade           = 100 - assignmentGradePenalty;

    assignmentGrade = std::max(assignmentGrade, 0);

    printf("\n");
    printf("========================================================================================\n");
    printf("  Number of GRADED tests passed: %i of %i (%i failed, %i skipped)\n", g_numGradedTestsPassed,
           g_numGradedTestsExpected, g_numGradedTestsFailed, g_numGradedTestsSkipped);
    printf("  Number of non-graded tests passed: %i of %i (%i failed, %i skipped)\n", g_numNonGradedTestsPassed,
           g_numNonGradedTestsExpected, g_numNonGradedTestsFailed, g_numNonGradedTestsSkipped);
    printf("\n");
    printf("  Assignment grade is calculated as: 100 minus %i point(s) per incorrect graded test.\n",
           pointsOffPerIncorrectTest);
    printf("\n");
    printf("  Grade for assignment: 100 - (%i incorrect x %i-point penalty each) = %i%%\n", numGradedIncorrect,
           pointsOffPerIncorrectTest, assignmentGrade);
    printf("========================================================================================\n");
    printf("\n");

    system("pause");    // block and wait for keypress

    return 0;
}
