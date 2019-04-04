set(CMAKE_VERBOSE_MAKEFILE ON)

cmake_minimum_required(VERSION 3.12)


if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version")
endif()

Project(PYSAM)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")


include_directories(. src $ENV{PY3DIR} $ENV{SAMNTDIR}/api/include)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(pysam SHARED
        TestSystem.c
		src/PySAM_utils.h src/AdjustmentFactors.c
		src/GenericSystem.c)


set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")


# setup linking dependencies and flags

# if running as combined build, make sure to link to projects
unset(SSC_LIB CACHE)
unset(SAM_API_LIB CACHE)
find_library( SSC_LIB
        NAMES libsscd.so sscd.lib
        PATHS data )
find_library( SAM_API_LIB
        NAMES libSAM_apid.so SAM_apid.lib
        PATHS data)
target_link_libraries(pysam ${SSC_LIB} ${SAM_API_LIB})


#setup compile options
if(MSVC)
    add_compile_definitions( __64BIT__ __WINDOWS__ __DLL__
        _WINDOWS _CRT_NON_CONFORMING_SWPRINTFS=1
        _SCL_SECURE_NO_WARNINGS=1 _UNICODE NOPCH)
    set_target_properties(${pysam} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_CURRENT_SOURCE_DIR}>)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
        PROPERTY VS_STARTUP_PROJECT ${pysam})

	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} /NODEFAULTLIB")
else()
    target_compile_options(pysam PUBLIC -O3 -framework Python)

    target_link_libraries(pysam -lm -lcurl)
endif()

# copy needed dlls
if(MSVC)
add_custom_command(
	TARGET pysam
		POST_BUILD 
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$ENV{SSCDIR}/build_vs2017/x64/Debug/sscd.dll ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			$ENV{SAMNTDIR}/api/SAM_apid.dll ${CMAKE_CURRENT_SOURCE_DIR}
	)
endif()