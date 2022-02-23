project(lab02)
add_executable(lab02 lab02.cpp lab02.report.md.in.txt)
target_link_libraries(lab02 ${OpenCV_LIBS})

file(READ lab02.cpp cpp_source)
# prepare report md file
configure_file(lab02.report.md.in.txt ${CMAKE_CURRENT_BINARY_DIR}/lab02.report.md @ONLY)
add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/lab02.report.md" "$<TARGET_FILE_DIR:${PROJECT_NAME}>")