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
    integer(int);
};

struct boolean : public expression
{
    bool value;
    boolean(bool);
};

struct addition_expr : public expression
{
    expression *e1;
    expression *e2;
};

struct subtraction_expr : public expression
{
    expression *e1;
    expression *e2;
};

struct multiplication_expr : public expression
{
    expression *e1;
    expression *e2;
};

struct division_expr : public expression
{
    expression *e1;
    expression *e2;
};

struct remainder_expr : public expression
{
    expression *e1;
    expression *e2;
};

#endif