/// <author>
/// zNova
/// </author>
#include <Windows.h> 
#include <iostream>

UINT __fastcall XorStringDecryption(const uint8_t* EncryptedString, const uint8_t* XorKey, uint8_t* DecryptedString, UINT XorIterator)
{
    UINT ret = 0; // rax
    for (int i = 0; i < XorIterator; i++)
    {
        ret = (unsigned int)i;

        char xorKey = XorKey[i];
        DecryptedString[i] = EncryptedString[i % strlen(reinterpret_cast<const char*>(EncryptedString))] ^ xorKey;
    }
    return ret;
}

//Note: We're using hard-coded struct size to match the encrypted string size

struct StrEnc
{
    uintptr_t v1;
    UINT v2; 
};

struct StrEnc1
{
    uintptr_t v1;
    uintptr_t v2;
    uintptr_t v3;
    uintptr_t v4;
    UINT v5;
    UINT v6;
};

struct StrEnc2
{
    uintptr_t v1;
    uintptr_t v2;
    UINT v3;
    UINT v4;
    UINT v5;
};

struct StrEnc3
{
    uintptr_t v1;
    uintptr_t v2;
    UINT v3;
};

int main(void)
{
    StrEnc FirstStrEnc{
        0x6969696969696969,0x6969
    };

    StrEnc FirstStrKey{
        0x115911125E582A3B,0x3659
    };


    uint8_t FirstStr[1024];

    XorStringDecryption((const uint8_t*)&FirstStrEnc, (const uint8_t*)&FirstStrKey, FirstStr, 10);

    std::cout << "First Encrypted String: " << FirstStr << std::endl;

    StrEnc1 SecondEncKey{
    0xB59100F175F3600,0xC14584363213E10,0x174526357F5F0C10,0x243333565855100F,0x72520D11,0x30
    };

    uint8_t SecondStr[1024];

    XorStringDecryption((const uint8_t*)&FirstStr, (const uint8_t*)&SecondEncKey, SecondStr, 37);//The first decrypted string is reused here as encrypted string xD 
    std::cout << "Second Encrypted String: " << SecondStr; //the string itself has \n at the end


    StrEnc2 StrLast{ 0x747261705F746F6E , 0x67616C665F666F5F,0x6B61665F,0x7265,0x7A };

    StrEnc3 StrLastKey{ 0x470A0444271C1B31 , 0xF150B086E121A3C,0x4B1C156E };

    uint8_t LastStr[1024];

    XorStringDecryption((const uint8_t*)&StrLast, (const uint8_t*)&StrLastKey, LastStr, 21);
    std::cout << "Last Encrypted String: " << LastStr << std::endl;

    std::cin.get();
    return 0;
}
