#include "AST.hpp"

void print_integer(integer *e)
{
    std::cout << e->eval();
}

void print_boolean(boolean *e)
{
    std::cout << e->eval();
}

void print_arg(argument_expression *e)
{
    std::cout << "(arg " << e->arg << ")";
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

void print_logical(logical_expression *e)
{
    switch (e->op)
    {
    case op_and:
        std::cout << "(";
        print(e->lhs);
        std::cout << " and ";
        print(e->rhs);
        std::cout << ")";
        break;
    case op_or:
        std::cout << "(";
        print(e->lhs);
        std::cout << " or ";
        print(e->rhs);
        std::cout << ")";
        break;
    }
}

void print_relational(relational_expression *e)
{
    switch (e->op)
    {
    case op_less_than:
        std::cout << "(";
        print(e->lhs);
        std::cout << " < ";
        print(e->rhs);
        std::cout << ")";
        break;
    case op_greater_than:
        std::cout << "(";
        print(e->lhs);
        std::cout << " > ";
        print(e->rhs);
        std::cout << ")";
        break;
    case op_equal:
        std::cout << "(";
        print(e->lhs);
        std::cout << " == ";
        print(e->rhs);
        std::cout << ")";
        break;
    }
}

void print_if(if_expression *e)
{
    std::cout << "(if ";
    print(e->test);
    std::cout << " then ";
    print(e->pass);
    std::cout << " else ";
    print(e->fail);
    std::cout << ")";
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
        return print_relational(static_cast<relational_expression *>(e));
    case ek_logic:
        return print_logical(static_cast<logical_expression *>(e));
    }
}

void print_type(numeric_expression *e)
{
    switch (e->kind)
    {
    case ek_arith:
        std::cout << "arithmetic expression";
        break;
    case ek_int:
        std::cout << "integer literal";
        break;
    case ek_if:
        std::cout << "if expression";
        break;
    case ek_arg:
        std::cout << "argument expression";
        break;
    }
}

void print_type(boolean_expression *e)
{
    switch (e->kind)
    {
    case ek_bool:
        std::cout << "boolean literal";
        break;
    case ek_rel:
        std::cout << "relational expression";
        break;
    case ek_logic:
        std::cout << "logic expression";
        break;
    }
}
