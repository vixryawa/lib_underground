#pragma once
template <class T>
class TNode {
public:

    T Key;

    TNode(T key) :
        Key(key), Left(0), Right(0) {}

    TNode* Left;
    TNode* Right;
    bool rightThread = false;
    bool leftThread = false;
};