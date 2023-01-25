module AST

/*
 * Define Abstract Syntax for QL
 *
 * - complete the following data types
 * - make sure there is an almost one-to-one correspondence with the grammar
 */

data AForm(loc src = |tmp:///|)
  = form(str name, list[AQuestion] qs); 

data AQuestion(loc src = |tmp:///|)
  = question(str q, AId id, AType t)
  | computed_question(str q, AId id, AType t, AExpr exp)
  | if_then_else(AExpr condition, list[AQuestion] then_answ, list[AQuestion] else_answ)
  | if_then(AExpr condition, list[AQuestion] then_answ);

data AExpr(loc src = |tmp:///|)
  = ref(AId id)
  | \bool(bool boolean)
  | \int(int integer)
  | \str(str string)
  | par(AExpr exp)
  | not(AExpr exp)
  | mul(AExpr exp1, AExpr exp2)
  | div(AExpr exp1, AExpr exp2)
  | add(AExpr exp1, AExpr exp2)
  | sub(AExpr exp1, AExpr exp2)
  | greater(AExpr exp1, AExpr exp2)
  | less(AExpr exp1, AExpr exp2)
  | leq(AExpr exp1, AExpr exp2)
  | geq(AExpr exp1, AExpr exp2)
  | eq(AExpr exp1, AExpr exp2)
  | neq(AExpr exp1, AExpr exp2)
  | and(AExpr exp1, AExpr exp2)
  | or(AExpr exp1, AExpr exp2);


data AId(loc src = |tmp:///|)
  = id(str name);

data AType(loc src = |tmp:///|)
  = \bool() | \int() | \str();





