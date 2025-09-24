#ifndef __TOOLKIT__DOUBLE_ROUND_H
#define __TOOLKIT__DOUBLE_ROUND_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// on ajoute 0.5 à la valeur a cause d'un bug de cast
// cf MSDN ID: Q48928 , ou Article ID: Q12297
#define DOUBLETOLONG(d)		((long) ((d) + ((d) > 0 ? 0.5 : -0.5)))

//DOUBLETOLONG implemented as inline function
inline long DoubleToLong(double val) {
	return long(val + (val >= 0 ? 0.5 : -0.5));
}

double RoundAsymArith(double val, double factor);
double RoundSymArith(double val, double factor);

#endif // __TOOLKIT__DOUBLE_ROUND_H