#include "Parser.h"
#include "Lexer.h"

static int CurTok;
static token_t curtoken;
static int getNextTok(){
	return CurTok = getNextToken();
}


static ExprAST ParseNumberExpr(){
	ExprAST expr;
	if(CurTok == TOKEN_INT)
		expr.num.ival = curtoken.val.intval;
	else if(CurTok == TOKEN_FLOAT)
		expr.num.dval = curtoken.val.floatval;
	getNextTok();
	return expr;
}

static ExprAST ParseParenExpr(){
	getNextTok();
	ExprAST expr;

}
