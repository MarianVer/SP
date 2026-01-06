

#define COMMENT_BEGIN_STR "??"
#define COMMENT_END_STR   "??"

/* Tokens: ->, <, >, (, ), {, }, [, ], ,, ;, identifiers (_AB), keywords/operators (ADD, PROGRAM...) */
#define TOKENS_RE         "->|<|>|\\(|\\)|\\{|\\}|\\[|\\]|,|;|_[A-Z][A-Z]|[_0-9A-Za-z]+|[^ \t\r\f\v\n]"

/* Keywords list for Regex check */
#define KEYWORDS_RE       "->|<|>|\\(|\\)|\\{|\\}|\\[|\\]|,|;|PROGRAM|VAR|BEGIN|END|SCAN|PRINT|IF|ELSE|WHILE|FOR|DOWNTO|DO|REPEAT|UNTIL|CONTINUE|BREAK|EXIT|LONG|INT|ADD|SUB|MUL|DIV|MOD|NOT|AND|OR|EQ|NE"

/* Identifier: Underscore + 2 Uppercase letters */
#define IDENTIFIERS_RE    "_[A-Z][A-Z]"

/* Unsigned Values: 0 or 1-9 followed by digits */
#define UNSIGNEDVALUES_RE "0|[1-9][0-9]*"

/* --- Token Definitions --- */

#define T_BEGIN_GROUPEXPRESSION_0 "("
#define T_BEGIN_GROUPEXPRESSION_1 ""
#define T_BEGIN_GROUPEXPRESSION_2 ""
#define T_BEGIN_GROUPEXPRESSION_3 ""
#define T_END_GROUPEXPRESSION_0 ")"
#define T_END_GROUPEXPRESSION_1 ""
#define T_END_GROUPEXPRESSION_2 ""
#define T_END_GROUPEXPRESSION_3 ""
#define T_LEFT_SQUAREBRACKETS_0 "["
#define T_LEFT_SQUAREBRACKETS_1 ""
#define T_LEFT_SQUAREBRACKETS_2 ""
#define T_LEFT_SQUAREBRACKETS_3 ""
#define T_RIGHT_SQUAREBRACKETS_0 "]"
#define T_RIGHT_SQUAREBRACKETS_1 ""
#define T_RIGHT_SQUAREBRACKETS_2 ""
#define T_RIGHT_SQUAREBRACKETS_3 ""
#define T_BEGIN_BLOCK_0 "{"
#define T_BEGIN_BLOCK_1 ""
#define T_BEGIN_BLOCK_2 ""
#define T_BEGIN_BLOCK_3 ""
#define T_END_BLOCK_0 "}"
#define T_END_BLOCK_1 ""
#define T_END_BLOCK_2 ""
#define T_END_BLOCK_3 ""
#define T_SEMICOLON_0 ";"
#define T_SEMICOLON_1 ""
#define T_SEMICOLON_2 ""
#define T_SEMICOLON_3 ""

/* Data Type: LONG INT */
#define T_DATA_TYPE_0 "LONG"
#define T_DATA_TYPE_1 "INT"
#define T_DATA_TYPE_2 ""
#define T_DATA_TYPE_3 ""

#define T_COMA_0 ","
#define T_COMA_1 ""
#define T_COMA_2 ""
#define T_COMA_3 ""

/* Operators */
#define T_NOT_0 "NOT"
#define T_NOT_1 ""
#define T_NOT_2 ""
#define T_NOT_3 ""

#define T_AND_0 "AND"
#define T_AND_1 ""
#define T_AND_2 ""
#define T_AND_3 ""

#define T_OR_0 "OR"
#define T_OR_1 ""
#define T_OR_2 ""
#define T_OR_3 ""

#define T_EQUAL_0 "EQ"
#define T_EQUAL_1 ""
#define T_EQUAL_2 ""
#define T_EQUAL_3 ""

#define T_NOT_EQUAL_0 "NE"
#define T_NOT_EQUAL_1 ""
#define T_NOT_EQUAL_2 ""
#define T_NOT_EQUAL_3 ""

/* Le -> <, Ge -> > */
#define T_LESS_0 "<"
#define T_LESS_1 ""
#define T_LESS_2 ""
#define T_LESS_3 ""

#define T_GREATER_0 ">"
#define T_GREATER_1 ""
#define T_GREATER_2 ""
#define T_GREATER_3 ""

#define T_ADD_0 "ADD"
#define T_ADD_1 ""
#define T_ADD_2 ""
#define T_ADD_3 ""

#define T_SUB_0 "SUB"
#define T_SUB_1 ""
#define T_SUB_2 ""
#define T_SUB_3 ""

#define T_MUL_0 "MUL"
#define T_MUL_1 ""
#define T_MUL_2 ""
#define T_MUL_3 ""

#define T_DIV_0 "DIV"
#define T_DIV_1 ""
#define T_DIV_2 ""
#define T_DIV_3 ""

#define T_MOD_0 "MOD"
#define T_MOD_1 ""
#define T_MOD_2 ""
#define T_MOD_3 ""

#define T_LRASSIGN_0 "->"
#define T_LRASSIGN_1 ""
#define T_LRASSIGN_2 ""
#define T_LRASSIGN_3 ""

/* Keywords */
#define T_IF_0 "IF"
#define T_IF_1 ""
#define T_IF_2 ""
#define T_IF_3 ""

#define T_ELSE_BLOCK_0 "ELSE"
#define T_ELSE_BLOCK_1 T_BEGIN_BLOCK_0
#define T_ELSE_BLOCK_2 ""
#define T_ELSE_BLOCK_3 ""

#define T_ELSE_IF_0 "ELSE"
#define T_ELSE_IF_1 T_IF_0
#define T_ELSE_IF_2 ""
#define T_ELSE_IF_3 ""

#define T_WHILE_0 "WHILE"
#define T_WHILE_1 ""
#define T_WHILE_2 ""
#define T_WHILE_3 ""

#define T_FOR_0 "FOR"
#define T_DOWNTO_0 "DOWNTO"
#define T_DO_0 "DO"

#define T_REPEAT_0 "REPEAT"
#define T_UNTIL_0 "UNTIL"

#define T_CONTINUE_WHILE_0 "CONTINUE"
#define T_CONTINUE_WHILE_1 ""
#define T_CONTINUE_WHILE_2 ""
#define T_CONTINUE_WHILE_3 ""

#define T_EXIT_WHILE_0 "EXIT"
#define T_EXIT_WHILE_1 "" 
#define T_EXIT_WHILE_2 "" 
#define T_EXIT_WHILE_3 ""

#define T_INPUT_0 "SCAN"
#define T_INPUT_1 ""
#define T_INPUT_2 ""
#define T_INPUT_3 ""

#define T_OUTPUT_0 "PRINT"
#define T_OUTPUT_1 ""
#define T_OUTPUT_2 ""
#define T_OUTPUT_3 ""

#define T_NAME_0 "PROGRAM"
#define T_NAME_1 ""
#define T_NAME_2 ""
#define T_NAME_3 ""

#define T_DATA_0 "VAR"
#define T_DATA_1 ""
#define T_DATA_2 ""
#define T_DATA_3 ""

#define T_BEGIN_0 "BEGIN"
#define T_BEGIN_1 ""
#define T_BEGIN_2 ""
#define T_BEGIN_3 ""

#define T_END_0 "END"
#define T_END_1 ""
#define T_END_2 ""
#define T_END_3 ""

#define T_COLON_0 ":"
#define T_GOTO_0 "GOTO"

/* Grammar Definition */
#define GRAMMAR_LL2__2025 {\
{ LA_IS, {"ident_terminal"}, { "program_name",{\
    { LA_IS, {""}, 1, {"ident"}}\
}}},\
{ LA_IS, {T_DATA_TYPE_0}, { "value_type",{\
    { LA_IS, {""}, 2, {T_DATA_TYPE_0, T_DATA_TYPE_1}}\
}}},\
{ LA_IS, {"["}, { "array_specify",{\
    { LA_IS, {""}, 3, {"[", "unsigned_value", "]"}}\
}}},\
{ LA_IS, {"ident_terminal"}, { "declaration_element",{\
    { LA_IS, {""}, 2, {"ident", "array_specify__optional"}}\
}}},\
{ LA_IS, {"["}, { "array_specify__optional",{\
    { LA_IS, {""}, 1, {"array_specify"}}\
}}},\
{ LA_NOT, {"["}, { "array_specify__optional",{\
    { LA_IS, {""}, 0, {""}}\
}}},\
{ LA_IS, {T_COMA_0}, { "other_declaration_ident",{\
    { LA_IS, {""}, 2, {T_COMA_0, "declaration_element"}}\
}}},\
{ LA_IS, {T_DATA_TYPE_0}, { "declaration",{\
    { LA_IS, {""}, 3, {"value_type", "declaration_element", "other_declaration_ident__iteration"}}\
}}},\
{ LA_IS, { T_COMA_0 }, { "other_declaration_ident__iteration",{\
    { LA_IS, {""}, 2, { "other_declaration_ident", "other_declaration_ident__iteration" }}\
}}},\
{ LA_NOT, { T_COMA_0 }, { "other_declaration_ident__iteration",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
{ LA_IS, { "[" }, { "index_action",{\
    { LA_IS, {""}, 3, { "[", "expression", "]" }}\
}}},\
{ LA_IS, { T_NOT_0 }, { "unary_operator",{\
    { LA_IS, {""}, 1, { T_NOT_0 }}\
}}},\
{ LA_IS, { T_NOT_0 }, { "unary_operation",{\
    { LA_IS, {""}, 2, { "unary_operator", "expression" }}\
}}},\
{ LA_IS, { T_AND_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_AND_0 }}\
}}},\
{ LA_IS, { T_OR_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_OR_0 }}\
}}},\
{ LA_IS, { T_EQUAL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_EQUAL_0 }}\
}}},\
{ LA_IS, { T_NOT_EQUAL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_NOT_EQUAL_0 }}\
}}},\
{ LA_IS, { T_LESS_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_LESS_0 }}\
}}},\
{ LA_IS, { T_GREATER_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_GREATER_0 }}\
}}},\
{ LA_IS, { T_ADD_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_ADD_0 }}\
}}},\
{ LA_IS, { T_SUB_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_SUB_0 }}\
}}},\
{ LA_IS, { T_MUL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_MUL_0 }}\
}}},\
{ LA_IS, { T_DIV_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_DIV_0 }}\
}}},\
{ LA_IS, { T_MOD_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_MOD_0 }}\
}}},\
{ LA_IS, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action",{\
    { LA_IS, {""}, 2, { "binary_operator", "expression" }}\
}}},\
{LA_IS, { "(" }, { "left_expression",{\
    {LA_IS, { "" }, 1, { "group_expression" }}\
}}},\
{LA_IS, { T_NOT_0 }, { "left_expression",{\
    {LA_IS, { "" }, 1, { "unary_operation" }}\
}}},\
{LA_IS, { T_IF_0 }, { "left_expression",{\
    {LA_IS, { "" }, 1, { "cond_block" }}\
}}},\
{LA_IS, { "unsigned_value_terminal" }, { "left_expression",{\
    {LA_IS, {""}, 1, { "value" }}\
}}},\
{LA_IS, { T_ADD_0, T_SUB_0 }, { "left_expression",{\
    {LA_IS,  { "unsigned_value_terminal"}, 1, { "value" }}\
}}},\
{LA_IS, { "ident_terminal" }, { "left_expression",{\
    {LA_IS, {""}, 2, { "ident", "index_action__optional" }}\
}}},\
{LA_IS, { "[" }, { "index_action__optional",{\
    {LA_IS, {""}, 1, { "index_action" }}\
}}},\
{LA_NOT, { "[" }, { "index_action__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "expression",{\
    {LA_IS, {""}, 2, { "left_expression", "binary_action__iteration" }}\
}}},\
{LA_IS, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action__iteration",{\
    {LA_IS, {""}, 2, { "binary_action", "binary_action__iteration" }}\
}}},\
{LA_NOT, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action__iteration",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { "(" }, { "group_expression",{\
    {LA_IS, {""}, 3, { "(", "expression", ")" }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "expression_or_cond_block__with_optional_assign",{\
    {LA_IS, {""}, 2, { "expression", "assign_to_right__optional" }}\
}}},\
{LA_IS, { T_LRASSIGN_0 }, { "assign_to_right",{\
    {LA_IS, {""}, 3, { T_LRASSIGN_0, "ident", "index_action__optional" }}\
}}},\
{ LA_IS, { T_LRASSIGN_0 }, { "assign_to_right__optional",{\
    { LA_IS, {""}, 1, { "assign_to_right" }}\
}}},\
{ LA_NOT, { T_LRASSIGN_0 }, { "assign_to_right__optional",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "if_expression",{\
    {LA_IS, {""}, 1, { "expression" }}\
}}},\
{LA_IS, { T_BEGIN_BLOCK_0 }, { "body_for_true",{\
    {LA_IS, {""}, 1, { "block_statements_in_while_and_if_body" }}\
}}},\
{LA_IS, { T_ELSE_IF_0 }, { "false_cond_block_without_else",{\
    {LA_IS, {""}, 4, { T_ELSE_IF_0, T_ELSE_IF_1, "if_expression", "body_for_true" }}\
}}},\
{LA_IS, { T_ELSE_BLOCK_0 }, { "body_for_false",{\
    {LA_IS, {""}, 2, { T_ELSE_BLOCK_0, "block_statements" }}\
}}},\
{LA_IS, { T_IF_0 }, { "cond_block",{\
    {LA_IS, {""}, 5, { T_IF_0, "if_expression", "body_for_true", "false_cond_block_without_else__iteration", "body_for_false__optional" }}\
}}},\
{LA_IS, { T_ELSE_IF_0 }, { "false_cond_block_without_else__iteration",{\
    {LA_IS, {T_ELSE_IF_1}, 2, { "false_cond_block_without_else", "false_cond_block_without_else__iteration" }},\
    {LA_NOT, { T_ELSE_IF_1 }, 0, { "" }}\
}}},\
{LA_NOT, { T_ELSE_IF_0 }, { "false_cond_block_without_else__iteration",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { T_ELSE_BLOCK_0 }, { "body_for_false__optional",{\
    {LA_IS, {""}, 1, { "body_for_false" }}\
}}},\
{LA_NOT, { T_ELSE_BLOCK_0 }, { "body_for_false__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { T_CONTINUE_WHILE_0 }, { "continue_while",{\
    {LA_IS, {""}, 1, { T_CONTINUE_WHILE_0 }}\
}}},\
{LA_IS, { T_EXIT_WHILE_0 }, { "break_while",{\
    {LA_IS, {""}, 1, { T_EXIT_WHILE_0 }}\
}}},\
{LA_IS, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0, T_CONTINUE_WHILE_0, T_EXIT_WHILE_0 }, { "statement_in_while_and_if_body",{\
    {LA_IS, {""}, 1, { "statement" }}\
}}},\
{LA_IS, { T_BEGIN_BLOCK_0 }, { "block_statements_in_while_and_if_body",{\
    {LA_IS, {""}, 3, { T_BEGIN_BLOCK_0, "statement_in_while_and_if_body__iteration", T_END_BLOCK_0 }}\
}}},\
{LA_IS, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0, T_CONTINUE_WHILE_0, T_EXIT_WHILE_0 }, { "statement_in_while_and_if_body__iteration",{\
    {LA_IS, {""}, 2, { "statement_in_while_and_if_body", "statement_in_while_and_if_body__iteration" }}\
}}},\
{LA_NOT, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0, T_CONTINUE_WHILE_0, T_EXIT_WHILE_0 }, { "statement_in_while_and_if_body__iteration",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "while_cycle_head_expression",{\
    {LA_IS, {""}, 1, { "expression" }}\
}}},\
{LA_IS, { T_WHILE_0 }, { "while_cycle",{\
    {LA_IS, {""}, 3, { T_WHILE_0, "while_cycle_head_expression", "block_statements_in_while_and_if_body" }}\
}}},\
{LA_IS, { T_FOR_0 }, { "forto_cycle",{\
    {LA_IS, {""}, 5, { T_FOR_0, "cycle_counter_init", T_DOWNTO_0, "expression", "cycle_body" }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "cycle_counter_init",{\
    {LA_IS, {""}, 3, { "expression", T_LRASSIGN_0, "ident" }}\
}}},\
{LA_IS, { T_DO_0 }, { "cycle_body",{\
    {LA_IS, {T_BEGIN_BLOCK_0}, 2, { T_DO_0, "block_statements" }},\
    {LA_NOT, {T_BEGIN_BLOCK_0}, 2, { T_DO_0, "statement" }}\
}}},\
{LA_IS, { T_REPEAT_0 }, { "repeat_until_cycle",{\
    {LA_IS, {""}, 4, { T_REPEAT_0, "statements__or__block_statements", T_UNTIL_0, "expression" }}\
}}},\
{LA_IS, { "ident_terminal" }, { "labeled_point",{\
    {LA_IS, {""}, 2, { "ident", T_COLON_0 }}\
}}},\
{LA_IS, { T_GOTO_0 }, { "goto_label",{\
    {LA_IS, {""}, 2, { T_GOTO_0, "ident" }}\
}}},\
{LA_IS, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0 }, { "statements__or__block_statements",{\
    {LA_IS, {""}, 1, { "statement__iteration" }}\
}}},\
{LA_IS, { T_BEGIN_BLOCK_0 }, { "statements__or__block_statements",{\
    {LA_IS, {""}, 1, { "block_statements" }}\
}}},\
{LA_IS, { T_INPUT_0 }, { "input_rule",{\
    {LA_IS, {""}, 2, { T_INPUT_0, "argument_for_input" }}\
}}},\
{LA_IS, { "ident_terminal" }, { "argument_for_input",{\
    {LA_IS, {""}, 2, { "ident", "index_action__optional" }}\
}}},\
{LA_IS, { "(" }, { "argument_for_input",{\
    {LA_IS, {""}, 4, { "(", "ident", "index_action__optional", ")" }}\
}}},\
{LA_IS, { T_OUTPUT_0 }, { "output_rule", {\
    {LA_IS, { "" }, 2, {T_OUTPUT_0, "expression"} }\
}}},\
{LA_IS, { "(", T_NOT_0, "ident_terminal", "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0 }, { "statement", {\
    { LA_IS, {""}, 1, {"expression_or_cond_block__with_optional_assign"}}\
}}},\
{LA_IS, { T_WHILE_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"while_cycle"}}\
}}},\
{LA_IS, { T_FOR_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"forto_cycle"}}\
}}},\
{LA_IS, { T_REPEAT_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"repeat_until_cycle"}}\
}}},\
{LA_IS, { T_GOTO_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"goto_label"}}\
}}},\
{LA_IS, { "ident_terminal" }, { "statement",{\
    {LA_IS, {T_COLON_0}, 1, {"labeled_point"}},\
    {LA_NOT, {T_COLON_0}, 1, {"expression_or_cond_block__with_optional_assign"}}\
}}},\
{LA_IS, { T_INPUT_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"input_rule"}}\
}}},\
{LA_IS, { T_OUTPUT_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"output_rule"}}\
}}},\
{LA_IS, { T_CONTINUE_WHILE_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"continue_while"}}\
}}},\
{LA_IS, { T_EXIT_WHILE_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"break_while"}}\
}}},\
{LA_IS, { T_SEMICOLON_0 }, { "statement",{\
    {LA_IS, {""}, 1, {";"}}\
}}},\
{ LA_IS, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_GOTO_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0, T_CONTINUE_WHILE_0, T_EXIT_WHILE_0 }, { "statement__iteration",{\
    { LA_IS, {""}, 2, { "statement", "statement__iteration" }}\
}}},\
{ LA_NOT, { "ident_terminal", "(", T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_WHILE_0, T_FOR_0, T_REPEAT_0, T_GOTO_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0, T_CONTINUE_WHILE_0, T_EXIT_WHILE_0 }, { "statement__iteration",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
{ LA_IS, { T_BEGIN_BLOCK_0 }, { "block_statements",{\
    { LA_IS, {""}, 3, { T_BEGIN_BLOCK_0, "statement__iteration", T_END_BLOCK_0 }}\
}}},\
{LA_IS, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "expression__optional",{\
    {LA_IS, {""}, 1, { "expression" }}\
}}},\
{LA_NOT, { "(", T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal", T_IF_0 }, { "expression__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
{ LA_IS, { T_NAME_0 }, { "program_rule",{\
    { LA_IS, {""}, 9, { T_NAME_0, "program_name", T_SEMICOLON_0, T_DATA_0, "declaration", T_SEMICOLON_0, T_BEGIN_0, "statement__iteration", T_END_0 }}\
}}},\
{LA_IS, { "unsigned_value_terminal", T_ADD_0, T_SUB_0 }, { "value", {\
    {LA_IS, { "" }, 2, { "sign__optional", "unsigned_value" }}\
}}},\
{LA_IS, { T_ADD_0, T_SUB_0 }, { "sign__optional", {\
    {LA_IS, { "" }, 1, { "sign" }}\
}}},\
{LA_NOT, { T_ADD_0, T_SUB_0 }, { "sign__optional",{\
    {LA_IS, { "" }, 0, { "" }}\
}}},\
{LA_IS, { T_ADD_0 }, { "sign", {\
    {LA_IS, {""}, 1, { T_ADD_0 }}\
}}},\
{LA_IS, { T_SUB_0 }, { "sign", {\
    {LA_IS, {""}, 1, { T_SUB_0 } }\
}}},\
/* unsigned_value_token represents unsigned_value in lexical analyzer */\
{LA_IS, { "unsigned_value_terminal" }, { "unsigned_value", {\
    {LA_IS, { "" }, 1, { "unsigned_value_terminal" }}\
}}},\
/* ident_token represents ident in lexical analyzer */\
{LA_IS, { "ident_terminal" }, { "ident", {\
    {LA_IS, {""}, 1, {"ident_terminal"} }\
}}},\
\
{ LA_IS, { T_NAME_0 }, { "program____part1",{\
    { LA_IS, {""}, 7, { T_NAME_0, "program_name", T_SEMICOLON_0, T_BODY_0, T_DATA_0, "declaration", T_SEMICOLON_0 }}\
}}},\
\
},\
"program_rule"
