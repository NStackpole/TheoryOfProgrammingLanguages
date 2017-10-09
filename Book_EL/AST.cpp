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
    if (test->eval())
        return pass->eval();
    else
        return fail->eval();
}

int arithmetic_expression::eval()
{
    if (op == op_add)
        return lhs->eval() + rhs->eval();
    else if (op == op_subtract)
        return lhs->eval() - rhs->eval();
    else if (op == op_multiply)
        return lhs->eval() * rhs->eval();
    else if (op == op_divide)
        return lhs->eval() / rhs->eval();
    else if (op == op_remainder)
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

//folding functions
numeric_expression *pfold(program *p)
{
    return nfold(p->body);
}

numeric_expression *nfold(numeric_expression *e)
{
    switch (e->kind)
    {
    case ek_int:
        return e;

    case ek_arg:
        return e;

    case ek_if:
    {
        if_expression *expr = static_cast<if_expression *>(e);

        if (bfold(expr->test)->eval())
            return nfold(expr->pass);
        else
            return nfold(expr->fail);

        break;
    }
    case ek_arith:
    {
        arithmetic_expression *expr = static_cast<arithmetic_expression *>(e);
        switch (expr->op)
        {
        case op_add:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() + static_cast<integer *>(nfold(expr->rhs))->eval());
        case op_subtract:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() - static_cast<integer *>(nfold(expr->rhs))->eval());
        case op_divide:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() / static_cast<integer *>(nfold(expr->rhs))->eval());
        case op_multiply:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() * static_cast<integer *>(nfold(expr->rhs))->eval());
        case op_remainder:
            return new integer(static_cast<integer *>(nfold(expr->lhs))->eval() % static_cast<integer *>(nfold(expr->rhs))->eval());
        }

        break;
    }
    }

    return e;
}

boolean_expression *bfold(boolean_expression *e)
{
    switch (e->kind)
    {
    case ek_bool:
        return e;
    case ek_rel:
    {
        relational_expression *rel_expr = static_cast<relational_expression *>(e);
        switch (rel_expr->op)
        {
        case op_less_than:
            return new boolean(static_cast<integer *>(nfold(rel_expr->lhs))->eval() < static_cast<integer *>(nfold(rel_expr->rhs))->eval());
        case op_greater_than:
            return new boolean(static_cast<integer *>(nfold(rel_expr->lhs))->eval() > static_cast<integer *>(nfold(rel_expr->rhs))->eval());
        case op_equal:
            return new boolean(static_cast<integer *>(nfold(rel_expr->lhs))->eval() == static_cast<integer *>(nfold(rel_expr->rhs))->eval());
        }
        break;
    }
    case ek_logic:
    {
        logical_expression *logic_expr = static_cast<logical_expression *>(e);
        switch (logic_expr->op)
        {
        case op_and:
            return new boolean(static_cast<boolean *>(bfold(logic_expr->lhs))->eval() < static_cast<boolean *>(bfold(logic_expr->rhs))->eval());
        case op_or:
            return new boolean(static_cast<boolean *>(bfold(logic_expr->lhs))->eval() > static_cast<boolean *>(bfold(logic_expr->rhs))->eval());
        }
        break;
    }
    }

    return e;
}

//syntactic equality functions
bool neq(numeric_expression *e1, numeric_expression *e2)
{
    switch (e1->kind)
    {
    case ek_int:
    {
        if (e2->kind != ek_int)
        {
            return false;
        }
        else
        {
            return (e1->eval() == e2->eval());
        }

        return false;
    }

    case ek_arg:
    {
        if (e2->kind != ek_arg)
        {
            return false;
        }

        return false;
    }

    case ek_arith:
    {
        if (e2->kind != ek_arith)
        {
            return false;
        }

        arithmetic_expression *arith1 = static_cast<arithmetic_expression *>(e1);
        arithmetic_expression *arith2 = static_cast<arithmetic_expression *>(e2);

        if ((arith1->op == arith2->op) && neq(arith1->lhs, arith2->lhs))
        {
            return neq(arith1->rhs, arith2->rhs);
        }

        return false;
    }

    case ek_if:
    {
        if (e2->kind != ek_if)
        {
            return false;
        }

        if_expression *if_expr1 = static_cast<if_expression *>(e1);
        if_expression *if_expr2 = static_cast<if_expression *>(e2);

        if (beq(if_expr1->test, if_expr2->test) && neq(if_expr1->pass, if_expr2->pass))
        {
            return neq(if_expr1->fail, if_expr2->fail);
        }

        return false;
    }
    }

    return false;
}

bool beq(boolean_expression *e1, boolean_expression *e2)
{

    switch (e1->kind)
    {
    case ek_bool:
    {
        if (e2->kind != ek_bool)
            return false;
        else
            return e1->eval() == e2->eval();
    }

    case ek_logic:
    {
        if (e2->kind != ek_logic)
            return false;

        logical_expression *log_expr1 = static_cast<logical_expression *>(e1);
        logical_expression *log_expr2 = static_cast<logical_expression *>(e2);

        if ((log_expr1->op != log_expr2->op) && beq(log_expr1->rhs, log_expr2->rhs))
            return beq(log_expr1->lhs, log_expr2->lhs);
    }

    case ek_rel:
    {
        if (e2->kind != ek_rel)
            return false;

        relational_expression *rel_expr1 = static_cast<relational_expression *>(e1);
        relational_expression *rel_expr2 = static_cast<relational_expression *>(e2);

        if ((rel_expr1->op != rel_expr2->op) && neq(rel_expr1->rhs, rel_expr2->rhs))
            return neq(rel_expr1->lhs, rel_expr2->lhs);
    }
    }

    return false;
}
