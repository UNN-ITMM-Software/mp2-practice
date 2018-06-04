﻿#include "Postfix.h"
#include "Stack.h"
#include "Stack.cpp"

string Postfix::postfix_notation(string expression)
{
	Stack<char> opStack;
	Stack<char> trackStack;

	map <char, int> op;
	op['*'] = 3;
	op['/'] = 3;
	op['+'] = 2;
	op['-'] = 2;
	op['('] = 1;
	op['='] = 0;

	char buff;

	for (int i = 0; i < expression.length(); i++) {
		buff = expression[i];
		if (op.count(buff)) {			
			if ((!opStack.isEmpty()) && (op[buff] <= op[opStack.look()]) && (buff != '('))
				while ((!opStack.isEmpty()) && (op[buff] <= op[opStack.look()]))
					trackStack.push(opStack.pop());
		

			opStack.push(buff);
			continue;
		}

		if (((buff >= 0x41) && (buff <= 0x5A))							 
			|| ((buff >= 0x61) && (buff <= 0x7A))) {						
			trackStack.push(buff);
			continue;
		}

		if (buff == ')') {																				
			while ((!opStack.isEmpty()) && (opStack.look() != '('))		 									
				trackStack.push(opStack.pop());							
			if (opStack.isEmpty())										
				throw "несогласованные скобки!";
			opStack.pop();
			continue;
		}
		throw "недопустимые символы";
	}
	while (!opStack.isEmpty()) {
		if (opStack.look() == '(')
			throw "несогласованные скобки!";
		trackStack.push(opStack.pop());
	}

	if (trackStack.isEmpty())
		throw "нет данных";

	string result;
	string tmp;

	while (!trackStack.isEmpty()) {
		tmp = trackStack.pop();
		result.insert(0, tmp);
	}
	return result;
}

float Postfix::postfix_calculation(string expression)
{
	if (expression == "")
		throw "нет данных";
	Stack<float> trackStack;
	char buff;
	float leftOperand;
	float rightOperand;

	map<char, float> values;

	cout << "Введите значения: " << endl;
	for (int i = 0; i < expression.length(); i++) {
		buff = expression[i];
		if (expression[expression.length() - 1] == '=')
			values[expression[0]] = 0;
		if (((buff >= 0x41) && (buff <= 0x5A))
			|| ((buff >= 0x61) && (buff <= 0x7A))) {
			if (!values.count(buff)) {
				cout << '\t' << buff << " = ";
				cin >> values[buff];
			}
			trackStack.push(values[buff]);
			continue;
		}

		if (trackStack.isEmpty())
			throw "не соответствует количеству операндов";
		rightOperand = trackStack.pop();
		if (trackStack.isEmpty())
			throw "не соответствует количеству операндов";
		leftOperand = trackStack.pop();

		switch (buff) {
		case '+': {trackStack.push(leftOperand + rightOperand); break; }
		case '-': {trackStack.push(leftOperand - rightOperand); break; }
		case '*': {trackStack.push(leftOperand * rightOperand); break; }
		case '/': {trackStack.push(leftOperand / rightOperand); break; }
		case '=': {return rightOperand;      				   break; }
		}
	}

	float result = trackStack.pop();
	if (!trackStack.isEmpty())
		throw "много операндов!";
	return result;
}