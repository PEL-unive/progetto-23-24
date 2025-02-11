#include <iostream>

#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

template <typename T>
struct weighted_sequence {
    weighted_sequence(double w, std::vector<T>& s) : weight(w) {
        sequence.swap(s);
    }
    bool operator==(weighted_sequence const& rhs) const {
        return weight == rhs.weight and sequence == rhs.sequence;
    }
    double weight;
    std::vector<T> sequence;
};

template <typename Trie, typename T>
std::vector<weighted_sequence<T>> test_const_iterators_pref_incr(
    Trie const& t) {
    std::vector<weighted_sequence<T>> result;
    std::vector<T> sequence;
    for (auto it_leaf = t.begin(); it_leaf != t.end(); ++it_leaf) {
        Trie const& leaf = it_leaf.get_leaf();
        typename Trie::const_node_iterator it_node = it_leaf;
        auto root = t.root();
        assert(sequence.empty());
        while (it_node != root) {
            sequence.push_back(*it_node);
            ++it_node;
        }
        result.emplace_back(leaf.get_weight(), sequence);
    }
    return result;
}

template <typename Trie, typename T>
std::vector<weighted_sequence<T>> test_const_iterators_post_incr(
    Trie const& t) {
    std::vector<weighted_sequence<T>> result;
    std::vector<T> sequence;
    for (auto it_leaf = t.begin(); it_leaf != t.end(); it_leaf++) {
        Trie const& leaf = it_leaf.get_leaf();
        typename Trie::const_node_iterator it_node = it_leaf;
        auto root = t.root();
        assert(sequence.empty());
        while (it_node != root) {
            sequence.push_back(*it_node);
            it_node++;
        }
        result.emplace_back(leaf.get_weight(), sequence);
    }
    return result;
}

template <typename Trie, typename T>
std::vector<weighted_sequence<T>> test_leaf_iterators_pref_incr(Trie& t) {
    std::vector<weighted_sequence<T>> result;
    std::vector<T> sequence;
    for (auto it_leaf = t.begin(); it_leaf != t.end(); ++it_leaf) {
        Trie& leaf = it_leaf.get_leaf();
        typename Trie::node_iterator it_node = it_leaf;
        auto root = t.root();
        assert(sequence.empty());
        while (it_node != root) {
            sequence.push_back(*it_node);
            ++it_node;
        }
        result.emplace_back(leaf.get_weight(), sequence);
    }
    return result;
}

template <typename Trie, typename T>
std::vector<weighted_sequence<T>> test_leaf_iterators_post_incr(Trie& t) {
    std::vector<weighted_sequence<T>> result;
    std::vector<T> sequence;
    for (auto it_leaf = t.begin(); it_leaf != t.end(); it_leaf++) {
        Trie& leaf = it_leaf.get_leaf();
        typename Trie::node_iterator it_node = it_leaf;
        auto root = t.root();
        assert(sequence.empty());
        while (it_node != root) {
            sequence.push_back(*it_node);
            it_node++;
        }
        result.emplace_back(leaf.get_weight(), sequence);
    }
    return result;
}

TEST_CASE("test 1 iterator") {
    trie<int> t1;
    pel_2324::my_trie<int> t2;

    {
        auto r1_pref_incr = test_const_iterators_pref_incr<trie<int>, int>(t1);
        auto r2_pref_incr =
            test_const_iterators_pref_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                        "ERROR in test 1 iterator with prefix increment.");

        auto r1_post_incr = test_const_iterators_post_incr<trie<int>, int>(t1);
        auto r2_post_incr =
            test_const_iterators_post_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                        "ERROR in test 1 iterator with postfix increment.");

        REQUIRE_MESSAGE(
            (r1_pref_incr == r1_post_incr) == true,
            "ERROR in test 1 iterator: weighted sequences are different.");
    }
    {
        auto r1_pref_incr = test_leaf_iterators_pref_incr<trie<int>, int>(t1);
        auto r2_pref_incr =
            test_leaf_iterators_pref_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                        "ERROR in test 1 iterator with prefix increment.");

        auto r1_post_incr = test_leaf_iterators_post_incr<trie<int>, int>(t1);
        auto r2_post_incr =
            test_leaf_iterators_post_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                        "ERROR in test 1 iterator with postfix increment.");

        REQUIRE_MESSAGE(
            (r1_pref_incr == r1_post_incr) == true,
            "ERROR in test 1 iterator: weighted sequences are different.");
    }
}

TEST_CASE("test 2 iterator") {
    trie<int> t1(3.4);
    pel_2324::my_trie<int> t2(3.4);

    {
        auto r1_pref_incr = test_const_iterators_pref_incr<trie<int>, int>(t1);
        auto r2_pref_incr =
            test_const_iterators_pref_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                        "ERROR in test 2 iterator with prefix increment.");

        auto r1_post_incr = test_const_iterators_post_incr<trie<int>, int>(t1);
        auto r2_post_incr =
            test_const_iterators_post_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                        "ERROR in test 2 iterator with postfix increment.");

        REQUIRE_MESSAGE(
            (r1_pref_incr == r1_post_incr) == true,
            "ERROR in test 2 iterator: weighted sequences are different.");
    }
    {
        auto r1_pref_incr = test_leaf_iterators_pref_incr<trie<int>, int>(t1);
        auto r2_pref_incr =
            test_leaf_iterators_pref_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                        "ERROR in test 2 iterator with prefix increment.");

        auto r1_post_incr = test_leaf_iterators_post_incr<trie<int>, int>(t1);
        auto r2_post_incr =
            test_leaf_iterators_post_incr<pel_2324::my_trie<int>, int>(t2);
        REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                        "ERROR in test 2 iterator with postfix increment.");

        REQUIRE_MESSAGE(
            (r1_pref_incr == r1_post_incr) == true,
            "ERROR in test 2 iterator: weighted sequences are different.");
    }
}

TEST_CASE("test 3 iterator") {
    try {
        /* Note: to be replaced with another private file. */
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
            auto r1_pref_incr =
                test_const_iterators_pref_incr<trie<char>, char>(t1);
            auto r2_pref_incr =
                test_const_iterators_pref_incr<pel_2324::my_trie<char>, char>(
                    t2);
            REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                            "ERROR in test 3 iterator with prefix increment.");

            auto r1_post_incr =
                test_const_iterators_post_incr<trie<char>, char>(t1);
            auto r2_post_incr =
                test_const_iterators_post_incr<pel_2324::my_trie<char>, char>(
                    t2);
            REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                            "ERROR in test 3 iterator with postfix increment.");

            REQUIRE_MESSAGE(
                (r1_pref_incr == r1_post_incr) == true,
                "ERROR in test 3 iterator: weighted sequences are different.");
        }
        {
            auto r1_pref_incr =
                test_leaf_iterators_pref_incr<trie<char>, char>(t1);
            auto r2_pref_incr =
                test_leaf_iterators_pref_incr<pel_2324::my_trie<char>, char>(
                    t2);
            REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                            "ERROR in test 3 iterator with prefix increment.");

            auto r1_post_incr =
                test_leaf_iterators_post_incr<trie<char>, char>(t1);
            auto r2_post_incr =
                test_leaf_iterators_post_incr<pel_2324::my_trie<char>, char>(
                    t2);
            REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                            "ERROR in test 3 iterator with postfix increment.");

            REQUIRE_MESSAGE(
                (r1_pref_incr == r1_post_incr) == true,
                "ERROR in test 3 iterator: weighted sequences are different.");
        }
    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}

TEST_CASE("test 4 iterator") {
    try {
        /* Note: to be replaced with another private file. */
        std::string path = "../test_data/trie_string.tr";
        trie<std::string> t1;
        pel_2324::my_trie<std::string> t2;
        {
            std::ifstream ifs(path);
            ifs >> t1;
        }
        {
            std::ifstream ifs(path);
            ifs >> t2;
        }

        {
            auto r1_pref_incr =
                test_const_iterators_pref_incr<trie<std::string>, std::string>(
                    t1);
            auto r2_pref_incr =
                test_const_iterators_pref_incr<pel_2324::my_trie<std::string>,
                                               std::string>(t2);
            REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                            "ERROR in test 4 iterator with prefix increment.");

            auto r1_post_incr =
                test_const_iterators_post_incr<trie<std::string>, std::string>(
                    t1);
            auto r2_post_incr =
                test_const_iterators_post_incr<pel_2324::my_trie<std::string>,
                                               std::string>(t2);
            REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                            "ERROR in test 4 iterator with postfix increment.");

            REQUIRE_MESSAGE(
                (r1_pref_incr == r1_post_incr) == true,
                "ERROR in test 4 iterator: weighted sequences are different.");
        }
        {
            auto r1_pref_incr =
                test_leaf_iterators_pref_incr<trie<std::string>, std::string>(
                    t1);
            auto r2_pref_incr =
                test_leaf_iterators_pref_incr<pel_2324::my_trie<std::string>,
                                              std::string>(t2);
            REQUIRE_MESSAGE((r1_pref_incr == r2_pref_incr) == true,
                            "ERROR in test 4 iterator with prefix increment.");

            auto r1_post_incr =
                test_leaf_iterators_post_incr<trie<std::string>, std::string>(
                    t1);
            auto r2_post_incr =
                test_leaf_iterators_post_incr<pel_2324::my_trie<std::string>,
                                              std::string>(t2);
            REQUIRE_MESSAGE((r1_post_incr == r2_post_incr) == true,
                            "ERROR in test 4 iterator with postfix increment.");

            REQUIRE_MESSAGE(
                (r1_pref_incr == r1_post_incr) == true,
                "ERROR in test 4 iterator: weighted sequences are different.");
        }

    } catch (parser_exception const& e) {
        REQUIRE_MESSAGE(false, "ERROR --> unexpected parser_exception thrown: "
                                   << e.what());
    }
}