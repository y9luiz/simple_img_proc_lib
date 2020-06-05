project(my_img_proc_lib)


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB old_hdrs "${PROJECT_SOURCE_DIR}/*.h")
#message(${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
install(FILES ${old_hdrs}
     DESTINATION lib
     COMPONENT   dev
     )
add_library(common SHARED ${PROJECT_SOURCE_DIR}/img.cpp ${old_hdrs})



target_link_libraries(common)

install (TARGETS common
    LIBRARY
    DESTINATION lib
)