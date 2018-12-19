//
// Created by gusef on 19.12.2018.
//

#include "tree_vertex.hpp"

vertex::vertex(int symbol, const std::array<int, 2>& link):
    _link(link),
    _symbol(symbol)
{
}

int vertex::get_symbol()
{
    return _symbol;
}

int vertex::get_next(int id)
{
    return _link.at(static_cast<unsigned int>(id));
}

void vertex::set_next(int id, int new_link)
{
    _link.at(static_cast<unsigned int>(id)) = new_link;
}
