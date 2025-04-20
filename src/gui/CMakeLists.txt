# src/gui/CMakeLists.txt

file(GLOB GUI_SRC CONFIGURE_DEPENDS
    *.cpp
    *.h
)

file(GLOB QT_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)    #获取ui文件

QT5_WRAP_UI(QT_FORMS_H ${QT_FORMS})



#qt5_add_resources(qrc_files ${CMAKE_CURRENT_SOURCE_DIR}/Resource.qrc)

list(GET QT_FORMS_H 0 FIRST_ELEMENT)
get_filename_component(VAR ${FIRST_ELEMENT} DIRECTORY)

include_directories(${VAR})

message(${VAR})

add_library(GUI ${GUI_SRC} ${QT_FORMS_H} )#${qrc_files}

target_include_directories(GUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../scene)
target_link_libraries(GUI Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL SCENE)
target_include_directories(GUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})