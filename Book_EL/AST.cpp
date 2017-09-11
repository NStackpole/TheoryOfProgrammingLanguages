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

relational_expression::relational_expression(relational_op oper, numeric_expression *e1, numeric_expression *e2) : boolean_expression(ek_rel), op(oper), lhs(e1), rhs(e2)
{
}

logical_expression::logical_expression(logical_operator oper, boolean_expression *e1, boolean_expression *e2) : boolean_expression(ek_logic), op(oper), lhs(e1), rhs(e2)
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

int boolean::eval()
{
    return value;
}

int height_arith(arithmetic_expression *e)
{
    return 1 + std::max(height(e->lhs), height(e->rhs));
}

int height_if(if_expression *e)
{
    return 1 + std::max(height(e->test), std::max(height(e->pass), height(e->fail)));
}

int height_logic(logical_expression *e)
{
    return 1 + std::max(height(e->lhs), height(e->rhs));
}

int height_rel(relational_expression *e)
{
    return 1 + std::max(height(e->lhs), height(e->rhs));
}

int height_int(integer *n)
{
    return 0;
}

int height_bool(boolean *b)
{
    return 0;
}

int height_arg(argument_expression *e)
{
    return 0;
}

int height(numeric_expression *e)
{
    switch (e->kind)
    {
    case ek_int:
        return height_int(static_cast<integer *>(e));
    case ek_arg:
        return height_arg(static_cast<argument_expression *>(e));
    case ek_arith:
        return height_arith(static_cast<arithmetic_expression *>(e));
    case ek_if:
        return height_if(static_cast<if_expression *>(e));
    }
}

int height(boolean_expression *e)
{
    switch (e->kind)
    {
    case ek_bool:
        return height_bool(static_cast<boolean *>(e));
    case ek_rel:
        return height_rel(static_cast<relational_expression *>(e));
    case ek_logic:
        return height_logic(static_cast<logical_expression *>(e));
    }
}
