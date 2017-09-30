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

int boolean_expression::eval()
{
    return 0;
}

int numeric_expression::eval()
{
    return 0;
}

int logical_expression::eval()
{
    if (op == op_and)
        return lhs->eval() && rhs->eval();
    else if (op == op_or)
        return lhs->eval() || rhs->eval();
    else
        return -1; //Maybe throw exception here.
}

int relational_expression::eval()
{
    if (op == op_less_than)
        return lhs->eval() < rhs->eval();
    else if (op == op_greater_than)
        return lhs->eval() > rhs->eval();
    else if (op == op_equal)
        return lhs->eval() == rhs->eval();
    else
        return -1; //Maybe throw exception here.
}

int if_expression::eval()
{
    if(test->eval())
        return pass->eval();
    else
        return fail->eval();

}

int arithmetic_expression::eval()
{
    if(op == op_add)
        return lhs->eval() + rhs->eval();
    else if(op == op_subtract)
        return lhs->eval() - rhs->eval();
    else if(op == op_multiply)
        return lhs->eval() * rhs->eval();
    else if(op == op_divide)
        return lhs->eval() / rhs->eval();
    else if(op == op_remainder)
        return lhs->eval() % rhs->eval();
    else
        return -1; //Maybe throw exception here.
}

//Height functions
int height_arith(arithmetic_expression *e)
{
    return 1 + std::max(height(e->lhs), height(e->rhs));
}

int height_if(if_expression *e)
{
    return 1 + std::max({height(e->test), height(e->pass), height(e->fail)});
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

numeric_expression* pfold()
{
  return new numeric_expression(ek_int);
}

numeric_expression* nfold(numeric_expression* e)
{
  switch(e->kind)
  {
    case ek_int:
        return e;

    case ek_arg:
        return e;

    case ek_if:
        break;
    case ek_arith:
        arithmetic_expression *expr = static_cast<arithmetic_expression *>(e);
        switch(expr->op)
        {
            case op_add:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() + static_cast<integer *>(nfold(expr->rhs))->eval());
            case op_subtract:
            break;
            case op_divide:
            break;
            case op_multiply:
            break;
            case op_remainder:
            break;
        }
        
        
        break;

  }
  
  return e;
}

boolean_expression* bfold(boolean_expression* e)
{
    switch(e->kind)
    {
        case ek_bool:
        break;
        case ek_rel:
        break;
        case ek_logic:
        break;
    }

  return e;
}
