module CST2AST

import Syntax;
import AST;

import ParseTree;

/*
 * Implement a mapping from concrete syntax trees (CSTs) to abstract syntax trees (ASTs)
 *
 * - Use switch to do case distinction with concrete patterns (like in Hack your JS) 
 * - Map regular CST arguments (e.g., *, +, ?) to lists 
 *   (NB: you can iterate over * / + arguments using `<-` in comprehensions or for-loops).
 * - Map lexical nodes to Rascal primitive types (bool, int, str)
 * - See the ref example on how to obtain and propagate source locations.
 */

AForm cst2ast(start[Form] sf) {
  Form f = sf.top; // remove layout before and after form
  return form("", [ ], src=f.src); 
}

default AQuestion cst2ast(Question q) {
  
  throw "Not yet implemented <q>";
}

AExpr cst2ast(Expr e) {
  switch (e) {
    case (Expr)`<Id x>`: 
      return ref(id("<x>", src=x.src), src=x.src);

    case (Expr)`<Id x>`: 
      return ref(cst2ast(x), src=x@\loc);
    
    case (Expr)`<Str s>`: 
      return \str("<s>"[1..-1], src=s@\loc);
    
    case (Expr)`<Int i>`: 
      return \int(toInt("<i>"), src=i@\loc);
    
    case (Expr)`<Bool b>`: 
      return \bool((Bool)`true` := b, src=b@\loc);
    
    case (Expr)`( <Expr ex> )`: 
      return par(cst2ast(ex), src=ex@\loc);
    
    case (Expr)`! <Expr exp>`: 
      return not(cst2ast(exp), src=exp@\loc);
    
    case (Expr)`<Expr exp1> * <Expr exp2>`:
      return mul(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> / <Expr exp2>`:
      return div(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> + <Expr exp2>`:
      return add(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> - <Expr exp2>`:
      return sub(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> \> <Expr exp2>`:
      return greater(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> \< <Expr exp2>`:
      return le(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> \<= <Expr exp2>`:
      return leq(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> \>= <Expr exp2>`:
      return geq(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> == <Expr exp2>`:
      return eq(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> != <Expr exp2>`:
      return neq(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    case (Expr)`<Expr exp1> && <Expr exp2>`:
      return and(cst2ast(exp1), cst2ast(exp2), src=e@\loc);
      
    case (Expr)`<Expr exp1> || <Expr exp2>`:
      return or(cst2ast(exp1), cst2ast(exp2), src=e@\loc);

    default: throw "Unhandled expression: <e>";
  }
}


default AType cst2ast(Type t) {
  throw "Not yet implemented <t>";
}
