cmake_minimum_required(VERSION 3.10)

project(StaticArrays)

add_library(StaticArrays INTERFACE
)

target_include_directories(StaticArrays INTERFACE include)

option(ENABLE_TESTING "Enable Testing" ON)
if(${ENABLE_TESTING})
        include(FetchContent)
        FetchContent_Declare(
          googletest
          URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        )
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
        enable_testing()

        add_executable(test_staticarrays
                        test/test_staticarrays.cpp
        )

        target_link_libraries(test_staticarrays PRIVATE StaticArrays gtest gtest_main)

        include(GoogleTest)
        gtest_discover_tests(test_staticarrays)
endif()