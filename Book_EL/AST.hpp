//Nathan Stackpole, 2017
#include <iostream>

#ifndef AST_HPP
#define AST_HPP

struct expression
{

};

struct integer : public expression
{
    int value;
};

struct boolean : public expression
{
    bool value;
};

#endif