cmake_minimum_required(VERSION 3.5)
project(ModelViewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# 查找 Osg
find_package(Osg REQUIRED)


# 查找 Assimp
find_package(Assimp REQUIRED)


# 查找 Qt
find_package(Qt5 5.13.2 REQUIRED COMPONENTS Core Widgets Gui OpenGL)
# 包含子目录

add_subdirectory(${CMAKE_SOURCE_DIR}/src/gui)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/scene)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/io)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/modelData)

#debug后缀带d
set_target_properties(GUI PROPERTIES CMAKE_DEBUG_POSTFIX "d")
set_target_properties(SCENE PROPERTIES CMAKE_DEBUG_POSTFIX "d")
set_target_properties(IO PROPERTIES CMAKE_DEBUG_POSTFIX "d")
set_target_properties(ModelData PROPERTIES CMAKE_DEBUG_POSTFIX "d")

# 收集入口源文件（main.cpp）
set(MAIN_SOURCES
    main.cpp
)

# 可执行文件
add_executable(ModelViewer WIN32 ${MAIN_SOURCES})


target_include_directories(ModelViewer PUBLIC  ${CMAKE_SOURCE_DIR})
target_include_directories(ModelViewer PUBLIC  ${CMAKE_SOURCE_DIR}/src/gui)
target_include_directories(ModelViewer PUBLIC  ${CMAKE_SOURCE_DIR}/src/scene)
target_include_directories(ModelViewer PUBLIC  ${CMAKE_SOURCE_DIR}/src/io)
target_include_directories(ModelViewer PUBLIC  ${CMAKE_SOURCE_DIR}/src/modelData)

target_link_libraries(ModelViewer GUI SCENE IO ModelData)



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

