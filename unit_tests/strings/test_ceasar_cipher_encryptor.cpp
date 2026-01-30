#include "strings/ceasar_cipher_encryptor.hpp"
#include <gtest/gtest.h>



TEST(CeasarEncrypt,TrivalCase)
{
EXPECT_EQ(ceasarCipherEncryptor("abc",2),"cde");
}

TEST(CeasarEncrypt,EmptyString)
{
    EXPECT_EQ(ceasarCipherEncryptor("",2),"");
}


TEST(CeasarEncrypt,SpecialCharacters)
{
    EXPECT_EQ(ceasarCipherEncryptor("middle-Outz",2),"okffng-Qwvb");
}


