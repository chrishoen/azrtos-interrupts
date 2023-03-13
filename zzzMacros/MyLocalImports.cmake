#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_threadx _target)

   target_link_libraries(${_target} azrtos::threadx)
   target_link_libraries(${_target} winmm)

endfunction()

function(my_inc_import_threadx _target)

   target_include_directories(${_target} PRIVATE $<TARGET_PROPERTY:azrtos::threadx,INTERFACE_INCLUDE_DIRECTORIES>)

endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_filex _target)

   target_link_libraries(${_target} azrtos::filex)

endfunction()

function(my_inc_import_filex _target)

   target_include_directories(${_target} PRIVATE $<TARGET_PROPERTY:azrtos::filex,INTERFACE_INCLUDE_DIRECTORIES>)

endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_netxduo _target)

   target_link_libraries(${_target} azrtos::netxduo)

endfunction()

function(my_inc_import_netxduo _target)

   target_include_directories(${_target} PRIVATE $<TARGET_PROPERTY:azrtos::netxduo,INTERFACE_INCLUDE_DIRECTORIES>)

endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

