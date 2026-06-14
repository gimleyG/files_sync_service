cmake_minimum_required(VERSION 3.20)

project("files_sync_service")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP ${PROJECT_NAME})

# Application library
set(APP_LIB ${APP}-lib)
set(APP_LIB_SRC
  src/dir_sniffer.ixx
)
add_library(${APP_LIB} STATIC
  ${APP_LIB_SRC}
)

# Application
set(SRC
  main.cpp
)
add_executable(${APP} ${SRC})
target_link_libraries(${APP}
  PRIVATE ${APP_LIB}
)

# Install
install(TARGETS ${APP} DESTINATION ${CMAKE_SOURCE_DIR}/out/bin)


# Tests
if (TESTS_ENABLED)
  message(STATUS "Configured with tests.")

  enable_testing()

  set(TST_APP ${PROJECT_NAME}-tst)

  set(SRC_TESTS
    tests/different_tests.hpp

    tests/dir_sniffer_tests.cpp

    tests/tests_main.cpp
  )

  add_executable(${TST_APP} ${SRC_TESTS})
  target_link_libraries(${TST_APP}
    PRIVATE ${APP_LIB}
  )

  # Install
  install(TARGETS ${TST_APP} DESTINATION ${CMAKE_SOURCE_DIR}/out/bin_tests)
endif()