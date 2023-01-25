module Syntax

extend lang::std::Layout;
extend lang::std::Id;

/*
 * Concrete syntax of QL
 */

start syntax Form
  = "form" Id name "{" Question* questions "}"; 

syntax Question = 
  Str Id ":" Type
  | Str Id ":" Type "=" Expr
  | "if" "(" Expr ")" "{" Question* "}" "else" "{" Question* "}"
  | "if" "(" Expr ")" "{" Question* "}";

// We followed the C Operator Precedence
syntax Expr 
  = Id \ Reserved // reserved keywords
  | Bool
  | Int
  | Str
  > bracket "(" Expr ")"
  > right "!" Expr
  > left (Expr "*" Expr | Expr "/" Expr) 
  > left (Expr "+" Expr | Expr "-" Expr) 

  > left (Expr "\>" Expr 
    | Expr "\<" Expr 
    | Expr "\<=" Expr 
    | Expr "\>=" Expr) 

  > left (Expr "==" Expr | Expr "!=" Expr)
  > left Expr "&&" Expr
  > left Expr "||" Expr;
  
syntax Type = "bool" | "int" | "str";

lexical Str = "(.*?)"; // catching everything between quotes except quotes

lexical Int = [\-]?[1-9][0-9]* | [0]; // catching everything while removing trailing zeros at the beginning 

lexical Bool = "true" | "false";

keyword Reserved
= "true" 
| "false" 
| "bool" 
| "int" 
| "str";