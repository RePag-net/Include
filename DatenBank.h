/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: DatenBank.h
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
#ifndef DatenbankH
#define DatenbankH
//-------------------------------------------------------------------------------------------------------------------------------------------
#define DB_SpinCount 1000
#ifndef _64bit
#define BY_STDBSatz 32
#else
#define BY_STDBSatz 56
#endif

#define _Datensatz ((STDBSatz*)vstTabellen[ucTabelle].vlTabelle->Element(pvDatenSatz))
#define _Datenfeld ((STDBSatz*)vstTabellen[ucTabelle].vlTabelle->Element(pvDatenSatz))->vstDBFelder[ucSpalte].stFeld
#define _Datensatz_Andern ((STDBSatz*)vstTabellen[stDSAndern.ucTabelle].vlTabelle->Element(stDSAndern.pvDatenSatz))
#define _Datenfeld_Andern ((STDBSatz*)vstTabellen[stDSAndern.ucTabelle].vlTabelle->Element(stDSAndern.pvDatenSatz))->vstDBFelder[ucSpalte].stFeld
#define _Datensatz_Loschen ((STDBSatz*)vstTabellen[stDSLoschen.ucTabelle].vlTabelle->Element(stDSLoschen.pvDatenSatz))
#define _Datenfeld_Loschen ((STDBSatz*)vstTabellen[stDSLoschen.ucTabelle].vlTabelle->Element(stDSLoschen.pvDatenSatz))->vstDBFelder[ucSpalte].stFeld
#define _Datensatz_Einfugen ((STDBSatz*)vstTabellen[stDSEinfugen.ucTabelle].vlTabelle->Element(stDSEinfugen.pvDatenSatz))
#define _Datenfeld_Einfugen ((STDBSatz*)vstTabellen[stDSEinfugen.ucTabelle].vlTabelle->Element(stDSEinfugen.pvDatenSatz))->vstDBFelder[ucSpalte].stFeld
extern char cKeinLoschzugriff[];
extern char cKeinSchreibzugriff[];
extern char cKeinLesezugriff[];
extern char cDBEngine[];
//-------------------------------------------------------------------------------------------------------------------------------------------
#endif