#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

template <typename Trie>
Trie const& test_const_max(Trie const& t) {
    return t.max();
}

template <typename Trie>
Trie& test_max(Trie& t) {
    return t.max();
}

TEST_CASE("test 1 max") {
    trie<int> t1;
    pel_2324::my_trie<int> t2;
    {
        auto const& leaf_t1 = test_const_max(t1);
        auto const& leaf_t2 = test_const_max(t2);
        REQUIRE_MESSAGE(leaf_t1.get_weight() == 0.0,
                        "ERROR in test 1 --> wrong max weight");
        REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                        "ERROR in test 1 --> weights are not equal.");
    }
    {
        auto& leaf_t1 = test_max(t1);
        auto& leaf_t2 = test_max(t2);
        REQUIRE_MESSAGE(leaf_t1.get_weight() == 0.0,
                        "ERROR in test 1 --> wrong max weight");
        REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                        "ERROR in test 1 --> weights are not equal.");
    }
}

TEST_CASE("test 2 max") {
    const double w = get_random_double();
    trie<int> t1(w);
    pel_2324::my_trie<int> t2(w);
    {
        auto const& leaf_t1 = test_const_max(t1);
        auto const& leaf_t2 = test_const_max(t2);
        REQUIRE_MESSAGE(leaf_t1.get_weight() == w,
                        "ERROR in test 2 --> wrong max weight");
        REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                        "ERROR in test 2 --> weights are not equal.");
    }
    {
        auto& leaf_t1 = test_max(t1);
        auto& leaf_t2 = test_max(t2);
        REQUIRE_MESSAGE(leaf_t1.get_weight() == w,
                        "ERROR in test 2 --> wrong max weight");
        REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                        "ERROR in test 2 --> weights are not equal.");
    }
}

TEST_CASE("test 3 max") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t1;
        pel_2324::my_trie<char> t2;
        {
            std::ifstream ifs(path);
            ifs >> t1;
        }
        {
            std::ifstream ifs(path);
            ifs >> t2;
        }

        {
            auto const& leaf_t1 = test_const_max(t1);
            auto const& leaf_t2 = test_const_max(t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 3 --> weights are not equal.");
        }
        {
            auto& leaf_t1 = test_max(t1);
            auto& leaf_t2 = test_max(t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 3 --> weights are not equal.");
            leaf_t1.set_weight(-10000.0);
            leaf_t2.set_weight(-10000.0);
        }
        {
            auto const& leaf_t1 = test_const_max(t1);
            auto const& leaf_t2 = test_const_max(t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 3 --> weights are not equal.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 4 max") {
    try {
        std::string path = "../test_data/trie_char3.tr";
        trie<char> t1;
        pel_2324::my_trie<char> t2;
        {
            std::ifstream ifs(path);
            ifs >> t1;
        }
        {
            std::ifstream ifs(path);
            ifs >> t2;
        }

        std::vector<char> prefix{'z', 'c'};
        {
            auto const& sub_t1 = t1[prefix];
            auto const& sub_t2 = t2[prefix];
            auto const& leaf_t1 = test_const_max(sub_t1);
            auto const& leaf_t2 = test_const_max(sub_t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 4 --> weights are not equal.");
        }
        {
            auto& sub_t1 = t1[prefix];
            auto& sub_t2 = t2[prefix];
            auto& leaf_t1 = test_max(sub_t1);
            auto& leaf_t2 = test_max(sub_t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 4 --> weights are not equal.");
            const double w = get_random_double();
            leaf_t1.set_weight(100.0 * w);
            leaf_t2.set_weight(100.0 * w);
        }
        {
            auto const& leaf_t1 = test_const_max(t1);
            auto const& leaf_t2 = test_const_max(t2);
            REQUIRE_MESSAGE(leaf_t1.get_weight() == leaf_t2.get_weight(),
                            "ERROR in test 4 --> weights are not equal.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}
