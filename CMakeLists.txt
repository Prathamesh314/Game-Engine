cmake_minimum_required(VERSION 3.15)

project(Hazel VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# macOS-specific: Enable position independent code
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Configure output directories
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
set(INTERMEDIATE_DIR ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${INTERMEDIATE_DIR})

###########################################
# Hazel Engine (Shared Library)
###########################################

add_library(Hazel SHARED
    Hazel/src/Hazel.h
    Hazel/src/Hazel.cpp
)

# Define HAZEL_BUILD_DLL when building the Hazel library
target_compile_definitions(Hazel PRIVATE HAZEL_BUILD_DLL)

# Set visibility for exported symbols on macOS
set_target_properties(Hazel PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    OUTPUT_NAME "Hazel"
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/Hazel
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/Hazel
    ARCHIVE_OUTPUT_DIRECTORY ${INTERMEDIATE_DIR}/Hazel
)

# macOS-specific: Set install name for the dylib
set_target_properties(Hazel PROPERTIES
    INSTALL_NAME_DIR "@rpath"
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "@loader_path"
)

target_include_directories(Hazel PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Hazel/src
)

###########################################
# Sandbox Application (Executable)
###########################################

add_executable(Sandbox
    Sandbox/src/Application.cpp
)

# Link Sandbox against Hazel
target_link_libraries(Sandbox PRIVATE Hazel)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/Sandbox
    ARCHIVE_OUTPUT_DIRECTORY ${INTERMEDIATE_DIR}/Sandbox
)

# macOS-specific: Set rpath for finding the dylib at runtime
set_target_properties(Sandbox PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "@loader_path/../Hazel"
)

###########################################
# Post-build: Copy dylib to Sandbox directory
###########################################

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Hazel>
        $<TARGET_FILE_DIR:Sandbox>
    COMMENT "Copying libHazel.dylib to Sandbox output directory"
)

###########################################
# Configuration-specific settings
###########################################

target_compile_definitions(Hazel PUBLIC 
    $<$<CONFIG:Debug>:HZ_DEBUG>
    $<$<CONFIG:Release>:HZ_RELEASE>
)

target_compile_definitions(Sandbox PUBLIC 
    $<$<CONFIG:Debug>:HZ_DEBUG>
    $<$<CONFIG:Release>:HZ_RELEASE>
)

# Optimization flags for Release
if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(Hazel PRIVATE -O3)
    target_compile_options(Sandbox PRIVATE -O3)
endif()

# Debug flags
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(Hazel PRIVATE -g -O0)
    target_compile_options(Sandbox PRIVATE -g -O0)
endif()