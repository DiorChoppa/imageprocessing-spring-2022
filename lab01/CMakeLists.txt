project(lab01)
add_executable(lab01 lab01.cpp lab01.report.md.in.txt)
target_link_libraries(lab01 ${OpenCV_LIBS})

# prepare report md file
file(READ lab01.cpp cpp_source)
configure_file(lab01.report.md.in.txt ${CMAKE_CURRENT_BINARY_DIR}/lab01.report.md @ONLY)
add_custom_command(TARGET ${PROJECT_NAME}
POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/lab01.report.md" "$<TARGET_FILE_DIR:${PROJECT_NAME}>")