//Nathan Stackpole, 2017
#include "AST.hpp"

//Constructors
program::program(int n, numeric_expression* e) : args(n), body(e)
{}

numeric_expression::numeric_expression(numeric_expression_kind k) : kind(k)
{}

boolean_expression::boolean_expression(bool_expression_kind k) : kind(k)
{}

arithmetic_expression::arithmetic_expression(arithmetic_op oper, numeric_expression* left, numeric_expression* right) : numeric_expression(ek_arith), op(oper), lhs(left), rhs(right)
{}

argument_expression::argument_expression(int n) : numeric_expression(ek_arg), arg(n)
{}

integer::integer(int val) : numeric_expression(ek_int), value(val)
{}

boolean::boolean(bool val) : boolean_expression(ek_bool), value(val)
{}

//eval: evaluates the expression
int integer::eval()
{
    return value;
}