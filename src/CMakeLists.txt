add_executable(regress
    main.cpp
    TestDiscovery.cpp
)

target_link_libraries(regress PRIVATE CLI11::CLI11)
target_include_directories(regress PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
