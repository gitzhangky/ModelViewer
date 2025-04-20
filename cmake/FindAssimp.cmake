#-----------------------------------------------------------------------------
# 引入Render基础模块
#-----------------------------------------------------------------------------

#防止重复引入
if(ASSIMP_ALREADY_INCLUDED)
	return()
endif()
set(ASSIMP_ALREADY_INCLUDED 1)

if(WIN32)
	#设置路径
	get_filename_component(ASSIMP_Dir "${CMAKE_SOURCE_DIR}/external/Assimp/" ABSOLUTE)

	message(${ASSIMP_Dir})
	set(ASSIMP_INC_DIR "${ASSIMP_Dir}/include")
	set(ASSIMP_LIB_DUBUG_DIR "${ASSIMP_Dir}/lib/")
	set(ASSIMP_BIN_DUBUG_DIR "${ASSIMP_Dir}/bin/")
	set(ASSIMP_LIB_RELEASE_DIR "${ASSIMP_Dir}/lib")
	set(ASSIMP_BIN_RELEASE_DIR "${ASSIMP_Dir}/bin")
	set(ASSIMP_TEMP_LIB_DIR "${ASSIMP_Dir}/lib")
	set(ASSIMP_TEMP_BIN_DIR "${ASSIMP_Dir}/bin")
	list(APPEND ASSIMPLibs assimp-vc143-mt)

	foreach(_library ${ASSIMPLibs})
		add_library(${_library} SHARED IMPORTED)
		set_property(TARGET ${_library} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ASSIMP_INC_DIR})
		set_property(TARGET ${_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
		set_target_properties(${_library} PROPERTIES
		IMPORTED_IMPLIB_RELEASE "${ASSIMP_TEMP_LIB_DIR}/${_library}.lib"
		IMPORTED_LOCATION_RELEASE "${ASSIMP_BIN_RELEASE_DIR}/${_library}.dll"
		IMPORTED_IMPLIB_DEBUG "${ASSIMP_TEMP_LIB_DIR}/${_library}d.lib"
		IMPORTED_LOCATION_DEBUG "${ASSIMP_BIN_DUBUG_DIR}/${_library}d.dll"
		)
	endforeach()
else()



	set(ASSIMP_INC_DIR "/usr/local/include")
	set(ASSIMP_LIB_RELEASE_DIR "/usr/local/lib")
	set(ASSIMP_LIB_DEBUG_DIR "/usr/local/lib")
	list(APPEND ASSIMPLibs assimp-vc143-mt)
	foreach(_library ${ASSIMPLibs})
		add_library(${_library} SHARED IMPORTED)
		set_property(TARGET ${_library} PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${ASSIMP_INC_DIR})
		set_property(TARGET ${_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
		set_target_properties(${_library} PROPERTIES
		IMPORTED_LOCATION_RELEASE "${ASSIMP_LIB_RELEASE_DIR}/lib${_library}.so"
		IMPORTED_LOCATION_DEBUG "${ASSIMP_LIB_DEBUG_DIR}/lib${_library}d.so"
		LINK_FLAGS "-Wl,-rpath,${ASSIMP_LIB_RELEASE_DIR}/"
		)
	endforeach()

endif()