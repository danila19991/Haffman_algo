//
// Created by gusef on 19.12.2018.
//

#ifndef HAFFMAN_TREE_VERTEX_HPP
#define HAFFMAN_TREE_VERTEX_HPP

#include <array>

/**
 * \brief Vertex for huffman tree.
 */
class vertex{
    /**
     * \brief Vertex links.
     */
    std::array<int, 2> _link;
public:
    /**
     * \brief   Symbol which associated with this vertex.
     * \details If symbol equals -1 - means this there is no symbol
     *          associated with this vertex.
     */
    int _symbol;


    /**
     * \brief               Constructor of vertex.
     * \param[in] symbol    Associated symbol.
     * \param[in] link      Array of initial links.
     */
    explicit vertex(int symbol);

    /**
     * \brief               Constructor of vertex.
     * \param[in] link      Array of initial links.
     */
    explicit vertex(const std::array<int, 2>& link);

    /**
     * \brief Default constructor.
     */
    vertex();

    /**
     * \brief   Getter for symbol.
     * \return  Value of symbol.
     */
    int get_symbol() const;

    /**
     * \brief           Getter for link.
     * \param[in] id    Id of link.
     * \return          Number of child element for this link.
     */
    int get_next(int id) const;

    /**
     * \brief               Setter for link.
     * \param[in] id        Id of setting link.
     * \param[in] new_link  New number of child link.
     */
    void set_next(int id, int new_link);
};

bool operator < (const vertex& l, const vertex& r);

#endif //HAFFMAN_TREE_VERTEX_HPP
