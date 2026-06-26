#ifndef _NUM_CONSTANTS_H_
#define _NUM_CONSTANTS_H_

//---------------------------------------------------------------------------------
// regular value
//---------------------------------------------------------------------------------

const _REGULAR_VALUE_ = 32;

//---------------------------------------------------------------------------------
// 8 bit integer constants
//---------------------------------------------------------------------------------
const char _MIN_SIGNED_8BIT_INTEGER_   = -128;
const char _MAX_SIGNED_8BIT_INTEGER_   = 127;
const char _VAL_SIGNED_8BIT_INTEGER_   = 32;
const unsigned char _MIN_UNSIGNED_8BIT_INTEGER_ = 0;
const unsigned char _MAX_UNSIGNED_8BIT_INTEGER_ = 255;
const unsigned char _VAL_UNSIGNED_8BIT_INTEGER_ = 4;
//---------------------------------------------------------------------------------
// 16 bit integer constants
//---------------------------------------------------------------------------------
const short _MIN_SIGNED_16BIT_INTEGER_   = -32768;
const short _MAX_SIGNED_16BIT_INTEGER_   = 32767;
const short _VAL_SIGNED_16BIT_INTEGER_   = 32;
const unsigned short _MIN_UNSIGNED_16BIT_INTEGER_ = 0;
const unsigned short _MAX_UNSIGNED_16BIT_INTEGER_ = 65535;
const unsigned short _VAL_UNSIGNED_16BIT_INTEGER_ = 4;
//---------------------------------------------------------------------------------
// 32 bit integer constants
//---------------------------------------------------------------------------------
const int _MIN_SIGNED_32BIT_INTEGER_   = -2147483648;
const int _MAX_SIGNED_32BIT_INTEGER_   = 2147483647;
const int _VAL_SIGNED_32BIT_INTEGER_   = 32;
const unsigned int _MIN_UNSIGNED_32BIT_INTEGER_ = 0;
const unsigned int _MAX_UNSIGNED_32BIT_INTEGER_ = 4294967295;
const unsigned int _VAL_UNSIGNED_32BIT_INTEGER_ = 4;
//---------------------------------------------------------------------------------
// 32 bit real constants
//---------------------------------------------------------------------------------
//const float _MIN_32BIT_REAL_   = -3.40282E+38; Doesn't compile correctly
//const float _MAX_32BIT_REAL_   = 3.40282E+38;  Doesn't compile correctly
const float _VAL_32BIT_REAL_   = 32.0;
//---------------------------------------------------------------------------------
// 64 bit real constants
//---------------------------------------------------------------------------------
const double _MIN_64BIT_REAL_   = -1.79769E+308;
const double _MAX_64BIT_REAL_   = 1.79769E+308;
const double _VAL_64BIT_REAL_   = 32.0;
//---------------------------------------------------------------------------------
// 64 bit integer constants
//---------------------------------------------------------------------------------
const __int64 _MIN_SIGNED_64BIT_INTEGER_   = -9223372036854775808;
const __int64 _MAX_SIGNED_64BIT_INTEGER_   = 9223372036854775807;
const __int64 _VAL_SIGNED_64BIT_INTEGER_   = 32;
const unsigned __int64 _MIN_UNSIGNED_64BIT_INTEGER_ = 0;
const unsigned __int64 _MAX_UNSIGNED_64BIT_INTEGER_ = 18446744073709551615;
const unsigned __int64 _VAL_UNSIGNED_64BIT_INTEGER_ = 4;

#endif
