#ifndef __PARSER_H__
#define __PARSER_H__
#include <common.h>
#include <loader.h>
#include <stdio.h>



typedef struct _AST_TOKEN ASTToken;
typedef struct _AST_EXPRESSION_ARG ASTExpressionArg;
typedef struct _AST_EXPRESSION* ASTExpression;
typedef struct _AST_OBJECT* ASTObject;



enum AST_TOKEN_TYPE{
	AST_TOKEN_TYPE_UNKNOWN=0x00,
	AST_TOKEN_TYPE_STRING=0x01,
	AST_TOKEN_TYPE_CHAR=0x02,
	AST_TOKEN_TYPE_INT=0x03,
	AST_TOKEN_TYPE_FLOAT=0x04,
	AST_TOKEN_TYPE_KEYWORD=0x05,
	AST_TOKEN_TYPE_MODIFIER=0x06,
	AST_TOKEN_TYPE_IDENTIFIER=0x07,
	AST_TOKEN_TYPE_OPERATOR=0x08,
	AST_TOKEN_TYPE_WHITESPACE=0x09,
	AST_TOKEN_TYPE_ERROR=0xfe,
	AST_TOKEN_TYPE_EOF=0xff
};



enum AST_TOKEN_MODIFIER{
	AST_TOKEN_MODIFIER_UNKNOWN=0x00,
	AST_TOKEN_MODIFIER_PUBLIC=0x01,
	AST_TOKEN_MODIFIER_PRIVATE=0x02,
	AST_TOKEN_MODIFIER_STATIC=0x04,
	AST_TOKEN_MODIFIER_EXPORT=0x08,
	AST_TOKEN_MODIFIER_FROZEN=0x10,
	AST_TOKEN_MODIFIER_FROZENTYPE=0x20,
	AST_TOKEN_MODIFIER_CONST=0x40,
	AST_TOKEN_MODIFIER_OPERATOR=0x80
};



enum AST_TOKEN_KEYWORD{
	AST_TOKEN_KEYWORD_UNKNOWN=0x00,
	AST_TOKEN_KEYWORD_AS=0x01,
	AST_TOKEN_KEYWORD_ASSERT=0x02,
	AST_TOKEN_KEYWORD_CLASS=0x03,
	AST_TOKEN_KEYWORD_DEF=0x04,
	AST_TOKEN_KEYWORD_DEBUGGER=0x05,
	AST_TOKEN_KEYWORD_DELETE=0x06,
	AST_TOKEN_KEYWORD_ELIF=0x07,
	AST_TOKEN_KEYWORD_ELSE=0x08,
	AST_TOKEN_KEYWORD_FOR=0x09,
	AST_TOKEN_KEYWORD_IF=0x0a,
	AST_TOKEN_KEYWORD_IMPORT=0x0b,
	AST_TOKEN_KEYWORD_RAISE=0x0c,
	AST_TOKEN_KEYWORD_RETURN=0x0d,
	AST_TOKEN_KEYWORD_WHILE=0x0e
};



enum AST_TOKEN_OPERATOR{
	AST_TOKEN_OPERATOR_UNKNOWN=0x00,
	AST_TOKEN_OPERATOR_AMP=0x01,
	AST_TOKEN_OPERATOR_AT=0x02,
	AST_TOKEN_OPERATOR_CIRCUMFLEX=0x03,
	AST_TOKEN_OPERATOR_CLOSE_BRACKET=0x04,
	AST_TOKEN_OPERATOR_COLON=0x05,
	AST_TOKEN_OPERATOR_COMMA=0x06,
	AST_TOKEN_OPERATOR_EQUALS=0x07,
	AST_TOKEN_OPERATOR_EXCLAMATION_MARK=0x08,
	AST_TOKEN_OPERATOR_GRATER=0x09,
	AST_TOKEN_OPERATOR_LEFT_BRACES=0x0a,
	AST_TOKEN_OPERATOR_LEFT_PARENTHESIS=0x0b,
	AST_TOKEN_OPERATOR_LESS=0x0c,
	AST_TOKEN_OPERATOR_MINUS=0x0d,
	AST_TOKEN_OPERATOR_MODULO=0x0e,
	AST_TOKEN_OPERATOR_OPEN_BRACKET=0x0f,
	AST_TOKEN_OPERATOR_PERIOD=0x10,
	AST_TOKEN_OPERATOR_PLUS=0x11,
	AST_TOKEN_OPERATOR_QUESTION_MARK=0x12,
	AST_TOKEN_OPERATOR_RIGHT_BRACES=0x13,
	AST_TOKEN_OPERATOR_RIGHT_PARENTHESIS=0x14,
	AST_TOKEN_OPERATOR_SEMICOLON=0x15,
	AST_TOKEN_OPERATOR_SLASH=0x16,
	AST_TOKEN_OPERATOR_STAR=0x17,
	AST_TOKEN_OPERATOR_TILDA=0x18,
	AST_TOKEN_OPERATOR_VERTICAL_BAR=0x19
};



enum AST_EXPRESSION_TYPE{
	AST_EXPRESSION_TYPE_UNKNOWN=0x00,
	AST_EXPRESSION_TYPE_EMPTY=0x01,
	AST_EXPRESSION_TYPE_CONST=0x02,
	AST_EXPRESSION_TYPE_LST=0x03,
	AST_EXPRESSION_TYPE_ARR=0x04,
	AST_EXPRESSION_TYPE_EXPAND=0x05,
	AST_EXPRESSION_TYPE_INC=0x06,
	AST_EXPRESSION_TYPE_DEC=0x07,
	AST_EXPRESSION_TYPE_CALL=0x08,
	AST_EXPRESSION_TYPE_SLC=0x09,
	AST_EXPRESSION_TYPE_ACS=0x0a,
	AST_EXPRESSION_TYPE_DEREF=0xfe,/***************************/
	AST_EXPRESSION_TYPE_REF=0xff,/*****************************/
	AST_EXPRESSION_TYPE_PLUS=0x0b,
	AST_EXPRESSION_TYPE_MINUS=0x0c,
	AST_EXPRESSION_TYPE_NOT=0x0d,
	AST_EXPRESSION_TYPE_BNOT=0x0e,
	AST_EXPRESSION_TYPE_POW=0x0f,
	AST_EXPRESSION_TYPE_ROOT=0x10,
	AST_EXPRESSION_TYPE_IROOT=0x11,
	AST_EXPRESSION_TYPE_MLT=0x12,
	AST_EXPRESSION_TYPE_DIV=0x13,
	AST_EXPRESSION_TYPE_FDIV=0x14,
	AST_EXPRESSION_TYPE_MOD=0x15,
	AST_EXPRESSION_TYPE_MMLT=0x16,
	AST_EXPRESSION_TYPE_ADD=0x17,
	AST_EXPRESSION_TYPE_SUB=0x18,
	AST_EXPRESSION_TYPE_LSH=0x19,
	AST_EXPRESSION_TYPE_RSH=0x1a,
	AST_EXPRESSION_TYPE_LT=0x1b,
	AST_EXPRESSION_TYPE_LE=0x1c,
	AST_EXPRESSION_TYPE_GT=0x1d,
	AST_EXPRESSION_TYPE_GE=0x1e,
	AST_EXPRESSION_TYPE_EQ=0x1f,
	AST_EXPRESSION_TYPE_NE=0x20,
	AST_EXPRESSION_TYPE_BAND=0x21,
	AST_EXPRESSION_TYPE_BXOR=0x22,
	AST_EXPRESSION_TYPE_BOR=0x23,
	AST_EXPRESSION_TYPE_AND=0x24,
	AST_EXPRESSION_TYPE_OR=0x25,
	AST_EXPRESSION_TYPE_TCOND=0x26,
	AST_EXPRESSION_TYPE_EQU=0x27,
	AST_EXPRESSION_TYPE_ADD_EQU=0x28,
	AST_EXPRESSION_TYPE_SUB_EQU=0x29,
	AST_EXPRESSION_TYPE_MLT_EQU=0x2a,
	AST_EXPRESSION_TYPE_DIV_EQU=0x2b,
	AST_EXPRESSION_TYPE_FDIV_EQU=0x2c,
	AST_EXPRESSION_TYPE_MOD_EQU=0x2d,
	AST_EXPRESSION_TYPE_MMLT_EQU=0x2e,
	AST_EXPRESSION_TYPE_POW_EQU=0x2f,
	AST_EXPRESSION_TYPE_ROOT_EQU=0x30,
	AST_EXPRESSION_TYPE_IROOT_EQU=0x31,
	AST_EXPRESSION_TYPE_LSH_EQU=0x32,
	AST_EXPRESSION_TYPE_RSH_EQU=0x33,
	AST_EXPRESSION_TYPE_BAND_EQU=0x34,
	AST_EXPRESSION_TYPE_BXOR_EQU=0x35,
	AST_EXPRESSION_TYPE_BOR_EQU=0x36
};



enum AST_EXPRESSION_ARG_TYPE{
	AST_EXPRESSION_ARG_TYPE_UNKNOWN=0x00,
	AST_EXPRESSION_ARG_TYPE_EXPRESSION=0x01,
	AST_EXPRESSION_ARG_TYPE_STRING=0x02,
	AST_EXPRESSION_ARG_TYPE_CHAR=0x03,
	AST_EXPRESSION_ARG_TYPE_INT=0x04,
	AST_EXPRESSION_ARG_TYPE_FLOAT=0x05,
	AST_EXPRESSION_ARG_TYPE_IDENTIFIER=0x06
};



enum AST_EXPRESSION_END_TYPE{
	AST_EXPRESSION_END_TYPE_WHITESPACE_OR_SEMICOLON=0x00,
	AST_EXPRESSION_END_TYPE_SEMICOLON=0x01,
	AST_EXPRESSION_END_TYPE_COLON=0x02
};



struct _AST_TOKEN{
	enum AST_TOKEN_TYPE t;
	union _AST_TOKEN_DATA{
		char u;
		struct _AST_TOKEN_DATA_STRING{
			size_t sl;
			char* s;
		} s;
		char c;
		int64_t i;
		double f;
		enum AST_TOKEN_KEYWORD k;
		enum AST_TOKEN_MODIFIER m;
		struct _AST_TOKEN_DATA_IDENTIFIER{
			size_t il;
			char* i;
		} id;
		enum AST_TOKEN_OPERATOR op;
	} dt;
	size_t _off;
};



struct _AST_EXPRESSION_ARG{
	enum AST_EXPRESSION_ARG_TYPE t;
	union _AST_EXPRESSION_ARG_VALUE{
		struct _AST_EXPRESSION* ex;
		struct _AST_EXPRESSION_ARG_VALUE_STRING{
			size_t sl;
			char* s;
		} s;
		char c;
		int64_t i;
		double f;
		struct _AST_EXPRESSION_ARG_VALUE_IDENTIFIER{
			size_t il;
			char* i;
		} id;
	} v;
};



struct _AST_EXPRESSION{
	enum AST_EXPRESSION_TYPE t;
	ASTExpressionArg a;
	uint8_t bl;
	ASTExpressionArg* b;
};



struct _AST_OBJECT{
	FileObject fo;
};



ASTObject ast_parse_file(FileObject fo);



ASTExpression ast_parse_expression(FileObject fo,ASTToken* t,enum AST_EXPRESSION_END_TYPE);



uint8_t next_token(FileObject fo,ASTToken* t);



uint8_t parse_string_char(uint8_t* s,size_t* i,uint8_t* e);



#endif
