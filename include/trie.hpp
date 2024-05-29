#include <iostream>
#include <cassert>

#include "bag.hpp"  // file with the implementation of your container bag<Val>

#include <vector>

struct parser_exception {
    parser_exception(std::string const& str) : m_str(str) {}

    std::string what() const { return m_str; }

private:
    std::string m_str;
};

template <typename T>
struct trie {
    /* node iterators */
    struct node_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        node_iterator(trie<T>*);
        reference operator*() const;
        pointer operator->() const;
        node_iterator& operator++();
        node_iterator operator++(int);
        bool operator==(node_iterator const&) const;
        bool operator!=(node_iterator const&) const;

    private:
        trie<T>* m_ptr;
    };
    struct const_node_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = const T;
        using pointer = T const*;
        using reference = T const&;

        const_node_iterator(trie<T> const* ptr);
        reference operator*() const;
        pointer operator->() const;
        const_node_iterator& operator++();
        const_node_iterator operator++(int);
        bool operator==(const_node_iterator const&) const;
        bool operator!=(const_node_iterator const&) const;

    private:
        trie<T> const* m_ptr;
    };

    /* leaf iterators */
    struct leaf_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        leaf_iterator(trie<T>*);
        reference operator*() const;
        pointer operator->() const;
        leaf_iterator& operator++();
        leaf_iterator operator++(int);
        bool operator==(leaf_iterator const&) const;
        bool operator!=(leaf_iterator const&) const;
        operator node_iterator() const;

        trie<T>& get_leaf() const;

    private:
        trie<T>* m_ptr;
    };
    struct const_leaf_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = const T;
        using pointer = T const*;
        using reference = T const&;

        const_leaf_iterator(trie<T> const* ptr);
        reference operator*() const;
        pointer operator->() const;
        const_leaf_iterator& operator++();
        const_leaf_iterator operator++(int);
        bool operator==(const_leaf_iterator const&) const;
        bool operator!=(const_leaf_iterator const&) const;
        operator const_node_iterator() const;

        trie<T> const& get_leaf() const;

    private:
        trie<T> const* m_ptr;
    };

    /* constructors */
    trie();
    trie(double);
    trie(trie<T> const&);
    trie(trie<T>&&);

    /* destructor */
    ~trie();

    /* assignment operators */
    trie<T>& operator=(trie<T> const&);
    trie<T>& operator=(trie<T>&&);

    /* setters */
    void set_weight(double w);
    void set_label(T* l);
    void set_parent(trie<T>* p);
    void add_child(trie<T> const& c);

    /* getters */
    double get_weight() const;
    T const* get_label() const;
    trie<T> const* get_parent() const;
    bag<trie<T>> const& get_children() const;
    T* get_label();
    trie<T>* get_parent();
    bag<trie<T>>& get_children();

    /* comparison */
    bool operator==(trie<T> const&) const;
    bool operator!=(trie<T> const&) const;

    /* prefix-search */
    trie<T>& operator[](std::vector<T> const&);
    trie<T> const& operator[](std::vector<T> const&) const;

    /* max-weight leaf */
    trie<T>& max();
    trie<T> const& max() const;

    /* methods to return iterators */
    leaf_iterator begin();
    leaf_iterator end();
    node_iterator root();
    const_leaf_iterator begin() const;
    const_leaf_iterator end() const;
    const_node_iterator root() const;

    /* facultative: union */
    trie<T> operator+(trie<T> const&) const;
    trie<T>& operator+=(trie<T> const&);

    /* facultative: path compression */
    void path_compress();

private:
    trie<T>* m_p;      // parent
    T* m_l;            // label
    bag<trie<T>> m_c;  // children
    double m_w;        // weight
};

template <typename T>
std::ostream& operator<<(std::ostream&, trie<T> const&);

template <typename T>
std::istream& operator>>(std::istream&, trie<T>&);
