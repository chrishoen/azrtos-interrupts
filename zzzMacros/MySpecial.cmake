#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_print_cmake_vars)

   message(STATUS "my_special1***********************************************************BEGIN")
   message(STATUS "CMAKE_SYSTEM_PROCESSOR   " ${CMAKE_SYSTEM_PROCESSOR})
   message(STATUS "CMAKE_CXX_COMPILER_ID    " ${CMAKE_CXX_COMPILER_ID})
   message(STATUS "CMAKE_C_COMPILER         " ${CMAKE_C_COMPILER})
   message(STATUS "CMAKE_CXX_COMPILER       " ${CMAKE_CXX_COMPILER})
   message(STATUS "CMAKE_BUILD_TYPE         " ${CMAKE_BUILD_TYPE})
   message(STATUS "CMAKE_C_FLAGS            " ${CMAKE_C_FLAGS})
   message(STATUS "CMAKE_C_FLAGS_RELEASE    " ${CMAKE_C_FLAGS_RELEASE})
   message(STATUS "CMAKE_C_FLAGS_DEBUG      " ${CMAKE_C_FLAGS_DEBUG})
   message(STATUS "CMAKE_CXX_FLAGS          " ${CMAKE_CXX_FLAGS})
   message(STATUS "CMAKE_CXX_FLAGS_RELEASE  " ${CMAKE_CXX_FLAGS_RELEASE})
   message(STATUS "CMAKE_CXX_FLAGS_DEBUG    " ${CMAKE_CXX_FLAGS_DEBUG})
   message(STATUS "CMAKE_EXE_LINKER_FLAGS   " ${CMAKE_EXE_LINKER_FLAGS})
   message(STATUS "CMAKE_SYSROOT            " ${CMAKE_SYSROOT})
   message(STATUS "CMAKE_TOOLCHAIN_FILE     " ${CMAKE_TOOLCHAIN_FILE})
   message(STATUS "CMAKE_SYSTEM             " ${CMAKE_SYSTEM})
   message(STATUS "CMAKE_BUILD_TYPE         " ${CMAKE_BUILD_TYPE})
   message(STATUS "PROJECT_SOURCE_DIR       " ${PROJECT_SOURCE_DIR})
   message(STATUS "my_special1***********************************************************END")
endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

