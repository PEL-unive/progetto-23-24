#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("test 1 operator+=") {
    /* all leaves */
    const double w1 = get_random_double();
    const double w2 = get_random_double();
    const double w3 = get_random_double();
    trie<char> x(w1), y(w2), z(w3);
    x += y += z;
    pel_2324::my_trie<char> x_(w1), y_(w2), z_(w3);
    x_ += y_ += z_;
    bool equal = x == x_;
    REQUIRE_MESSAGE(equal, "ERROR in test 1 operator+=: tries are not equal.");
}

TEST_CASE("test 1 operator+") {
    /* all leaves */
    const double w1 = get_random_double();
    const double w2 = get_random_double();
    const double w3 = get_random_double();
    trie<char> x(w1), y(w2), z(w3);
    trie<char> res = x + y + z;
    pel_2324::my_trie<char> x_(w1), y_(w2), z_(w3);
    pel_2324::my_trie<char> res_ = x_ + y_ + z_;
    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 1 operator+: tries are not equal.");
}

TEST_CASE("test 2 operator+=") {
    /* leaf + internal node */
    std::string path = "../test_data/trie_char3.tr";

    const double w = get_random_double();
    trie<char> leaf(w);
    trie<char> node;
    {
        std::ifstream ifs(path);
        ifs >> node;
    }
    leaf += node;

    pel_2324::my_trie<char> leaf_(w);
    pel_2324::my_trie<char> node_;
    {
        std::ifstream ifs(path);
        ifs >> node_;
    }
    leaf_ += node_;

    bool equal = leaf == leaf_;
    REQUIRE_MESSAGE(equal, "ERROR in test 2 operator+=: tries are not equal.");
}

TEST_CASE("test 2 operator+") {
    /* leaf + internal node */
    std::string path = "../test_data/trie_char3.tr";

    const double w = get_random_double();
    trie<char> leaf(w);
    trie<char> node;
    {
        std::ifstream ifs(path);
        ifs >> node;
    }
    trie<char> res = leaf + node;

    pel_2324::my_trie<char> leaf_(w);
    pel_2324::my_trie<char> node_;
    {
        std::ifstream ifs(path);
        ifs >> node_;
    }
    pel_2324::my_trie<char> res_ = leaf_ + node_;

    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 2 operator+: tries are not equal.");
}

TEST_CASE("test 3 operator+=") {
    /* internal node + leaf */
    std::string path = "../test_data/trie_char3.tr";

    const double w = get_random_double();
    trie<char> leaf(w);
    trie<char> node;
    {
        std::ifstream ifs(path);
        ifs >> node;
    }
    node += leaf;

    pel_2324::my_trie<char> leaf_(w);
    pel_2324::my_trie<char> node_;
    {
        std::ifstream ifs(path);
        ifs >> node_;
    }
    node_ += leaf_;

    bool equal = node == node_;
    REQUIRE_MESSAGE(equal, "ERROR in test 3 operator+=: tries are not equal.");
}

TEST_CASE("test 3 operator+") {
    /* internal node + leaf */
    std::string path = "../test_data/trie_char3.tr";

    const double w = get_random_double();
    trie<char> leaf(w);
    trie<char> node;
    {
        std::ifstream ifs(path);
        ifs >> node;
    }
    trie<char> res = node + leaf;

    pel_2324::my_trie<char> leaf_(w);
    pel_2324::my_trie<char> node_;
    {
        std::ifstream ifs(path);
        ifs >> node_;
    }
    pel_2324::my_trie<char> res_ = node_ + leaf_;

    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 3 operator+: tries are not equal.");
}

TEST_CASE("test 4 operator+=") {
    /* internal node + internal node */
    trie<char> l, r;
    pel_2324::my_trie<char> res;
    {
        std::ifstream is("../test_data/trie_char_left_fig8.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig8.tr");
        is >> r;
    }
    l += r;
    {
        std::ifstream is("../test_data/trie_char_result_fig8.tr");
        is >> res;
    }
    bool equal = l == res;
    REQUIRE_MESSAGE(equal, "ERROR in test 4 operator+=: tries are not equal.");
}

TEST_CASE("test 4 operator+") {
    /* internal node + internal node */
    trie<char> l, r;
    {
        std::ifstream is("../test_data/trie_char_left_fig8.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig8.tr");
        is >> r;
    }
    trie<char> res = l + r;
    pel_2324::my_trie<char> res_;
    {
        std::ifstream is("../test_data/trie_char_result_fig8.tr");
        is >> res_;
    }
    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 4 operator+: tries are not equal.");
}

TEST_CASE("test 5 operator+=") {
    /* internal node + internal node */
    trie<char> l, r;
    pel_2324::my_trie<char> res;
    {
        std::ifstream is("../test_data/trie_char_left_fig8-v2.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig8-v2.tr");
        is >> r;
    }
    l += r;
    {
        std::ifstream is("../test_data/trie_char_result_fig8-v2.tr");
        is >> res;
    }
    bool equal = l == res;
    REQUIRE_MESSAGE(equal, "ERROR in test 5 operator+=: tries are not equal.");
}

TEST_CASE("test 5 operator+") {
    /* internal node + internal node */
    trie<char> l, r;
    {
        std::ifstream is("../test_data/trie_char_left_fig8-v2.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig8-v2.tr");
        is >> r;
    }
    trie<char> res = l + r;
    pel_2324::my_trie<char> res_;
    {
        std::ifstream is("../test_data/trie_char_result_fig8-v2.tr");
        is >> res_;
    }
    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 5 operator+: tries are not equal.");
}

TEST_CASE("test 6 operator+=") {
    /* internal node + internal node */
    trie<char> l, r;
    pel_2324::my_trie<char> res;
    {
        std::ifstream is("../test_data/trie_char_left_fig9.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig9.tr");
        is >> r;
    }
    l += r;
    {
        std::ifstream is("../test_data/trie_char_result_fig9.tr");
        is >> res;
    }
    bool equal = l == res;
    REQUIRE_MESSAGE(equal, "ERROR in test 6 operator+=: tries are not equal.");
}

TEST_CASE("test 6 operator+") {
    /* internal node + internal node */
    trie<char> l, r;
    {
        std::ifstream is("../test_data/trie_char_left_fig9.tr");
        is >> l;
    }
    {
        std::ifstream is("../test_data/trie_char_right_fig9.tr");
        is >> r;
    }
    trie<char> res = l + r;
    pel_2324::my_trie<char> res_;
    {
        std::ifstream is("../test_data/trie_char_result_fig9.tr");
        is >> res_;
    }
    bool equal = res == res_;
    REQUIRE_MESSAGE(equal, "ERROR in test 6 operator+: tries are not equal.");
}
