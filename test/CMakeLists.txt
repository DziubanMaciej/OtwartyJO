function(create_test TEST_NAME SOURCE_FILE_NAME)
    add_executable(${TEST_NAME} ${SOURCE_FILE_NAME})
    target_link_libraries(${TEST_NAME} OtwartyJo)
endfunction()

create_test(OtwartyJoTestWektory wektory.c)
create_test(OtwartyJoTestInfo    jo_info.c)
