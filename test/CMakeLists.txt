enable_testing()

# Download and unpack googletest at configure time

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# Hide Google Test variables
mark_as_advanced(FORCE BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
gmock_build_tests gtest_build_samples gtest_build_tests
gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols)

 # The gtest/gtest_main targets carry header search path
 # dependencies automatically when using CMake 2.8.11 or
 # later. Otherwise we have to add them here ourselves.
 if (CMAKE_VERSION VERSION_LESS 2.8.11)
   include_directories("${gtest_SOURCE_DIR}/include")
   include_directories("${gmock_SOURCE_DIR}/include")
 endif()

set(UNIT_TESTS_SOURCES
  drawing/CanvasTest.cpp
  drawing/LineTest.cpp
  drawing/PointTransformTest.cpp
  drawing/RangeTest.cpp
  expression/EvaluateTest.cpp
  expression/ExpressionBuilderTest.cpp
  expression/ExpressionTest.cpp
  expression/ParserTest.cpp
  TestMain.cpp
)

set(UNIT_TESTS_HEADERS
  HelperFunctions.h
)

source_group("Source Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.cpp")
source_group("Source Files\\expression" REGULAR_EXPRESSION "expression/.*\\.cpp")
source_group("Header Files\\drawing" REGULAR_EXPRESSION "drawing/.*\\.h")
source_group("Header Files\\expression" REGULAR_EXPRESSION "expression/.*\\.h")

add_executable(UnitTest ${UNIT_TESTS_SOURCES} ${UNIT_TESTS_HEADERS})
target_include_directories(UnitTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(UnitTest FuncDrawLib gmock gtest)

add_test(unittest UnitTest)
