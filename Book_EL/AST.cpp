//Nathan Stackpole, 2017
#include "AST.hpp"

//Constructors
program::program(int n, numeric_expression *e) : args(n), body(e)
{
}

numeric_expression::numeric_expression(numeric_expression_kind k) : kind(k)
{
}

boolean_expression::boolean_expression(bool_expression_kind k) : kind(k)
{
}

arithmetic_expression::arithmetic_expression(arithmetic_op oper, numeric_expression *left, numeric_expression *right) : numeric_expression(ek_arith), op(oper), lhs(left), rhs(right)
{
}

argument_expression::argument_expression(int n) : numeric_expression(ek_arg), arg(n)
{
}

if_expression::if_expression(boolean_expression *tst, numeric_expression *ps, numeric_expression *fl) : numeric_expression(ek_if), test(tst), pass(ps), fail(fl)
{
}

relational_expression::relational_expression(relational_op oper, numeric_expression *e1, numeric_expression *e2) : boolean_expression(ek_bool), op(oper), lhs(e1), rhs(e2)
{
}

logical_expression::logical_expression(logical_operator oper, boolean_expression *e1, boolean_expression *e2) : boolean_expression(ek_bool), op(oper), lhs(e1), rhs(e2)
{
}

integer::integer(int val) : numeric_expression(ek_int), value(val)
{
}

boolean::boolean(bool val) : boolean_expression(ek_bool), value(val)
{
}

//eval: evaluates the expression
int integer::eval()
{
    return value;
}