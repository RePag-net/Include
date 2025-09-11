/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: Rights.h
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
#ifndef RightsH
#define RightsH

constexpr BYTE ZR_KEINE = 0;
constexpr BYTE ZR_LESEN = 1;
constexpr BYTE ZR_OFFNEN = 1;
constexpr BYTE ZR_EINFUGEN = 2;
constexpr BYTE ZR_ANDERN = 4;
constexpr BYTE ZR_LADEN = 4;
constexpr BYTE ZR_LOSCHEN = 8;
constexpr BYTE ZR_SENDEN = 16;
constexpr BYTE ZR_SPEICHERN = 32;
constexpr BYTE ZR_SONDER_1 = 16;
constexpr BYTE ZR_SONDER_2 = 32;
constexpr BYTE ZR_SONDER_3 = 64;
constexpr BYTE ZR_SONDER_4 = 128;
//--------------------------------------------------------------------------------------------------------------------------------------------
#endif