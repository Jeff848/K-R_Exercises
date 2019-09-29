#define MAXVAL 100
#define MAXSTRING 100


typedef enum {
	TOKEN_ERROR,
	TOKEN_OP,
	TOKEN_IDENT,
	TOKEN_INT,
	TOKEN_FLOAT,
	TOKEN_STRING
} token;


typedef struct{
	token dataType;
	union {
		int intval;
		float floatval;
		char *string;
		char op;
	} val;
} token_t;

int lineno = 1;


int getNextToken(FILE* filename, token_t *t);
