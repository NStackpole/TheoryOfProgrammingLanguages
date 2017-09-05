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
    addition_expr(expression, expression);
};

struct subtraction_expr : public expression
{
    expression *e1;
    expression *e2;
    subtraction_expr(expression, expression);
};

struct multiplication_expr : public expression
{
    expression *e1;
    expression *e2;
    multiplication_expr(expression, expression);
};

struct division_expr : public expression
{
    expression *e1;
    expression *e2;
    division_expr(expression, expression);
};

struct remainder_expr : public expression
{
    expression *e1;
    expression *e2;
    remainder_expr(expression, expression);
};

#endif