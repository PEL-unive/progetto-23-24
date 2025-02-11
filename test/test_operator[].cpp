#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

template <typename Trie, typename T>
Trie const& test_const_prefix_search(Trie const& t,
                                     std::vector<T> const& prefix) {
    return t[prefix];
}

template <typename Trie, typename T>
Trie& test_prefix_search(Trie& t, std::vector<T> const& prefix) {
    return t[prefix];
}

// template <typename Trie>
// void print_sequences(Trie const& t) {
//     for (auto it_leaf = t.begin(); it_leaf != t.end(); ++it_leaf) {
//         Trie const& leaf = it_leaf.get_leaf();
//         std::cout << "weight on leaf = " << leaf.get_weight() << std::endl;
//         typename Trie::const_node_iterator it_node = it_leaf;
//         auto root = t.root();
//         std::vector<char> path;
//         while (it_node != root) {
//             path.push_back(*it_node);
//             ++it_node;
//         }
//         if (!path.empty()) {
//             std::reverse(path.begin(), path.end());
//             for (auto x : path) std::cout << x;
//             std::cout << std::endl;
//         }
//     }
// }

TEST_CASE("test 1 operator[]") {
    trie<int> t1;
    pel_2324::my_trie<int> t2;
    std::vector<int> prefix{};
    {
        auto sub_t1 = test_const_prefix_search(t1, prefix);
        auto sub_t2 = test_const_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 1 --> tries are not equal.");
    }
    {
        auto sub_t1 = test_prefix_search(t1, prefix);
        auto sub_t2 = test_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 1 --> tries are not equal.");
    }
}

TEST_CASE("test 2 operator[]") {
    trie<int> t1;
    pel_2324::my_trie<int> t2;
    std::vector<int> prefix{2, 3};
    {
        auto sub_t1 = test_const_prefix_search(t1, prefix);
        auto sub_t2 = test_const_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 2 --> tries are not equal.");
        REQUIRE_MESSAGE((sub_t1 == t1) == true,
                        "ERROR in test 2 --> tries are not equal.");
        REQUIRE_MESSAGE((sub_t1 == t2) == true,
                        "ERROR in test 2 --> tries are not equal.");
    }
    {
        auto sub_t1 = test_prefix_search(t1, prefix);
        auto sub_t2 = test_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 2 --> tries are not equal.");
        REQUIRE_MESSAGE((sub_t1 == t1) == true,
                        "ERROR in test 2 --> tries are not equal.");
        REQUIRE_MESSAGE((sub_t1 == t2) == true,
                        "ERROR in test 2 --> tries are not equal.");
    }
}

TEST_CASE("test 3 operator[]") {
    trie<int> t1(55.413);
    pel_2324::my_trie<int> t2(55.413);
    std::vector<int> prefix{2, 3};
    {
        auto sub_t1 = test_const_prefix_search(t1, prefix);
        auto sub_t2 = test_const_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 3 --> tries are not equal.");
    }
    {
        auto sub_t1 = test_prefix_search(t1, prefix);
        auto sub_t2 = test_prefix_search(t2, prefix);
        REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                        "ERROR in test 3 --> tries are not equal.");
    }
}

TEST_CASE("test 4 operator[]") {
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

        std::vector<char> prefix{'z', 'b'};
        {
            auto sub_t1 = test_const_prefix_search(t1, prefix);
            auto sub_t2 = test_const_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 4 --> tries are not equal.");
        }
        {
            auto sub_t1 = test_prefix_search(t1, prefix);
            auto sub_t2 = test_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 4 --> tries are not equal.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 5 operator[]") {
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

        std::vector<char> prefix{'z'};
        {
            auto sub_t1 = test_const_prefix_search(t1, prefix);
            auto sub_t2 = test_const_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 5 --> tries are not equal.");
        }
        {
            auto sub_t1 = test_prefix_search(t1, prefix);
            auto sub_t2 = test_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 5 --> tries are not equal.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 6 operator[]") {
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
            auto sub_t1 = test_const_prefix_search(t1, prefix);
            auto sub_t2 = test_const_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 6 --> tries are not equal.");
        }
        {
            auto sub_t1 = test_prefix_search(t1, prefix);
            auto sub_t2 = test_prefix_search(t2, prefix);
            // print_sequences(sub_t2);
            REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
                            "ERROR in test 6 --> tries are not equal.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

// TEST_CASE("test 7 operator[]") {
//     trie<char> t1;
//     try {
//         std::string path = "../test_data/trie_char1.tr";
//         {
//             std::ifstream ifs(path);
//             ifs >> t1;
//         }
//     } catch (parser_exception const& e) {
//         REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown:
//         "
//                                    << e.what());
//     }

//     pel_2324::my_trie<char> t2;
//     try {
//         std::string path = "../test_data/trie_char11.tr";
//         {
//             std::ifstream ifs(path);
//             ifs >> t2;
//         }
//     } catch (parser_exception const& e) {
//         REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown:
//         "
//                                    << e.what());
//     }

//     auto sub_t1 = t1[{'b'}];
//     auto sub_t2 = t2[{'z'}];
//     // std::cout << sub_t1 << std::endl;
//     // std::cout << sub_t2 << std::endl;

//     REQUIRE_MESSAGE((sub_t1 == sub_t2) == true,
//                     "ERROR in test 7 --> tries are not equal.");
// }
