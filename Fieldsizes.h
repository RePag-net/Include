/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Fieldsizes.h
For more information see https://github.com/RePag-net/Include

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/
#ifndef FieldsizesH
#define FieldsizesH
//-------------------------------------------------------------------------------------------------------------------------------------------
constexpr unsigned char FT_EMPTY = 0;
constexpr unsigned char FT_SHORTSTR = 1;
constexpr unsigned char FT_LONGSTR = 2;
constexpr unsigned char FT_MEMOSTR = 3;
constexpr unsigned char FT_LISTSTR = 4;
constexpr unsigned char FT_BOOL = 5;
constexpr unsigned char FT_CHAR = 6;
constexpr unsigned char FT_BYTE = 7;
constexpr unsigned char FT_SHORT = 8;
constexpr unsigned char FT_USHORT = 9;
constexpr unsigned char FT_LONG = 10;
constexpr unsigned char FT_ULONG = 11;
constexpr unsigned char FT_LONGLONG = 12;
constexpr unsigned char FT_FLOAT = 13;
constexpr unsigned char FT_DOUBLE = 14;
constexpr unsigned char FT_COMMA4 = 15;
constexpr unsigned char FT_COMMA4_80 = 16;
constexpr unsigned char FT_TIME = 17;
constexpr unsigned char FT_SMALLIMAGE = 18;
constexpr unsigned char FT_BIGIMAGE = 19;
constexpr unsigned char FT_DOCUMENT = 20;
constexpr unsigned char FT_AUDIO = 21;
constexpr unsigned char FT_VIDEO = 22;
constexpr unsigned char FT_DATE = 23;
constexpr unsigned char FT_BIT128 = 24;
constexpr unsigned char FT_BIT256 = 25;

constexpr unsigned char FT_SORTDOWN = 32;
constexpr unsigned char FT_SORTUP = 64;
constexpr unsigned char FT_KEY = 128;
//-------------------------------------------------------------------------------------------------------------------------------------------
constexpr unsigned char AT_NOCRYPT = 0;
constexpr unsigned char AT_CRYPT = 1;

//-------------------------------------------------------------------------------------------------------------------------------------------
constexpr unsigned char BY_NULL = 0;
constexpr unsigned char BY_BOOL = 1;
constexpr unsigned char BY_CHAR = 1;
constexpr unsigned char BY_BYTE = 1;
constexpr unsigned char BY_USHORT = 2;
constexpr unsigned char BY_SHORT = 2;
constexpr unsigned char BY_INT = 4;
constexpr unsigned char BY_UINT = 4;
constexpr unsigned char BY_LONG = 4;
constexpr unsigned char BY_ULONG = 4;
constexpr unsigned char BY_FLOAT = 4;
constexpr unsigned char BY_COMMA4 = 6;
constexpr unsigned char BY_COMMA4_80 = 10;
constexpr unsigned char BY_TIME = 8;
constexpr unsigned char BY_DOUBLE = 8;
constexpr unsigned char BY_LONGLONG = 8;
constexpr unsigned char BY_DATE = 8;
constexpr unsigned char BY_BIT128 = 16;
constexpr unsigned char BY_BIT256 = 32;
//-------------------------------------------------------------------------------------------------------------------------------------------
#endif