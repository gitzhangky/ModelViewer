# - Config file for the OpenSceneGraph package.
#
# For finding and loading OpenSceneGraph from your project, type:
#
# find_package(OpenSceneGraph [version] [COMPONENTS comp])
#
# This creates the following variables:
#
# OpenSceneGraph_LIBRARIES    : All the libraries of all the requested components
# OPENSCENEGRAPH_LIBRARIES
#
# OpenSceneGraph_INCLUDE_DIRS : All the include directories of all the requested components
# OPENSCENEGRAPH_INCLUDE_DIRS
#
# OpenSceneGraph_FOUND        : Set to true if all required components can be found
# OPENSCENEGRAPH_FOUND
#
# OpenSceneGraph_<comp>_FOUND : Set to true if this component was found
# OPENSCENEGRAPH_<COMP>_FOUND
#
# OSG_LIBRARY                 : The library for the core OSG component
# OSG_LIBRARIES
#
# OSG_INCLUDE_DIR             : The include directory for  the core OSG component
#
# <COMP>_LIBRARY              : This is created for each requested component <comp>
# <COMP>_LIBRARIES              and refers to the component's library
#
# <COMP>_INCLUDE_DIR          : This is created for each requested component <comp>
#                               and refers to the component's include directory


################################################################################
#
# This config-file will also import the following targets:
#
#   osg3::osg     (for the core OSG library)
#   osg3::<comp>  (for each requested component library)
#
# Use target_link_libraries(tgt [PUBLIC|PRIVATE] osg3::<comp>)
# for each component that you want to link to.
#
# For convenience, this will also produce a variable
#
#   OpenSceneGraph_TARGETS
#
# which will contain the targets of all the requested components.
#
################################################################################


# =========================== DO NOT MODIFY THIS FILE DIRECTLY ===========================
# This file is auto-generated from OpenSceneGraph/CMakeModules/OpenSceneGraphConfig.cmake
# ========================================================================================

# We depend on 2.8.8 for CMakePackageConfigHelpers. This config file is not
# guaranteed to work with lower versions of cmake.
cmake_minimum_required(VERSION 3.5.0)

# Assume we have succeeded unless a required component is missing
set(OpenSceneGraph_FOUND TRUE)
set(OPENSCENEGRAPH_FOUND TRUE)

# Shortcut if find_package(OpenSceneGraph ...) has been called before
if(OpenSceneGraph_CONFIG_INCLUDED)

    # Check that each of the components requested have already been found.
    set(OpenSceneGraph_all_components_found TRUE)
    foreach(component ${OpenSceneGraph_FIND_COMPONENTS})
        if(NOT TARGET osg3::${component})
            set(OpenSceneGraph_all_components_found FALSE)
            break()
        endif()
    endforeach()

    # If this config file has been called before, and all the requested
    # components are already found, then exit early.
    if(OpenSceneGraph_all_components_found)
        return()
    endif()

endif()
set(OpenSceneGraph_CONFIG_INCLUDED TRUE)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was OpenSceneGraphConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

set(OpenSceneGraph_INCLUDE_DIRS ${PACKAGE_PREFIX_DIR}/include)
set(OPENSCENEGRAPH_INCLUDE_DIRS ${OpenSceneGraph_INCLUDE_DIRS})

set(OpenSceneGraph_LIBRARIES)

set(OpenSceneGraph_TARGETS)

foreach(component OpenThreads osg ${OpenSceneGraph_FIND_COMPONENTS})

    if(TARGET osg3::${component})
        # This component has already been found, so we'll skip it
        set(OpenSceneGraph_${component}_FOUND TRUE)
        set(OPENSCENEGRAPH_${component}_FOUND TRUE)
        continue()
    endif()

    string(TOUPPER ${component} UC_COMPONENT)

    set(osg_component_import_target_file ${CMAKE_CURRENT_LIST_DIR}/openscenegraph-${component}-import-targets.cmake)

    if(NOT EXISTS ${osg_component_import_target_file})

        if(OpenSceneGraph_FIND_REQUIRED_${component} OR NOT OpenSceneGraph_FIND_QUIETLY)
            message("Could not find [${component}] component of OpenSceneGraph")
        endif()

        set(OpenSceneGraph_${component}_FOUND FALSE)
        set(OPENSCENEGRAPH_${UC_COMPONENT}_FOUND FALSE)

        continue()

    endif()

    include(${osg_component_import_target_file})

    list(APPEND OpenSceneGraph_TARGETS osg3::${component})

    set(OpenSceneGraph_${component}_FOUND TRUE)
    set(OPENSCENEGRAPH_${component}_FOUND TRUE)

    if(NOT OpenSceneGraph_FIND_QUIETLY)
        message(STATUS "Found [${component}] component of OpenSceneGraph")
    endif()

    # Components all get installed to the same include directory
    set(${UC_COMPONENT}_INCLUDE_DIR ${OpenSceneGraph_INCLUDE_DIRS})

    if(_WIN32)
        # For Windows, we need to provide the consumer with the IMPLIB (.lib) file
        set(osg_imported_lib_property IMPORTED_IMPLIB)
    else()
        # For UNIX, we need to provide the shared object (.so) file
        set(osg_imported_lib_property IMPORTED_LOCATION)
    endif()

    # For each possible configuration, find the relevant file on disk
    foreach(osg_configuration "" _DEBUG _RELEASE)

        get_property(${UC_COMPONENT}_LIBRARY${osg_configuration}
            TARGET osg3::${component}
            PROPERTY ${osg_imported_lib_property}${osg_configuration}
        )
        set(${UC_COMPONENT}_LIBRARIES${osg_configuration} ${${UC_COMPONENT}_LIBRARY})

    endforeach()

    # If a default library configuration was not found, create it
    if(NOT ${UC_COMPONENT}_LIBRARY)

        if(${UC_COMPONENT}_LIBRARY_DEBUG AND ${UC_COMPONENT}_LIBRARY_RELEASE)

            # We have a release and a debug library, so let's use both
            set(${UC_COMPONENT}_LIBRARY
                optimized ${${UC_COMPONENT}_LIBRARY_RELEASE}
                debug ${${UC_COMPONENT}_LIBRARY_DEBUG})

        elseif(${UC_COMPONENT}_LIBRARY_RELEASE)

            # There is only a release library, so let's use that
            set(${UC_COMPONENT}_LIBRARY optimized ${${UC_COMPONENT}_LIBRARY_RELEASE})

        elseif(${UC_COMPONENT}_LIBRARY_DEBUG)

            # There is only a debug library, so let's use that
            set(${UC_COMPONENT}_LIBRARY debug ${${UC_COMPONENT}_LIBRARY_DEBUG})

        else()

            # This should never happen, or else something is severely broken
            # with the configuration, so we'll quit early.
            message(FATAL_ERROR
                "Could not find either an optimized or a debug version of the "
                "requested OSG component: [${component}]")

        endif()

        set(${UC_COMPONENT}_LIBRARIES ${${UC_COMPONENT}_LIBRARY})

    endif()

    list(APPEND OpenSceneGraph_LIBRARIES ${${UC_COMPONENT}_LIBRARIES})

endforeach()

set(OPENSCENEGRAPH_LIBRARIES ${OpenSceneGraph_LIBRARIES})

check_required_components(OpenSceneGraph)
set(OPENSCENEGRAPH_FOUND ${OpenSceneGraph_FOUND})
