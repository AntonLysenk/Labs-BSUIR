#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class TranscException
{
	double value;
	string opname;
public:
	TranscException(string nameop, double val) : value(val), opname(nameop) {}
	virtual string Message() const = 0;
	void outV() const { cout << "Value: " << value << endl; }
	void outO() const { cout << "Opname: " << opname << endl; }
};

class LogException : public TranscException
{
public:
	LogException(string nameop, double val) : TranscException(nameop, val) {}
	virtual string Message() const { string ex = "LogException"; return ex; }
};

class TrigException : public TranscException
{
public:
	TrigException(string nameop, double val) : TranscException(nameop, val) {}
	virtual string Message() const { string ex = "TrigException"; return ex; }
};

class Trans
{
public:
	double Sin(double angle);
	double Cos(double angle);
	double Tan(double angle);
	double Asin(double value);
	double Acos(double value);
	double Atan(double value);
	double Ln(double value);
	double Lg(double value);
};
