#include <iostream>
#include <sstream>

#include "util.hpp"
#include "trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("test 1 operator==") {
    trie<int> a;
    trie<int> b;
    bool equal = (a == b);
    bool not_equal = (a != b);
    REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
    REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
}

TEST_CASE("test 2 operator==") {
    trie<int> a(get_random_double());
    trie<int> b;
    bool equal = (a == b);
    bool not_equal = (a != b);
    REQUIRE_MESSAGE(equal == false, "ERROR --> tries are equal.");
    REQUIRE_MESSAGE(not_equal == true, "ERROR --> tries are not equal.");
}

// TEST_CASE("test 3 operator==") {
//     trie<int> a;
//     trie<int> b;
//     int x = static_cast<int>(get_random_double());
//     b.set_label(&x);
//     bool equal = (a == b);
//     bool not_equal = (a != b);
//     REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
//     REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
// }

/*
    Replaced test 3 with something identical to test 2.
*/

TEST_CASE("test 3 operator==") {
    trie<int> a(get_random_double());
    trie<int> b;
    bool equal = (a == b);
    bool not_equal = (a != b);
    REQUIRE_MESSAGE(equal == false, "ERROR --> tries are equal.");
    REQUIRE_MESSAGE(not_equal == true, "ERROR --> tries are not equal.");
}

TEST_CASE("test 4 operator==") {
    const double w = get_random_double();
    trie<int> a(w);
    trie<int> b(w);
    bool equal = (a == b);
    bool not_equal = (a != b);
    REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
    REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
}

TEST_CASE("test 5 operator==") {
    const double w1 = get_random_double();
    const double w2 = get_random_double();
    trie<int> a(w1);
    trie<int> b(-w1);
    trie<int> c(w2);
    int x = static_cast<int>(get_random_double());
    c.set_label(&x);
    c.set_parent(&b);
    b.add_child(c);
    bool equal = (a == b);
    bool not_equal = (a != b);
    REQUIRE_MESSAGE(equal == false, "ERROR --> tries are equal.");
    REQUIRE_MESSAGE(not_equal == true, "ERROR --> tries are not equal.");
}

TEST_CASE("test 6 operator==") {
    try {
        std::string str("3.9 children = { }");
        trie<char> a, b;
        {
            std::istringstream iss(str);
            iss >> a;
        }
        {
            std::istringstream iss(str);
            iss >> b;
        }
        bool equal = (a == b);
        bool not_equal = (a != b);
        REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
        REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 7 operator==") {
    try {
        std::string str("children = { b 8.4 children = { } }");
        trie<char> a, b;
        {
            std::istringstream iss(str);
            iss >> a;
        }
        {
            std::istringstream iss(str);
            iss >> b;
        }
        bool equal = (a == b);
        bool not_equal = (a != b);
        REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
        REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 8 operator==") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> a, b;
        {
            std::ifstream ifs(path);
            ifs >> a;
        }
        {
            std::ifstream ifs(path);
            ifs >> b;
        }
        bool equal = (a == b);
        bool not_equal = (a != b);
        REQUIRE_MESSAGE(equal == true, "ERROR --> tries are not equal.");
        REQUIRE_MESSAGE(not_equal == false, "ERROR --> tries are equal.");
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}
