#-----------------------------------------------------------------------------
# 引入Render基础模块
#-----------------------------------------------------------------------------

#防止重复引入
if(OSG_ALREADY_INCLUDED)
	return()
endif()
set(OSG_ALREADY_INCLUDED 1)

if(WIN32)
	#设置路径
	get_filename_component(OSG_Dir "${CMAKE_SOURCE_DIR}/external/OpenSceneGraph/" ABSOLUTE)

	message(${OSG_Dir})
	set(OSG_INC_DIR "${OSG_Dir}/include")
	set(OSG_LIB_DUBUG_DIR "${OSG_Dir}/lib/")
	set(OSG_BIN_DUBUG_DIR "${OSG_Dir}/bin/")
	set(OSG_LIB_RELEASE_DIR "${OSG_Dir}/lib")
	set(OSG_BIN_RELEASE_DIR "${OSG_Dir}/bin")
	set(OSG_TEMP_LIB_DIR "${OSG_Dir}/lib")
	set(OSG_TEMP_BIN_DIR "${OSG_Dir}/bin")
	list(APPEND OSGLibs OpenThreads osg osgDB osgFX osgGA osgText osgUtil osgViewer)

	foreach(_library ${OSGLibs})
		add_library(${_library} SHARED IMPORTED)
		set_property(TARGET ${_library} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OSG_INC_DIR})
		set_property(TARGET ${_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
		set_target_properties(${_library} PROPERTIES
		IMPORTED_IMPLIB_RELEASE "${OSG_TEMP_LIB_DIR}/${_library}.lib"
		IMPORTED_LOCATION_RELEASE "${OSG_BIN_RELEASE_DIR}/${_library}.dll"
		IMPORTED_IMPLIB_DEBUG "${OSG_TEMP_LIB_DIR}/${_library}d.lib"
		IMPORTED_LOCATION_DEBUG "${OSG_BIN_DUBUG_DIR}/${_library}d.dll"
		)
	endforeach()
else()

#	find_package(OpenSceneGraph REQUIRED CONFIG)
#
#	list(APPEND OSGLibs osg osgDB osgFX osgGA osgText osgUtil osgViewer)
#	foreach(_library ${OSGLibs})
#		add_library(${_library} ALIAS openscenegraph::${_library})
#	endforeach()
#	add_library(OpenThreads ALIAS OpenThreads::OpenThreads)

	set(OSG_INC_DIR "/usr/local/include")
	set(OSG_LIB_RELEASE_DIR "/usr/local/lib")
	set(OSG_LIB_DEBUG_DIR "/usr/local/lib")
	list(APPEND OSGLibs OpenThreads osg osgDB osgFX osgGA osgText osgUtil osgViewer)
	foreach(_library ${OSGLibs})
		add_library(${_library} SHARED IMPORTED)
		set_property(TARGET ${_library} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OSG_INC_DIR})
		set_property(TARGET ${_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
		set_target_properties(${_library} PROPERTIES
		IMPORTED_LOCATION_RELEASE "${OSG_LIB_RELEASE_DIR}/lib${_library}.so"
		IMPORTED_LOCATION_DEBUG "${OSG_LIB_DEBUG_DIR}/lib${_library}d.so"
		LINK_FLAGS "-Wl,-rpath,${OSG_LIB_RELEASE_DIR}/"
		)
	endforeach()

endif()