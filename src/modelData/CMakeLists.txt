# src/modelData/CMakeLists.txt

file(GLOB ModelData_SRC CONFIGURE_DEPENDS
    *.cpp
    *.h
)

add_library(ModelData ${ModelData_SRC})

target_include_directories(ModelData PRIVATE ${CMAKE_SOURCE_DIR}/include)