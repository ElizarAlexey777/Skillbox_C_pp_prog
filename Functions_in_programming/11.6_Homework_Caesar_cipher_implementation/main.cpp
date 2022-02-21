#include <iostream>

//std::string encrypt_caesar(std::string stroka, int num_sdvig) {
//    std::string encr_stroka;
//    std::string up_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    std::string down_letter = "abcdefghijklmnopqrstuvwxyz";
//
//    while (num_sdvig > 26) {num_sdvig -= 26;}
//
//    for (int i = 0; i < stroka.length(); i++) {
//        if (down_letter.find(stroka[i]) != std::string::npos) {
//            int index_let = down_letter.find(stroka[i]);
//            int cur_stroka;
//            int cur_num_sdvig;
//            if (index_let + num_sdvig >= down_letter.length()) {
//                cur_num_sdvig = num_sdvig - (down_letter.length() - index_let);
//                cur_stroka = 0;
//            } else {
//                cur_num_sdvig = num_sdvig;
//                cur_stroka = index_let;
//            }
//            encr_stroka += down_letter[cur_stroka + cur_num_sdvig];
//        }
//
//        else if (up_letter.find(stroka[i]) != std::string::npos) {
//            int index_let = up_letter.find(stroka[i]);
//            int cur_stroka;
//            int cur_num_sdvig;
//            if (index_let + num_sdvig >= up_letter.length()) {
//                cur_num_sdvig = num_sdvig - (up_letter.length() - index_let);
//                cur_stroka = 0;
//            } else {
//                cur_num_sdvig = num_sdvig;
//                cur_stroka = index_let;
//            }
//            encr_stroka += up_letter[cur_stroka + cur_num_sdvig];
//        }
//
//        else {
//            encr_stroka += stroka[i];
//        }
//    }
//    return encr_stroka;
//}

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