#include <iostream>

std::string encrypt_caesar(std::string stroka, int num_sdvig) {
    std::string encr_stroka;
    encr_stroka = stroka;
    while (num_sdvig > 26) {num_sdvig -= 26;}

    for (int i = 0; i < stroka.length(); i++){
        encr_stroka[i] = stroka[i] + num_sdvig;
        if (stroka[i] <= 'Z'){
            if (encr_stroka[i] > 'Z'){
                encr_stroka[i] = 'A' + (encr_stroka[i] - 'Z') - 1;

            }
            if (encr_stroka[i] < 'A'){
                encr_stroka[i] = 'Z' - ('A' - encr_stroka[i]) + 1;
            }
        }
        if (stroka[i] >= 'a'){
            if ((encr_stroka[i] > 'z') || (int) encr_stroka[i] < 0){
                encr_stroka[i] = 'a' + ((encr_stroka[i] - 'z') - 1);
            }
            if (encr_stroka[i] < 'a'){
                encr_stroka[i]= 'z' - ('a' - encr_stroka[i]) + 1;
            }
        }
        if (stroka[i] == ' '){
            encr_stroka[i] = stroka[i];
        }
    }
    return encr_stroka;
}


std::string decrypt_caesar(std::string stroka, int num_sdvig) {
    stroka = encrypt_caesar(stroka, -num_sdvig);
    return stroka;
}

int main() {
    std::cout << "Caesar cipher implementation" << std::endl;
    std::cout << std::endl;

    std::string stroka;
    int num_sdvig;

    std::cout << "Enter the original string: " << std::endl;
    std::getline(std::cin, stroka);

    std::cout << "Enter numeric shift: " << std::endl;
    std::cin >> num_sdvig;

    if (num_sdvig < 0) {
        std::cout << "Invalid data" << std::endl;
        return -1;
    }

    std::cout << "The original string in Caesar cipher:" << std::endl;
    std::cout << encrypt_caesar(stroka, num_sdvig) << std::endl;
    std::cout << std::endl;

    std::cout << "Reverse transformation: from the Caesar cipher to the original string:" << std::endl;
    std::cout << decrypt_caesar(encrypt_caesar(stroka, num_sdvig), num_sdvig) << std::endl;
    std::cout << std::endl;
    return 0;
}