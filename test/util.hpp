#pragma once

#include <random>
#include <ctime>

double get_random_double() {
    std::uniform_real_distribution<double> distr(-10000, 10000);
    std::default_random_engine gen(time(0));  // randomize
    return distr(gen);
}

template <typename TrieType1, typename TrieType2>
bool operator==(TrieType1 const& t1, TrieType2 const& t2) {
    if (t1.get_weight() == t2.get_weight()) {
        auto const& children_t1 = t1.get_children();
        auto const& children_t2 = t2.get_children();
        auto it1 = children_t1.begin();
        auto it2 = children_t2.begin();
        while (it1 != children_t1.end() and it2 != children_t2.end())  //
        {
            // check labels
            auto l1 = (*it1).get_label();
            auto l2 = (*it2).get_label();
            if (!l1 or !l2 or *l1 != *l2) return false;

            if (!(*it1 == *it2)) return false;  // check children recursively

            ++it1;
            ++it2;
        }
        if (it1 != children_t1.end() or it2 != children_t2.end()) return false;
        return true;
    }
    return false;
}
