#include "AST.hpp"

int main()
{
    std::cout << "Hello.\n";

    //logical_expression tests ----------------------------------------------------------------------------------
    {
        logical_expression *logical_test = new logical_expression(op_and, new boolean(true), new boolean(false));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    {
        logical_expression *logical_test = new logical_expression(op_and, new boolean(true), new boolean(true));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    {
        logical_expression *logical_test = new logical_expression(op_and, new boolean(false), new boolean(false));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    {
        logical_expression *logical_test = new logical_expression(op_or, new boolean(true), new boolean(false));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    {
        logical_expression *logical_test = new logical_expression(op_or, new boolean(true), new boolean(true));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    {
        logical_expression *logical_test = new logical_expression(op_or, new boolean(false), new boolean(false));
        print(logical_test);
        std::cout << " = " << logical_test->eval() << "\n";
    }

    //relational_expression tests ----------------------------------------------------------------------------------
    {
        relational_expression *relation_test = new relational_expression(op_less_than, new integer(10), new integer(20));
        print(relation_test);
        std::cout << " = " << relation_test->eval() << "\n";
    }

    {
        relational_expression *relation_test = new relational_expression(op_less_than, new integer(100), new integer(20));
        print(relation_test);
        std::cout << " = " << relation_test->eval() << "\n";
    }

    {
        relational_expression *relation_test = new relational_expression(op_greater_than, new integer(100), new integer(20));
        print(relation_test);
        std::cout << " = " << relation_test->eval() << "\n";
    }

    {
        relational_expression *relation_test = new relational_expression(op_greater_than, new integer(10), new integer(20));
        print(relation_test);
        std::cout << " = " << relation_test->eval() << "\n";
    }

    //arithemtic_expression tests ----------------------------------------------------------------------------------
    {
        arithmetic_expression *arithmetic_test = new arithmetic_expression(op_add, new integer(200), new integer(10));
        print(arithmetic_test);
        std::cout << " = " << arithmetic_test->eval() << "\n";
    }

    {
        arithmetic_expression *arithmetic_test = new arithmetic_expression(op_subtract, new integer(200), new integer(10));
        print(arithmetic_test);
        std::cout << " = " << arithmetic_test->eval() << "\n";
    }

    {
        arithmetic_expression *arithmetic_test = new arithmetic_expression(op_multiply, new integer(200), new integer(10));
        print(arithmetic_test);
        std::cout << " = " << arithmetic_test->eval() << "\n";
    }

    {
        arithmetic_expression *arithmetic_test = new arithmetic_expression(op_divide, new integer(200), new integer(10));
        print(arithmetic_test);
        std::cout << " = " << arithmetic_test->eval() << "\n";
    }

    {
        arithmetic_expression *arithmetic_test = new arithmetic_expression(op_remainder, new integer(200), new integer(10));
        print(arithmetic_test);
        std::cout << " = " << arithmetic_test->eval() << "\n";
    }

    //if_expressions tests ----------------------------------------------------------------------------------
    {
        relational_expression *relation_test = new relational_expression(op_less_than, new integer(100), new integer(20));

        if_expression *if_test = new if_expression(relation_test, new arithmetic_expression(op_add, new integer(20), new integer(30)), new arithmetic_expression(op_add, new integer(200), new integer(30)));

        print(if_test);
        std::cout << " = " << if_test->eval() << "\n";
    }

    {
        relational_expression *relation_test = new relational_expression(op_greater_than, new integer(100), new integer(20));

        if_expression *if_test = new if_expression(relation_test, new arithmetic_expression(op_add, new integer(20), new integer(30)), new arithmetic_expression(op_add, new integer(200), new integer(30)));

        print(if_test);
        std::cout << " = " << if_test->eval() << "\n";
    }

    //folding tests ----------------------------------------------------------------------------------
    {
        program *test = new program(0, new arithmetic_expression(op_add, new integer(10), new integer(50)));

        //Comes back with and prints an integer instead of an arithmetic expression.
        numeric_expression *test_expr = pfold(test);
        print_type(test_expr);
        std::cout << " -> ";
        print(test_expr);
        std::cout << "\n";
    }

    {
        program *test = new program(0, new arithmetic_expression(op_subtract, new integer(10), new integer(50)));

        //Comes back with and prints an integer instead of an arithmetic expression.
        numeric_expression *test_expr = pfold(test);
        print_type(test_expr);
        std::cout << " -> ";
        print(test_expr);
        std::cout << "\n";
    }

    {
        program *test = new program(0, new arithmetic_expression(op_divide, new integer(10), new integer(50)));

        //Comes back with and prints an integer instead of an arithmetic expression.
        numeric_expression *test_expr = pfold(test);
        print_type(test_expr);
        std::cout << " -> ";
        print(test_expr);
        std::cout << "\n";
    }

    {
        program *test = new program(0, new arithmetic_expression(op_multiply, new integer(10), new integer(50)));

        //Comes back with and prints an integer instead of an arithmetic expression.
        numeric_expression *test_expr = pfold(test);
        print_type(test_expr);
        std::cout << " -> ";
        print(test_expr);
        std::cout << "\n";
    }

    {
        program *test = new program(0, new arithmetic_expression(op_remainder, new integer(10), new integer(50)));

        //Comes back with and prints an integer instead of an arithmetic expression.
        numeric_expression *test_expr = pfold(test);
        print_type(test_expr);
        std::cout << " -> ";
        print(test_expr);
        std::cout << "\n";
    }

    //syntactic equality tests
    {
        arithmetic_expression *test1 = new arithmetic_expression(op_add, new integer(10), new integer(20));
        arithmetic_expression *test2 = new arithmetic_expression(op_add, new integer(10), new integer(20));
        std::cout << neq(test1, test2) << "\n";
    }

    {
        arithmetic_expression *test1 = new arithmetic_expression(op_subtract, new integer(10), new integer(20));
        arithmetic_expression *test2 = new arithmetic_expression(op_add, new integer(10), new integer(20));
        std::cout << neq(test1, test2) << "\n";
    }

    return 0;
}