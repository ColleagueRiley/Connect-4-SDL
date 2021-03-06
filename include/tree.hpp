#include <iostream>
#include <vector>

struct Node{
    int value;
    std::vector<Node*> children;
};