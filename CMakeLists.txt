cmake_minimum_required(VERSION 3.20)

project("files_sync_service")

set(APP ${PROJECT_NAME})

set(SRC
    src/dir_sniffer.ixx

    main.cpp
)

add_executable(${APP} ${SRC})
set_property(TARGET ${APP} PROPERTY CXX_STANDARD 23)

# Install
install(TARGETS ${APP} DESTINATION ${CMAKE_SOURCE_DIR}/out/bin)


# Tests
if (TESTS_ENABLED)
  message(STATUS "Configured with tests.")

  enable_testing()

  set(TST_APP ${PROJECT_NAME}-tst)

  set(SRC_TESTS
    tests/tests_main.cpp
  )

  add_executable(${TST_APP} ${SRC_TESTS})
  set_property(TARGET ${TST_APP} PROPERTY CXX_STANDARD 23)

  # Install
  install(TARGETS ${TST_APP} DESTINATION ${CMAKE_SOURCE_DIR}/out/bin_tests)
endif()