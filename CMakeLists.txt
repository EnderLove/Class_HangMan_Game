cmake_minimum_required(VERSION 3.15)

project(HangmanGame LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Gather all source files and headers explicitly
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS includes/*.h)
file(GLOB RESOURCE_FILES resources/*)

# Combine all source-related files so they appear in Visual Studio
set(ALL_FILES ${SOURCES} ${HEADERS} ${RESOURCE_FILES})

add_executable(${PROJECT_NAME} ${ALL_FILES})

# Include headers directory for compilation
target_include_directories(${PROJECT_NAME} PRIVATE includes)

# Copy each resource file to build output directory after build
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_FILE}
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endforeach()

# Optional: Organize files into Visual Studio folders (for clarity)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "Source Files" FILES ${SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/includes PREFIX "Header Files" FILES ${HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/resources PREFIX "Resource Files" FILES ${RESOURCE_FILES})

message(STATUS "Source files: ${SOURCES}")
message(STATUS "Header files: ${HEADERS}")
message(STATUS "Resource files: ${RESOURCE_FILES}")
