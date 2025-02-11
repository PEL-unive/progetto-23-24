#include <iostream>

#include "util.hpp"
#include "trie.cpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest/doctest.h"

TEST_CASE("weight") {
    trie<int> t;
    CHECK(t.get_weight() == 0.0);
    const double w = get_random_double();
    t.set_weight(w);
    CHECK(t.get_weight() == w);
}

TEST_CASE("label") {
    trie<int> t;
    CHECK(t.get_label() == nullptr);
    int label = static_cast<int>(get_random_double());
    t.set_label(&label);
    CHECK(*(t.get_label()) == label);
}

TEST_CASE("parent") {
    const double w = get_random_double();
    trie<char> parent;
    trie<char> child(w);
    char l = 'z';
    child.set_label(&l);
    child.set_parent(&parent);
    parent.add_child(child);
    trie<char> const* p = child.get_parent();
    CHECK(p->get_label() == nullptr);
    CHECK(p->get_parent() == nullptr);
    CHECK(child.get_weight() == w);
}