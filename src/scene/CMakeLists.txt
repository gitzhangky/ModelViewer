# src/scene/CMakeLists.txt

file(GLOB SCENE_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_library(SCENE ${SCENE_SRC})

target_link_libraries(SCENE OpenThreads osg osgDB osgFX osgGA osgText osgUtil osgViewer IO)
target_include_directories(SCENE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SCENE PRIVATE ${CMAKE_SOURCE_DIR}/src/io)