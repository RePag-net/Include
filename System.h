#ifndef SystemH
#define SystemH
//------------------------------------------------------------------------------------------------------------------------------------------
constexpr PCHAR PIPENAME = "\\\\.\\pipe\\RePagCorePipe_1";
constexpr BYTE PIPEBUFFER = 5;

constexpr BYTE GATE_OK = 0;
constexpr BYTE GATE_KEINUPDATE = 1;
constexpr BYTE GATE_FEHLER_VMBLOCKM_MAPDUPLICATE = 97;
constexpr BYTE GATE_FEHLER_VMBLOCKM_TIMEOUT = 98;
constexpr BYTE GATE_FEHLER_MAPVIEW = 99;
constexpr BYTE GATE_FEHLER = 100;
constexpr BYTE GATE_ZEITENDE = 0xFF;

constexpr BYTE GATE_CORE = 0;
constexpr BYTE GATE_PROZESS = 1;
constexpr BYTE GATE_THREAD = 2;
constexpr BYTE GATE_THREAD_1 = 1;

constexpr BYTE GAES_FEHLER_GLEICHERNAME = 1;
constexpr BYTE GAES_FEHLER_GLEICHENUMMER = 2;
constexpr BYTE GAES_FEHLER_FALSCHESPASSWORT = 3;
constexpr BYTE GAES_FEHLER_UNBEKANNTERNAME = 4;
constexpr BYTE GAES_FEHLER_TRESOR = 5;
constexpr BYTE GAES_FEHLER_SICHERHEIT = 6;
constexpr BYTE GAES_FEHLER_DATEIERSTELLEN = 7;
constexpr BYTE GAES_FEHLER_DATEILESEN = 8;
constexpr BYTE GAES_FEHLER_DATEISCHREIBEN = 9;
constexpr BYTE GASE_FEHLER_COREDOPPEL = 10;
constexpr BYTE GASE_FEHLER_KEINEVERBINDUNG = 11;
constexpr BYTE GASE_FEHLER_DATENBANK = 12;

constexpr BYTE GSYS_FEHLER_VMBLOCKSHARED_VOHANDEN = 9;

constexpr BYTE GREG_GETKEYVALUE = 1;
constexpr BYTE GREG_SETKEYVALUE = 2;

constexpr BYTE AES_FEHLER_CREATETRESOR = 0;
constexpr BYTE AES_FEHLER_NICHTVORHANDEN = 1;
constexpr BYTE AES_FEHLER_SCHLUSSELFEHLER = 2;
constexpr BYTE AES_FEHLER_TRESORVORHANDEN = 3;

constexpr BYTE GSYS_VMCore_PROZESSE = 1; 
constexpr BYTE GSYS_VMCORE_MAPPED = 2;
constexpr BYTE GSYS_VMCORE_SERVER = 3;
constexpr BYTE GSYS_VMCORE_DATABASE = 4;
constexpr BYTE GSYS_VMCORE_PROTOCOL = 5;
constexpr BYTE GSYS_ROOTZERTIFIKAT = 6;
constexpr BYTE GSYS_PROZESSPLATZE = 7;
constexpr BYTE GSYS_UPDATE_INFO = 8;

constexpr BYTE GAES_ADDNEWKEY = 1;
constexpr BYTE GAES_DELETEKEY = 2;
constexpr BYTE GAES_CHANGEKEYNAME = 3;
constexpr BYTE GAES_CHANGEKEYPASSWORD = 4;
constexpr BYTE GAES_GETENCRYPTKEY = 5;
constexpr BYTE GAES_GETDECRYPTKEY = 6;
constexpr BYTE GAES_GETDATABASEKEYSERVER = 7;
constexpr BYTE GAES_TRANSFERKEYTOCOMPUTER_IP = 8;
constexpr BYTE GAES_TRANSFERKEYFROMCOMPUTER_IP = 9;
constexpr BYTE GAES_TRANSFERKEYTOCOMPUTER_NAME = 10;
constexpr BYTE GAES_TRANSFERKEYFROMCOMPUTER_NAME = 11;
constexpr BYTE GAES_COMPLETERESET = 12;
constexpr BYTE GAES_REPAGNETENCRYPT = 13;
constexpr BYTE GAES_REPAGNETDECRYPT = 14;
constexpr BYTE GAES_SELFCORENUMBER = 15;
constexpr BYTE GAES_CORECRYPTKEY = 16;
constexpr BYTE GAES_DNSTOCORE = 17;
constexpr BYTE GAES_LOGINCORE = 18;
constexpr BYTE GAES_CONNECTCORES = 19;

constexpr BYTE HE_Anforderung = 0;
constexpr BYTE HE_Freigabe = 1;
constexpr BYTE HE_Quit = 2;

constexpr BYTE AES_128 = 1;
constexpr BYTE AES_192 = 2;
constexpr BYTE AES_256 = 3;

#define SHA_128 1
#define SHA_256 2
#define SHA_384 3
#define SHA_512 4
//------------------------------------------------------------------------------------------------------------------------------------------
using VMMAPPED = LPVOID;
using VMBLOCKM = char*;
using VMBLOCKA = unsigned char*;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STMapped_Adresse
{
  HANDLE hmMapped;
  VMMAPPED vmmBasisAdresse;
} STMapped_Adresse;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STVMBlockM
{
  VMBLOCKM vbmCore;
  VMBLOCKM vbmDuplicate;
  ULONG ulBytes;
} STVMBlockM;
//------------------------------------------------------------------------------------------------------------------------------------------
typedef struct STVMBlockMEx
{
  VMBLOCKM vbmCore;
  VMBLOCKM vbmDuplicate;
  ULONG ulBytes;
  HANDLE hmMapped_Duplicate;
  ULONG ulOffset;
} STVMBlockMEx;
//------------------------------------------------------------------------------------------------------------------------------------------
struct STGate
{
  struct STGVMBlockM
  {
    HANDLE he2Fertig_Duplicate[2];
    HANDLE hmMapped_Duplicate;
    ULONG ulOffset;
    VMBLOCKM vbmCore;
    ULONG ulBytes;
  }; STGVMBlockM stGVMBlockM;

  struct STGVMBlockShared
  {
    BYTE ucReturn;
    HANDLE he2Fertig_Duplicate[2];
    STVMBlockMEx stmShared;
    STVMBlockM stmName;
    HANDLE heSchreiben_Duplicate[3];
    HANDLE heLesen_Duplicate[3];
  }; STGVMBlockShared stGMBlockShared;

  struct STGVMFreiShared
  {
    BYTE ucReturn;
    HANDLE he2Fertig_Duplicate[2];
    STVMBlockM stmName;
  }; STGVMFreiShared stGVMFreiShared;

  struct STGLogin
  {
    HANDLE hThread_Duplicate;
    STVMBlockM stmLoginSid;
    STVMBlockM stmProgVersion;
    BYTE ucProgNummer;
  }; STGLogin stGLogin;

	struct STGLogout
	{
		HANDLE hThread_Duplicate;
		HANDLE heFertig_Duplicate;
	}; STGLogout stGLogout;

  struct STGSystem
  {
    BYTE ucReturn;
		HANDLE he3Fertig_Duplicate[3];
    BYTE ucAufgabe;
    STVMBlockMEx stmDaten;
  }; STGSystem stGSystem;

  struct STGRegistry
  {
    BYTE ucReturn;
    HANDLE he3Fertig_Duplicate[3];
    BYTE ucAufgabe;
    LONG lSchlussel;
    DWORD dwBytes;
    STVMBlockM stmSchlussel;
    STVMBlockM stmWertName;
    STVMBlockM stmWert_Write;
    STVMBlockMEx stmWert_Read;
    DWORD dwWertTyp;
  }; STGRegistry stGRegistry;

  struct STGAESKey
  {
    BYTE ucReturn;
		HANDLE he3Fertig_Duplicate[3];
    BYTE ucAufgabe;
    STVMBlockMEx stmDaten;
    STVMBlockM stmNamePasswort;
  }; STGAESKey stGAESKey;

};
//---------------------------------------------------------------------------
typedef struct STAES_Key_CBC
{
  alignas(16) BYTE auc256Key[256];
  alignas(16) BYTE auc16IVector[16];
} STAES_Key_CBC;
//---------------------------------------------------------------------------
char* __vectorcall AES_CBC_Encrypt(_In_ const void* vmSpeicher, _In_ const void* pvPlainText, _Inout_ unsigned long& ulBytes,
                                   _In_ unsigned char auc16IVec[16], _In_ unsigned char auc256Key[256]);
char* __vectorcall AES_CBC_Decrypt(_In_ const void* vmSpeicher, _In_ const void* pvChipperText, _Inout_ unsigned long& ulBytes,
                                   _In_ unsigned char auc16IVec[16], _In_ unsigned char auc256Key[256]);
//---------------------------------------------------------------------------
void __vectorcall CPUID(SYSTEM_INFO& stSystem_Info);
//---------------------------------------------------------------------------
#endif