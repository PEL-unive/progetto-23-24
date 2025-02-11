#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("load small file") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path = "../test_data/trie_char1.tr";
        trie<char> t;
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> t;
        }
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("load big file 1") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t;
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> t;
        }
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("load big file 2") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path = "../test_data/trie_char1.tr";
        trie<char> t;
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> t;
        }
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("load big file 3") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path = "../test_data/trie_char1.tr";
        trie<char> t;
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> t;
        }
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "ERROR --> file was loaded incorrectly.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("load, save, re-load with our code and compare") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path1 = "../test_data/trie_string.tr";
        std::string path2 = "../test_data/deleteme.tr";
        trie<std::string> t;
        pel_2324::my_trie<std::string> my_t;
        {
            std::ifstream ifs(path1);
            ifs >> t;
        }
        {
            std::ofstream ofs(path2);
            ofs << t;
        }
        {
            std::ifstream ifs(path2);
            ifs >> my_t;
            ifs.close();
            std::remove(path2.c_str());
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "error: loaded/saved tries do not match.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("load two times") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path1 = "../test_data/trie_string.tr";
        trie<std::string> t;
        pel_2324::my_trie<std::string> my_t;
        {
            std::ifstream ifs(path1);
            ifs >> t;
        }
        {
            std::ifstream ifs(path1);
            ifs >> t;
        }
        {
            std::ifstream ifs(path1);
            ifs >> my_t;
        }
        bool equal = (t == my_t);
        REQUIRE_MESSAGE(equal == true,
                        "error: loaded/saved tries do not match.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("format error 1") {
    std::string path = "../test_data/trie_char_error1.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}

TEST_CASE("format error 2") {
    std::string path = "../test_data/trie_char_error2.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}

TEST_CASE("format error 3") {
    std::string path = "../test_data/trie_char_error3.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}

TEST_CASE("format error 4") {
    std::string path = "../test_data/trie_char_error4.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}

TEST_CASE("format error 5") {
    std::string path = "../test_data/trie_char_error5.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}

TEST_CASE("format error 6") {
    std::string path = "../test_data/trie_char_error6.tr";
    trie<char> t;
    std::ifstream ifs(path);
    bool exception_thrown = false;
    try {
        ifs >> t;
    } catch (parser_exception const& e) {
        (void)e;
        // std::cout << e.what() << std::endl;
        exception_thrown = true;
    }
    REQUIRE_MESSAGE(
        exception_thrown == true,
        "ERROR --> file not in correct format but exception not thrown");
}