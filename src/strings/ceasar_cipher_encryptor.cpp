#include <string>
#include "strings/ceasar_cipher_encryptor.hpp"

 //Implement your ceasar_cipher_encryptor logic here.


std::string ceasarCipherEncryptor(const std::string& order,int k){
    k %= 26;
    std::string encryptedMess = "";
    if (order.empty()) return "";
    for (unsigned char uch: order) {
        if ('a' <= uch && uch <= 'z') {
            encryptedMess += char('a' + (uch - 'a' + k) % 26); //uch -a->number, (uch -'a'+k)%26
        } else if ('A' <= uch && uch <= 'Z') {
            encryptedMess += char('A' + (uch - 'A' + k) % 26);
        } else {
            encryptedMess += char(uch);
        }
    }
    return encryptedMess;
}
