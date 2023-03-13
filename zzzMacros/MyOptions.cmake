set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(THREADX_ARCH "win32")
set(THREADX_TOOLCHAIN "vs_2019")



set(CMAKE_C_FLAGS           "/DWIN32 /D_WINDOWS /W3" CACHE INTERNAL "c compiler flags")
set(CMAKE_C_FLAGS_RELEASE   "/MT /O2 /Ob2 /DNDEBUG" CACHE INTERNAL "c compiler flags release")
set(CMAKE_C_FLAGS_DEBUG     "/MTd /Zi /Ob0 /Od /RTC1" CACHE INTERNAL "c compiler flags debug")
set(CMAKE_CXX_FLAGS         "/DWIN32 /D_WINDOWS /W3 /GR /EHsc" CACHE INTERNAL "cxx compiler flags")
set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /DNDEBUG" CACHE INTERNAL "cxx compiler flags release")
set(CMAKE_CXX_FLAGS_DEBUG   "/MTd /Zi /Ob0 /Od /RTC1" CACHE INTERNAL "cxx compiler flags debug")

set(CMAKE_ASM_FLAGS "-x assembler-with-cpp" CACHE INTERNAL "asm compiler flags")
set(CMAKE_EXE_LINKER_FLAGS "/machine:X86" CACHE INTERNAL "exe link flags")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
