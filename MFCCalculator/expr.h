#pragma once
#define MATH_PI  3.14159265358979323846
#define MATH_E  2.71828182845904523536
#include <string>
#include <math.h>
#include <stack>
bool is_oper_sign(char c)
{
	return ('+' == c) || ('-' == c) || ('*' == c) || ('/' == c)|| ('^' == c) || ('%' == c);
}
bool is_sign(char c)
{
	return ('+' == c) || ('-' == c);
}
bool is_number(char c)
{
	return ('0' <= c) && ('9' >= c);
}
bool is_left_bracket(char c)
{
	return ('(' == c) || ('[' == c) || ('{' == c);
}
bool is_right_bracket(char c)
{
	return (')' == c) || (']' == c) || ('}' == c);
}
bool is_letter(char c)
{
	return (('a' <= c) && ('z' >= c)) || (('A' <= c) && ('Z' >= c));
}
bool is_dot(char c)
{
	return ('.' == c);
}
bool is_space(char c)
{
	return (' ' == c);
}
enum operator_sign
{
	OP_ADD, //+
	OP_SUB, //-
	OP_MUL, //*
	OP_DIV, ///

	OP_POW, //^
	OP_MOD, //%


	OP_SIN, //sin(x)
	OP_COS, //cos(x)
	OP_TAN, //tan(x)
	OP_COT, //cot(x)
	OP_SEC, //sec(x)
	OP_CSC, //csc(x)

	OP_LG,  //lg(x)
	OP_LN,  //ln(x)
	OP_FACT, //fact(x),x!
	OP_ABS, //abs(x),|x|


	OP_left,//(
	OP_right,//)

	OP_START,
	OP_ERROR
};

bool is_binary_oper(operator_sign o)
{
	return (OP_ADD <= o)&& (OP_MOD >= o);
}
bool is_unary_oper(operator_sign o){
	return (OP_SIN <= o) && (OP_ABS >= o);
}


double oper_binary(operator_sign o, double a, double b)
{
	switch (o)
	{
	case OP_ADD:
		return a + b;
		break;
	case OP_SUB:
		return a - b;
		break;
	case OP_MUL:
		return a * b;
		break;
	case OP_DIV:
		return a / b;
		break;
	case OP_POW:
		return pow(a, b);
		break;
	case OP_MOD:
		return ((int)a % (int)b);
		break;
	default:
		break;
	}
	return 0;
}
int fact(int x)
{
	int s = 1;
	for (; x >= 1; x--)
	{
		s *= x;
	}
	return s;
}
double oper_unary(operator_sign o, double x)
{
	switch (o)
	{

	case OP_SIN:
		return sin(x);
		break;
	case OP_COS:
		return cos(x);
		break;
	case OP_TAN:
		return tan(x);
		break;
	case OP_COT:
		return 1 / tan(x);
		break;
	case OP_SEC:
		return 1 / cos(x);
		break;
	case OP_CSC:
		return 1 / sin(x);
		break;

	case OP_LG:
		return log(x);
		break;
	case OP_LN:
		return log(x) / log(MATH_E);
		break;

	case OP_FACT:
		return fact((int)x);
		break;

	case OP_ABS:
		return fabs(x);
		break;
	default:
		break;
	}
	return 0;
}
int get_priority(operator_sign o){
	if(OP_POW==o)return 4;
	if((OP_MUL==o)||(OP_DIV==o)||(OP_MOD==o))return 3;
	if((OP_ADD==o)||(OP_SUB==o))return 2;
	if(OP_left==o)return 1;
	//if(is_unary_oper(o))return 1;
	if(OP_START==o)return 0;
	return -1;

}
operator_sign get_oper_from_letter(const char* str){
	if((strcmp(str,"sin")==0)||(strcmp(str,"SIN")==0))return OP_SIN;
	if((strcmp(str,"cos")==0)||(strcmp(str,"COS")==0))return OP_COS;
	if((strcmp(str,"tan")==0)||(strcmp(str,"TAN")==0))return OP_TAN;
	if((strcmp(str,"cot")==0)||(strcmp(str,"COT")==0))return OP_COT;
	if((strcmp(str,"sec")==0)||(strcmp(str,"SEC")==0))return OP_SEC;
	if((strcmp(str,"csc")==0)||(strcmp(str,"CSC")==0))return OP_CSC;

	if((strcmp(str,"lg")==0)||(strcmp(str,"LG")==0))return OP_LG;
	if((strcmp(str,"ln")==0)||(strcmp(str,"LN")==0))return OP_LN;
	if((strcmp(str,"fact")==0)||(strcmp(str,"FACT")==0))return OP_FACT;
	if((strcmp(str,"abs")==0)||(strcmp(str,"ABS")==0))return OP_ABS;
	return OP_ERROR;
}
operator_sign get_oper_from_sign(char c){
	if ('+'==c)return OP_ADD;
	if ('-'==c)return OP_SUB;
	if ('*'==c)return OP_MUL;
	if ('/'==c)return OP_DIV;
	if ('^'==c)return OP_POW;
	if ('%'==c)return OP_MOD;
	
	return OP_ERROR;

}

double evaluate(std::string str)
{
	int len = str.length();
	str.insert(len, ")"); len++;
	std::stack<operator_sign> s_oper;
	s_oper.push(OP_START);
	s_oper.push(OP_left);
	std::stack<double> s_number;
	char c;
	double d;
	char tmp[10];
	bool last_push_left_bracket = true;

	for (int i = 0; i < len; i++)
	{
		c = str[i];
		if (is_space(c))
			continue;
		if (is_number(c))
		{
			d = c - '0';
			while (is_number(str[++i]))
			{
				d = d * 10 + (str[i] - '0');
			}
			if (is_dot(str[i]))
			{
				int j = 0;
				while (is_number(str[++i]))
				{
					j++;
					d = d + (str[i] - '0') / pow(10, j);
				}
			}if (is_letter(str[i])) {
				if (('p' == str[i]) && ('i' == str[i + 1]))
				{
					d *= MATH_PI;
					i += 2;
				}
				else if ('e' == str[i])
				{
					d *= MATH_E;
					i++;
				}
				else throw 1;
			}
			s_number.push(d);
			last_push_left_bracket = false;
			i--;
			continue;
		}
		if (is_left_bracket(c))
		{
			s_oper.push(OP_left);
			last_push_left_bracket = true;
			continue;
		}
		if (is_letter(c))
		{
			int j = 0;
			tmp[j] = c;
			while (is_letter(str[++i]))
			{
				tmp[++j] = str[i];
			}
			tmp[++j] = '\0';
			if (strcmp(tmp, "pi") == 0)
			{
				s_number.push(MATH_PI);
				last_push_left_bracket = false;
			}
			else if (strcmp(tmp, "e") == 0)
			{
				s_number.push(MATH_E);
				last_push_left_bracket = false;
			}
			else if (is_left_bracket(str[i]))
			{
				s_oper.push(get_oper_from_letter(tmp));
				if (s_oper.top() == OP_ERROR)throw 1;
				s_oper.push(OP_left);
				last_push_left_bracket = true;
				i++;
			}
			else throw 1;
			i--;
			continue;
		}

		if (is_oper_sign(c))
		{
			operator_sign o = get_oper_from_sign(c);
			if (is_sign(c) && last_push_left_bracket)
			{
				s_number.push(0.0);
				last_push_left_bracket = false;
			}
			if (get_priority(o) > get_priority(s_oper.top()))
			{
				s_oper.push(o);
				last_push_left_bracket = false;
			}
			else
			{
				if (s_number.empty())throw 1;
				double a = s_number.top();
				s_number.pop();
				if (s_number.empty())throw 1;
				double b = s_number.top();
				s_number.pop();
				s_number.push(oper_binary(s_oper.top(), b, a));
				last_push_left_bracket = false;
				if (s_oper.empty())throw 1;
				s_oper.pop();
				i--;
			}
			continue;
		}
		if (is_right_bracket(c))
		{
			if (OP_left == s_oper.top())
			{
				s_oper.pop();
				if (is_unary_oper(s_oper.top()))
				{
					if (s_number.empty())throw 1;
					double dtmp = oper_unary(s_oper.top(), s_number.top());
					s_oper.pop();
					s_number.pop();
					s_number.push(dtmp);
					last_push_left_bracket = false;
				}
			}
			else
			{
				if (s_number.empty())throw 1;
				double a = s_number.top();
				s_number.pop();
				if (s_number.empty())throw 1;
				double b = s_number.top();
				s_number.pop();
				s_number.push(oper_binary(s_oper.top(), b, a));
				last_push_left_bracket = false;
				if (s_oper.empty())throw 1;
				s_oper.pop();
				i--;
			}
			continue;
		}
	}
	if ((s_number.size()!=1)||(s_oper.size()!=1))throw 1;
	return s_number.top();
}