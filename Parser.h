typedef union{
	double dval;
	int ival;
} NumberExprAST;

typedef struct{
	char* Name;
} VariableExprAST;

typedef union ExprAST {
	struct {
		char Op;
		union ExprAST* LHS;
		union ExprAST* RHS;
	} BinaryExprAST;

	struct{
		char* Callid;
		union ExprAST* Args;
		int numArgs;
	} CallExprAST;
	VariableExprAST var;
	NumberExprAST num;
} ExprAST;

typedef struct {
	char* Name;
	ExprAST* Args;
	int numArgs;
} PrototypeAST;

typedef struct {
	PrototypeAST pro;
	ExprAST body;
} FunctionAST;
