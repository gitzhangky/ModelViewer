# src/io/CMakeLists.txt

file(GLOB IO_SRC CONFIGURE_DEPENDS
    *.cpp
    *.h
)


add_library(IO ${IO_SRC})

target_link_libraries(IO assimp-vc143-mt ModelData)
target_include_directories(IO PRIVATE ${PROJECT_SOURCE_DIR}/external/Assimp/include)
target_include_directories(IO PRIVATE ${PROJECT_SOURCE_DIR}/modelData)