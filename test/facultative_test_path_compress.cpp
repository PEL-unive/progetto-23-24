#include <iostream>

#include "util.hpp"
#include "trie.cpp"
#include "my_trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("test 1 path_compress") {
    const double w = get_random_double();
    trie<char> x(w);
    x.path_compress();
    pel_2324::my_trie<char> x_(w);
    x_.path_compress();
    bool equal = x == x_;
    REQUIRE_MESSAGE(equal,
                    "ERROR in test 1 path_compress: tries are not equal.");
}

TEST_CASE("test 2 path_compress") {
    std::string path = "../test_data/trie_char3.tr";

    trie<char> x;
    {
        std::ifstream ifs(path);
        ifs >> x;
    }
    x.path_compress();

    pel_2324::my_trie<char> x_;
    {
        std::ifstream ifs(path);
        ifs >> x_;
    }
    x_.path_compress();

    bool equal = x == x_;
    REQUIRE_MESSAGE(equal,
                    "ERROR in test 2 path_compress: tries are not equal.");
}

TEST_CASE("test 3 path_compress") {
    std::string path = "../test_data/trie_char1.tr";

    trie<char> x;
    {
        std::ifstream ifs(path);
        ifs >> x;
    }
    x.path_compress();

    pel_2324::my_trie<char> x_;
    {
        std::ifstream ifs(path);
        ifs >> x_;
    }
    x_.path_compress();

    bool equal = x == x_;
    REQUIRE_MESSAGE(equal,
                    "ERROR in test 3 path_compress: tries are not equal.");
}

TEST_CASE("test 4 path_compress") {
    std::string path = "../test_data/trie_string_fig6.tr";

    trie<std::string> x;
    {
        std::ifstream ifs(path);
        ifs >> x;
    }
    x.path_compress();

    pel_2324::my_trie<std::string> x_;
    {
        std::ifstream ifs(path);
        ifs >> x_;
    }
    x_.path_compress();

    bool equal = x == x_;
    REQUIRE_MESSAGE(equal,
                    "ERROR in test 4 path_compress: tries are not equal.");
}

TEST_CASE("test 5 path_compress") {
    std::string path = "../test_data/trie_int_fig11.tr";

    trie<int> x;
    {
        std::ifstream ifs(path);
        ifs >> x;
    }
    x.path_compress();

    pel_2324::my_trie<int> x_;
    {
        std::ifstream ifs(path);
        ifs >> x_;
    }
    x_.path_compress();

    bool equal = x == x_;
    REQUIRE_MESSAGE(equal,
                    "ERROR in test 5 path_compress: tries are not equal.");
}

// TEST_CASE("test 6 path_compress") {
//     std::string path = "../test_data/trie_int.tr";

//     trie<int> x;
//     {
//         std::ifstream ifs(path);
//         ifs >> x;
//     }
//     x.path_compress();

//     pel_2324::my_trie<int> x_;
//     {
//         std::ifstream ifs(path);
//         ifs >> x_;
//     }
//     std::cout << x_ << std::endl;
//     x_.path_compress();
//     std::cout << x_ << std::endl;
//     bool equal = x == x_;
//     REQUIRE_MESSAGE(equal,
//                     "ERROR in test 6 path_compress: tries are not equal.");
// }

// TEST_CASE("test 7 path_compress") {
//     std::string path = "../test_data/trie_string2.tr";

//     trie<std::string> x;
//     {
//         std::ifstream ifs(path);
//         ifs >> x;
//     }
//     x.path_compress();

//     pel_2324::my_trie<std::string> x_;
//     {
//         std::ifstream ifs(path);
//         ifs >> x_;
//     }
//     std::cout << x_ << std::endl;
//     x_.path_compress();
//     std::cout << x_ << std::endl;
//     bool equal = x == x_;
//     REQUIRE_MESSAGE(equal,
//                     "ERROR in test 7 path_compress: tries are not equal.");
// }

// TEST_CASE("test 8 path_compress") {
//     std::string path = "../test_data/trie_int2.tr";

//     trie<int> x;
//     {
//         std::ifstream ifs(path);
//         ifs >> x;
//     }
//     x.path_compress();

//     pel_2324::my_trie<int> x_;
//     {
//         std::ifstream ifs(path);
//         ifs >> x_;
//     }
//     std::cout << x_ << std::endl;
//     x_.path_compress();
//     std::cout << x_ << std::endl;
//     bool equal = x == x_;
//     REQUIRE_MESSAGE(equal,
//                     "ERROR in test 6 path_compress: tries are not equal.");
// }
