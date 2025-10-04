cmake_minimum_required(VERSION 3.10.0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 1.0.${PATCH_VERSION})

project(lab2 VERSION ${PROJECT_VERSION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)


add_executable(lab2 main.cpp)
add_library(lib ip_filter.cpp)
add_executable(test_func test.cpp)



target_compile_features(lab2 PRIVATE cxx_std_20)
target_compile_features(lib PRIVATE cxx_std_20)
target_compile_features(test_func PRIVATE cxx_std_20)

target_include_directories(lib 
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(test_func PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(lab2 PRIVATE
    lib
)
target_link_libraries(test_func 
    ${Boost_LIBRARIES}
    lib
)

if (MSVC)
    target_compile_options(lab2 PRIVATE
        /W4
    )
    target_compile_options(lib PRIVATE
        /W4
    )
    target_compile_options(test_func PRIVATE
        /W4
    )
else ()
    target_compile_options(lab2 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_func PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS lab2 RUNTIME DESTINATION bin)

if(UNIX)
    set(CPACK_GENERATOR "DEB")
else ()
    set(CPACK_GENERATOR "ZIP")
endif()


set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_func test_func)


