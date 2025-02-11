#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("test copy constructor 1") {
    trie<char> t1;
    trie<char> t2 = t1;
    pel_2324::my_trie<char> t3;
    bool equal1 = t1 == t2;
    bool equal2 = t1 == t3;
    REQUIRE_MESSAGE(equal1, "ERROR --> tries are not equal");
    REQUIRE_MESSAGE(equal2, "ERROR --> tries are not equal");
}

TEST_CASE("test copy assignment 1") {
    trie<char> t1;
    trie<char> t2;
    t2 = t1;
    pel_2324::my_trie<char> t3;
    bool equal1 = t1 == t2;
    bool equal2 = t1 == t3;
    REQUIRE_MESSAGE(equal1, "ERROR --> tries are not equal");
    REQUIRE_MESSAGE(equal2, "ERROR --> tries are not equal");
}

TEST_CASE("test copy constructor 2") {
    const double w = get_random_double();
    trie<char> t1(w);
    trie<char> t2 = t1;
    pel_2324::my_trie<char> t3(w);
    bool equal1 = t1 == t2;
    bool equal2 = t1 == t3;
    REQUIRE_MESSAGE(equal1, "ERROR --> tries are not equal");
    REQUIRE_MESSAGE(equal2, "ERROR --> tries are not equal");
}

TEST_CASE("test copy assignment 2") {
    const double w = get_random_double();
    trie<char> t1(w);
    trie<char> t2;
    t2 = t1;
    pel_2324::my_trie<char> t3(w);
    bool equal1 = t1 == t2;
    bool equal2 = t1 == t3;
    REQUIRE_MESSAGE(equal1, "ERROR --> tries are not equal");
    REQUIRE_MESSAGE(equal2, "ERROR --> tries are not equal");
}

TEST_CASE("test move constructor 1") {
    trie<char> t1;
    trie<char> t2 = std::move(t1);
    pel_2324::my_trie<char> t3;
    bool equal = t2 == t3;
    REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
}

TEST_CASE("test move assignment 1") {
    trie<char> t1;
    trie<char> t2;
    t2 = std::move(t1);
    pel_2324::my_trie<char> t3;
    bool equal = t2 == t3;
    REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
}

TEST_CASE("test move constructor 2") {
    const double w = get_random_double();
    trie<char> t1(w);
    trie<char> t2 = std::move(t1);
    pel_2324::my_trie<char> t3(w);
    bool equal = t2 == t3;
    REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
}

TEST_CASE("test move assignment 2") {
    const double w = get_random_double();
    trie<char> t1(w);
    trie<char> t2;
    t2 = std::move(t1);
    pel_2324::my_trie<char> t3(w);
    bool equal = t2 == t3;
    REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
}

TEST_CASE("test copy constructor 3") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t;
        {
            std::ifstream ifs(path);
            ifs >> t;
        }
        trie<char> t1 = t;
        bool equal = t1 == t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        equal = t1 == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test copy assignment 3") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t1;
        {
            trie<char> t;
            std::ifstream ifs(path);
            ifs >> t;
            t1 = t;
        }
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = t1 == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test move assignment 3") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t1;
        {
            trie<char> t;
            std::ifstream ifs(path);
            ifs >> t;
            t1 = std::move(t);
        }
        pel_2324::my_trie<char> my_t;
        {
            std::ifstream ifs(path);
            ifs >> my_t;
        }
        bool equal = t1 == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
        const double w = get_random_double();
        t1 = {w};
        my_t = {w};
        equal = t1 == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test copy assignment 4") {
    try {
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

        bool equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

        /*
            Assign a leaf to a subtrie,
            hence effectively modifying the original trie.
         */
        const double w = get_random_double();
        trie<char> leaf(w);
        pel_2324::my_trie<char> my_leaf(w);
        t[{'z', 'c'}] = leaf;
        my_t[{'z', 'c'}] = my_leaf;
        equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

        /*
            Re-assign subtries.
         */
        t[{'z', 'c'}] = t[{'a'}];
        my_t[{'z', 'c'}] = my_t[{'a'}];
        equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test move assignment 4") {
    try {
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

        bool equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

        const double w = get_random_double();

        /*
            Assign a leaf to a subtrie,
            hence effectively modifying the original trie.
         */
        t[{'z', 'c'}] = {w};
        my_t[{'z', 'c'}] = {w};
        equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

        /*
            Re-assign subtries.
         */
        trie<char> copy = t[{'a'}];
        t[{'z', 'c'}] = std::move(copy);
        pel_2324::my_trie<char> my_copy = my_t[{'a'}];
        my_t[{'z', 'c'}] = std::move(my_copy);

        equal = t == my_t;
        REQUIRE_MESSAGE(equal, "ERROR --> tries are not equal");

    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}