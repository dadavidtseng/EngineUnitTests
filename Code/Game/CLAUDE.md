[Root Directory](../../CLAUDE.md) > [Code](../) > **Game**

# Game Module Documentation

## Changelog

### 2025-09-23 23:46:27
- Initial module documentation created
- Comprehensive test file inventory and analysis
- Performance testing framework documented

---

## Module Responsibilities

The Game module serves as the primary unit testing suite for the game engine, containing:

- **Unit Test Framework Implementation**: Core testing infrastructure with grading capabilities
- **Mathematical Component Tests**: Comprehensive testing for Vec2, AABB2, and related math classes
- **Performance Benchmarking**: High-precision performance measurements for critical engine operations
- **Assignment Validation**: Structured test sets for SMU Guildhall coursework (MP1-A1 through MP2-A2)

## Entry and Startup

### Main Entry Point
- **File**: `Main.cpp`
- **Function**: `main()` - Orchestrates test execution and reporting
- **Key Components**:
  - `RunTestSets()` - Central test dispatcher
  - Global test tracking variables for graded/non-graded results
  - Automatic grade calculation and reporting

### Test Runner Infrastructure
- **Global Functions**: `RunTestSet()`, `VerifyTestResult()`
- **Test Framework**: Custom implementation with academic grading features
- **Result Tracking**: Comprehensive statistics for passed, failed, and skipped tests

## External Interfaces

### Engine Dependencies
```cpp
// Engine math components (external dependency)
#include "Engine/Math/Vec2.hpp"
#include "Engine/Math/AABB2.hpp" 
// ... other engine components
```

### Test Set Interface Pattern
```cpp
// Each test file exposes:
void RunTests_[TestName]();     // Main test runner
int TestSet_[Specific]();       // Individual test sets
```

### Configuration Interface
```cpp
// Enable/disable controls in headers:
#define ENABLE_TestSet_[Name]   // Uncomment to enable test set
```

## Key Dependencies and Configuration

### Build Configuration
- **Project File**: `Game.vcxproj`
- **Target Platform**: Windows (Win32/x64)
- **C++ Standard**: C++17
- **Toolset**: Visual Studio v143 (2022)

### External Dependencies
- **Engine Project**: `../../../Engine/Code/Engine/Engine.vcxproj`
- **Include Paths**: 
  - `$(SolutionDir)Code/` (local)
  - `$(SolutionDir)../Engine/Code/` (external engine)

### Build Preferences
- **File**: `EngineBuildPreferences.hpp`
- **Configurations**:
  - `ENGINE_DISABLE_AUDIO` - Disables audio system for testing
  - `ENGINE_DEBUG_RENDER` - Enables debug rendering features

### Common Utilities
- **File**: `GameCommon.hpp`
- **Provides**: 
  - `TestSetFunctionType` typedef
  - Global test framework function declarations
  - Shared testing infrastructure

## Data Models

### Test Result Tracking
```cpp
// Global test statistics (from Main.cpp)
int g_numTotalTestsPassed;      // All tests passed
int g_numTotalTestsFailed;      // All tests failed
int g_numTotalTestsExpected;    // Expected test count
int g_numTotalTestsSkipped;     // Tests not run

// Separate tracking for graded vs non-graded tests
int g_numGradedTestsPassed;     // Assignment-relevant tests
int g_numNonGradedTestsPassed;  // Additional/practice tests
```

### Performance Measurement Framework
```cpp
// Performance timing utilities (UnitTests_AABB2_Performance.hpp)
struct PerformanceTimer {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    
    void Start();
    void Stop(); 
    double GetElapsedMilliseconds();
    double GetElapsedMicroseconds();
};
```

### Test Configuration Constants
```cpp
#define PERFORMANCE_TEST_ITERATIONS 1000000    // Main test iterations
#define PERFORMANCE_WARMUP_ITERATIONS 10000    // Warmup runs
```

## Testing and Quality

### Unit Test Structure

#### Math Library Tests (MP1 Series)
- **MP1-A1**: Vec2 construction, operators, comparison
- **MP1-A2**: Vec2 advanced operations and methods
- **MP1-A3**: AABB2 construction and basic operations
- **MP1-A4**: AABB2 advanced operations and collision detection
- **MP1-A7**: Extended math operations and edge cases

#### Advanced Tests (MP2 Series)
- **MP2-A1**: Complex mathematical relationships and transformations
- **MP2-A2**: Advanced collision detection and spatial operations

#### Custom Test Framework
- **File**: `UnitTests_Custom.cpp/hpp`
- **Purpose**: User-defined test cases and experiments
- **Integration**: Follows same pattern as standard test sets

### Performance Testing

#### AABB2 Performance Benchmarks
- **Construction Performance**: Timing various AABB2 construction methods
- **Basic Operations**: Performance of fundamental AABB2 operations
- **Point Queries**: Efficiency of point-in-box and related queries

#### Image Performance Tests
- **File**: `UnitTests_Image_Performance.hpp` (header-only configuration)
- **Purpose**: Performance testing for image processing operations

### Quality Assurance Features

#### Test Validation
- **Expected Count Verification**: Ensures test sets report correct expected test counts
- **Error Detection**: Identifies mismatched expected vs actual test execution
- **Integrity Checking**: Validates test framework consistency

#### Academic Compliance
- **Grading Integration**: Automatic grade calculation (100 - 2 points per failed test)
- **Submission Validation**: All test sets must be enabled for assignments
- **Cheating Prevention**: Explicit warnings against modifying protected code sections

## FAQ

### Q: How do I add a new test set?
A: Create new header/source pair following existing patterns, add includes to Main.cpp, and call from RunTestSets().

### Q: Can I modify existing test files?
A: No, test files contain protected sections marked "DO NOT MODIFY" - these are provided by instructors.

### Q: How do I temporarily disable a test set?
A: Comment out the corresponding `#define ENABLE_TestSet_*` in the test header file.

### Q: What if my engine classes have different names?
A: Update the `#define` mappings in test headers (e.g., `#define Vector2Class Vec2`).

### Q: How do performance tests work?
A: They use high-resolution timers with warmup iterations to provide accurate microsecond-level measurements.

### Q: Why are some tests graded and others not?
A: Graded tests directly relate to assignment requirements; non-graded tests are supplementary or practice-oriented.

## Related File List

### Core Framework Files
- `Main.cpp` - Test runner entry point and framework implementation
- `GameCommon.hpp` - Shared utilities and type definitions
- `EngineBuildPreferences.hpp` - Engine build configuration

### Unit Test Files (MP1 Series)
- `UnitTests_MP1A1.hpp/.cpp` - Vec2 basic operations
- `UnitTests_MP1A2.hpp/.cpp` - Vec2 advanced operations  
- `UnitTests_MP1A3.hpp/.cpp` - AABB2 basic operations
- `UnitTests_MP1A4.hpp/.cpp` - AABB2 advanced operations
- `UnitTests_MP1A7.hpp/.cpp` - Extended math operations

### Unit Test Files (MP2 Series)
- `UnitTests_MP2A1.hpp/.cpp` - Advanced mathematical relationships
- `UnitTests_MP2A2.hpp/.cpp` - Complex spatial operations

### Custom and Performance Tests
- `UnitTests_Custom.hpp/.cpp` - User-defined test cases
- `UnitTests_AABB2_Performance.hpp/.cpp` - AABB2 performance benchmarks
- `UnitTests_Image_Performance.hpp` - Image processing performance configuration

### Build Files
- `Game.vcxproj` - Visual Studio project configuration
- `Game.vcxproj.filters` - Project file organization
- `Game.vcxproj.user` - User-specific project settings

---

**Module Type**: Unit Testing Framework  
**Primary Language**: C++17  
**Test Categories**: Math Library, Performance Benchmarks  
**Build Integration**: Visual Studio MSBuild