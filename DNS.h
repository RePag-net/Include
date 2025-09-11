/******************************************************************************
MIT License

Copyright(c) 2025 René Pagel

Filename: DNS.h
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
#ifndef DNSH
#define DNSH
//---------------------------------------------------------------------------
constexpr USHORT SV_PAKETGROSSE = 1024;
constexpr USHORT SV_PAKETOFFSET = 16;
constexpr USHORT SV_PAKETGROSSECRYPT = SV_PAKETGROSSE + SV_PAKETOFFSET;
constexpr USHORT SV_SENDRECVBUFFER = SV_PAKETGROSSE + SV_PAKETOFFSET + 4;
//---------------------------------------------------------------------------
#define SRV_PROGSERVER 0
//---------------------------------------------------------------------------
#ifdef DNSLOCAL
	constexpr USHORT PORT_CORE = 5101;
	constexpr USHORT PORT_ADMIN = 5102;
	constexpr USHORT PORT_LOGIN = 5103;
	constexpr USHORT PORT_SERVER = 5104;

	constexpr PCHAR PORT_CORE_STR = "5101";
	constexpr PCHAR PORT_ADMIN_STR = "5102";
	constexpr PCHAR PORT_LOGIN_STR = "5103";
	constexpr PCHAR PORT_SERVER_STR = "5104";

	constexpr PCHAR DNS_COREHOSTNAME = "Dev1";
	constexpr PCHAR DNS_QUORRA = "Dev1";
	constexpr PCHAR DNS_LOGINSERVER_1 = "Dev1";
	constexpr PCHAR DNS_LOGINSERVER_2 = "Dev1";
	constexpr PCHAR DNS_ADMINSERVER_1 = "Dev1";
	constexpr PCHAR DNS_ADMINSERVER_2 = "Dev1";
	constexpr PCHAR DNS_SERVER_1 = "Dev1";
	constexpr PCHAR DNS_SERVER_2 = "Dev1";
#else
	constexpr USHORT PORT_CORE = 5115;
	constexpr USHORT PORT_ADMIN = 5116;
	constexpr USHORT PORT_LOGIN = 5117;
	constexpr USHORT PORT_SERVER = 5118;

	constexpr PCHAR PORT_CORE_STR = "5115";
	constexpr PCHAR PORT_ADMIN_STR = "5116";
	constexpr PCHAR PORT_LOGIN_STR = "5117";
	constexpr PCHAR PORT_SERVER_STR = "5118";

	constexpr PCHAR DNS_COREHOSTNAME = "Dev1-VM-RePag";
	constexpr PCHAR DNS_QUORRA = "core.repag.net";
	constexpr PCHAR DNS_LOGINSERVER_1 = "login1.repag.net";
	constexpr PCHAR DNS_LOGINSERVER_2 = "login2.repag.net";
	constexpr PCHAR DNS_ADMINSERVER_1 = "admin1.repag.net";
	constexpr PCHAR DNS_ADMINSERVER_2 = "admin2.repag.net";
	constexpr PCHAR DNS_SERVER_1 = "server1.repag.net";
	constexpr PCHAR DNS_SERVER_2 = "server2.repag.net";
#endif
//---------------------------------------------------------------------------
#endif

	// D1 v2		/ 1 / 3.5 / 50
	// D2s v3		/ 2 / 8   / 16
	// A2 V2    / 2 / 4  / 20 