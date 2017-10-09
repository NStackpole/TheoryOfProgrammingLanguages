//Nathan Stackpole, 2017
#include <iostream>
#include <algorithm>

#ifndef AST_HPP
#define AST_HPP

enum arithmetic_op
{
    op_add,
    op_subtract,
    op_multiply,
    op_divide,
    op_remainder
};

enum relational_op
{
    op_less_than,
    op_greater_than,
    op_equal
};

enum logical_operator
{
    op_and,
    op_or
};

enum numeric_expression_kind
{
    ek_int,
    ek_arg,
    ek_arith,
    ek_if
};

enum bool_expression_kind
{
    ek_bool,
    ek_rel,
    ek_logic
};

struct program;
struct numeric_expression;
struct boolean_expression;

struct program
{
    program(int n, numeric_expression *e);

    int args;
    numeric_expression *body;
};

struct numeric_expression
{
    numeric_expression(numeric_expression_kind k);
    virtual int eval();

    numeric_expression_kind kind;
};

struct boolean_expression
{
    boolean_expression(bool_expression_kind k);
    virtual int eval();

    bool_expression_kind kind;
};

struct arithmetic_expression : numeric_expression
{
    arithmetic_expression(arithmetic_op, numeric_expression *, numeric_expression *);
    int eval();

    arithmetic_op op;
    numeric_expression *lhs;
    numeric_expression *rhs;
};

struct argument_expression : numeric_expression
{
    argument_expression(int);

    int arg;
};

struct if_expression : numeric_expression
{
    if_expression(boolean_expression *, numeric_expression *, numeric_expression *);
    int eval();

    boolean_expression *test;
    numeric_expression *pass;
    numeric_expression *fail;
};

struct relational_expression : boolean_expression
{
    relational_expression(relational_op, numeric_expression *, numeric_expression *);
    int eval();

    relational_op op;
    numeric_expression *lhs;
    numeric_expression *rhs;
};

struct logical_expression : boolean_expression
{
    logical_expression(logical_operator, boolean_expression *, boolean_expression *);
    int eval();

    logical_operator op;
    boolean_expression *lhs;
    boolean_expression *rhs;
};

struct integer : numeric_expression
{
    int value;
    int eval();
    integer(int);
};

struct boolean : boolean_expression
{
    bool value;
    int eval();
    boolean(bool);
};

//height
int height(numeric_expression *);
int height(boolean_expression *);

//printing
void print(numeric_expression *e);
void print(boolean_expression *e);
void print_type(numeric_expression *e);
void print_type(boolean_expression *e);

//folding
numeric_expression *pfold(program *p);
numeric_expression *nfold(numeric_expression *e);
boolean_expression *bfold(boolean_expression *e);

//syntactic equality
bool neq(numeric_expression *, numeric_expression *);
bool beq(boolean_expression *, boolean_expression *);

#endif