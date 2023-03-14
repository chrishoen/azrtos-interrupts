cmake_minimum_required (VERSION 3.8)

set (project "Test1")
project(${project} CXX)
#my_find_src_files (src_files ${project})
set(src_files
   ${PROJECT_SOURCE_DIR}/sample_threadx.c
   ${PROJECT_SOURCE_DIR}/sample_interrupt.c
)
add_executable (${project} ${src_files})
#my_add_compile_options (${project})
#my_add_pch (${project})


my_inc_import_threadx(${project})
my_lib_import_threadx(${project})

include("${MY_MACRO_DIR}/MyInstall.cmake")

