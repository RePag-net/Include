/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: DBTable.h
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
#ifndef DBTabelleH
#define DBTabelleH
#include "Table.h"
#include "ProtocolClient.h"

namespace RePag
{
	namespace GUI
	{
		//---------------------------------------------------------------------------------------------------------------------------------------
		class CODBTabelle : public COTabBasis
		{
			friend bool __vectorcall frDSSenden(COTabBasis* pTabelle);
			friend bool __vectorcall frServerVerbunden(COTabBasis* pTabelle);

		private:
			COServer* vServer;
			unsigned char ucDBTabelleServer;
			bool __vectorcall DSSenden(void);
			void __vectorcall Fehler_SF_KEINESITZUNG(COStringA* pasMeldung);
			void __vectorcall Fehler_SF_KEINRECHT(COStringA* pasMeldung);
			void __vectorcall Fehler_DB_FEHLER(COStringA* pasMeldung);
			void __vectorcall Fehler_DB_KEINEDATEN(COStringA* pasMeldung);
			void __vectorcall Fehler_SF_ZEITENDE(COStringA* pasMeldung);
			void __vectorcall Fehler_SF_SYSTEMFEHLER(COStringA* pasMeldung);
			void __vectorcall Fehler_DB_KEINEANDERUNG(COStringA* pasMeldung);
			void __vectorcall Fehler_DB_GEANDERTEDATEN(COStringA* pasMeldung);
			void __vectorcall Fehler_DB_KEINSUCHPARAM(COStringA* pasMeldung);
			void __vectorcall Fehler_PF_ABBRUCH(COStringA* pasMeldung);

		protected:

		public:
			void __vectorcall CODBTabelleV(VMEMORY vmSpeicher, const char* pcFensterName, unsigned int uiIDElement, COServer* vServerA, unsigned long ulZeilen_Blatt, unsigned char ucSpalten);
			VMEMORY __vectorcall COFreiV(void);
			void __vectorcall TabErstellen(COProtokollClient* vProtokollClient);
			void __vectorcall Abfrage(void);
			void __vectorcall Spalte(unsigned char ucSpalte, const char* pcBeschriftung, long lBreite, unsigned short usFormat);
			void __vectorcall DBLesen(bool bWiederholen);
			bool __vectorcall DSEinfugen(void* pthstDSEinfugen_Fehler);
			bool __vectorcall DSAndern(void* pthstDSAndern_Fehler);
			bool __vectorcall DSLoschen(void* pthstDSLoschen_Fehler);
			COStream* vsmSuchParam;
			COStringA* vasLogbuchName;
			unsigned char ucSuchAufgabe;
			unsigned char ucServer;
			HANDLE heFertig;

		};
		//---------------------------------------------------------------------------------------------------------------------------------------
		CODBTabelle* __vectorcall CODBTabelleV(const char* pcFensterName, unsigned int uiIDElement, COServer* vServer, unsigned long ulZeilen_Blatt, unsigned char ucSpalten);
		CODBTabelle* __vectorcall CODBTabelleV(VMEMORY vmSpeicher, const char* pcFensterName, unsigned int uiIDElement, COServer* vServerA, unsigned long ulZeilen_Blatt, unsigned char ucSpalten);
		//---------------------------------------------------------------------------------------------------------------------------------------
	}
}
#endif