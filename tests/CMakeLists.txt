add_executable(tests_liste tests_liste_circulaire.cpp)
target_include_directories(tests_liste PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests_liste
        gtest
        gtest_main
        pthread
        )

include(Googletest)
gtest_discover_tests(tests_liste)