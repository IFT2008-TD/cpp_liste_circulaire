add_executable(tests tests_liste_circulaire.cpp
        TestListeCirculaire.h)
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(
        tests
        gtest
        gtest_main
        pthread
)
include(GoogleTest)
gtest_discover_tests(tests)