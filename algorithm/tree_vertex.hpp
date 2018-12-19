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

    /**
     * \brief   Symbol which associated with this vertex.
     * \details If symbol equals -1 - means this there is no symbol
     *          associated with this vertex.
     */
    int _symbol;

public:
    /**
     * \brief               Constructor of vertex.
     * \param[in] link      Array of initial links.
     * \param[in] symbol    Associated symbol.
     */
    explicit vertex(const std::array<int, 2>& link = {0,0}, int symbol = -1);

    /**
     * \brief   Getter for symbol.
     * \return  Value of symbol.
     */
    int get_symbol();

    /**
     * \brief           Getter for link.
     * \param[in] id    Id of link.
     * \return          Number of child element for this link.
     */
    int get_next(int id);

    /**
     * \brief               Setter for link.
     * \param[in] id        Id of setting link.
     * \param[in] new_link  New number of child link.
     */
    void set_next(int id, int new_link);
};

#endif //HAFFMAN_TREE_VERTEX_HPP
