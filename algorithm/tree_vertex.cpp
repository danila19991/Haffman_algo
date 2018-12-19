//
// Created by gusef on 19.12.2018.
//

#include "tree_vertex.hpp"

vertex::vertex(int symbol):
    _link({-1,-1}),
    _symbol(symbol)
{
}

vertex::vertex(const std::array<int, 2>& link):
    _link(link),
    _symbol(-1)
{
}

int vertex::get_symbol() const
{
    return _symbol;
}

int vertex::get_next(int id) const
{
    return _link.at(static_cast<unsigned int>(id));
}

void vertex::set_next(int id, int new_link)
{
    _link.at(static_cast<unsigned int>(id)) = new_link;
}

vertex::vertex():
    _link{-1, -1},
    _symbol(-1)
{

}

bool operator <(const vertex& l, const vertex& r)
{
    return l.get_symbol() < r.get_symbol();
}
