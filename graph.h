#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct vertex
{
    vertex(int v,set<int> &a) : vertex_number(v), adjacents(a){}
    int vertex_number;
    set<int> adjacents;
};
class graph
{
public:
    graph(vector<vertex> &v): v_(v) {}
    vector<vertex> v_;
};
