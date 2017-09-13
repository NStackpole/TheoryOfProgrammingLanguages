#include "AST.hpp"

void print_integer(integer *e)
{
    std::cout << e->eval();
}

void print_boolean(boolean *e)
{
    std::cout << e->eval();
}

void print(arithmetic_op op)
{
    switch (op)
    {
    case op_add:
        std::cout << "+";
        break;
    case op_subtract:
        std::cout << "-";
        break;
    case op_multiply:
        std::cout << "*";
        break;
    case op_divide:
        std::cout << "/";
        break;
    case op_remainder:
        std::cout << "%";
        break;
    }
}

void print_arith(arithmetic_expression *e)
{
    std::cout << "(";
    print(e->lhs);
    std::cout << " ";
    print(e->op);
    std::cout << " ";
    print(e->rhs);
    std::cout << ")";
}

void print_if(if_expression *e)
{
}

void print(numeric_expression *e)
{
    switch (e->kind)
    {
    case ek_arith:
        return print_arith(static_cast<arithmetic_expression *>(e));
    case ek_int:
        return print_integer(static_cast<integer *>(e));
    case ek_if:
        return print_if(static_cast<if_expression *>(e));
    case ek_arg:
        break;
    }
}

void print(boolean_expression *e)
{
    switch (e->kind)
    {
    case ek_bool:
        return print_boolean(static_cast<boolean *>(e));
    case ek_rel:
        break;
    case ek_logic:
        break;
    }
}