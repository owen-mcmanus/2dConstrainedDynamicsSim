cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName physics-sim)
set(ProjectNamespace "physics_sim")

project("${ProjectName}")

set(CMAKE_CXX_STANDARD 11)

# =========================================================
# gtest

include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_property(TARGET gmock PROPERTY FOLDER "gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "gtest")
set_property(TARGET gtest PROPERTY FOLDER "gtest")
set_property(TARGET gtest_main PROPERTY FOLDER "gtest")

# =========================================================

add_library("${ProjectName}" STATIC
    # Source files
    src/information.cpp

    # Header files
    include/information.h
 "include/state.h" "src/state.cpp" "include/flat_vector.h" "src/flat_vector.cpp" "include/force_generator.h" "src/force_generator.cpp" "include/rigidbody.h" "src/rigidbody.cpp" "include/gravity_fg.h" "src/gravity_fg.cpp" "include/euler_solver.h" "src/euler_solver.cpp" "include/single_rigidbody.h" "src/single_rigidbody.cpp" "src/double_rigidbody.cpp" "include/double_rigidbody.h" "src/spring_fg.cpp" "include/spring_fg.h" "src/runge_kutta_solver.cpp" "include/runge_kutta_solver.h" "src/data_logger.cpp" "include/data_logger.h")

target_compile_definitions("${ProjectName}" PRIVATE PROJECT_NAMESPACE=${ProjectNamespace})

add_executable("${ProjectName}-main"
    # Source files
    src/main.cpp

    # Header files
 "include/state.h" "src/state.cpp" "include/flat_vector.h" "src/flat_vector.cpp" "include/force_generator.h" "src/force_generator.cpp" "include/rigidbody.h" "src/rigidbody.cpp" "include/gravity_fg.h" "src/gravity_fg.cpp" "include/euler_solver.h" "src/euler_solver.cpp" "include/single_rigidbody.h" "src/single_rigidbody.cpp" "src/double_rigidbody.cpp" "include/double_rigidbody.h" "src/spring_fg.cpp" "include/spring_fg.h" "src/runge_kutta_solver.cpp" "include/runge_kutta_solver.h" "src/data_logger.cpp" "include/data_logger.h")

# gtest

enable_testing()

add_executable("${ProjectName}-test"
    # Source files
    test/sanity_test.cpp

    # Head files
 "include/state.h" "src/state.cpp" "include/flat_vector.h" "src/flat_vector.cpp" "include/force_generator.h" "src/force_generator.cpp" "include/rigidbody.h" "src/rigidbody.cpp" "include/gravity_fg.h" "src/gravity_fg.cpp" "include/euler_solver.h" "src/euler_solver.cpp" "include/single_rigidbody.h" "src/single_rigidbody.cpp" "src/double_rigidbody.cpp" "include/double_rigidbody.h" "src/spring_fg.cpp" "include/spring_fg.h" "src/runge_kutta_solver.cpp" "include/runge_kutta_solver.h" "src/data_logger.cpp" "include/data_logger.h")

target_link_libraries("${ProjectName}-test"
    gtest_main
    "${ProjectName}"
)

include(GoogleTest)
gtest_discover_tests("${ProjectName}-test")
