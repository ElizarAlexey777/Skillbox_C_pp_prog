#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    json data = {
        {"title", "Король и Шут"},
        {"country", "Россия"},
        {"release_date", "2023-03-02"},
        {"production_company", "Kinoslovo"},
        {"director", "Рустам Мосафир"},
        {"producers", {"Евгений Бедарев", "Александр Цекало"}},
        {"screenwriters", {"Дмитрий Ларин", "Елена Ванина"}},
        {"cast", {
            {{"character", "Михаил 'Горшок' Горшенёв"}, {"actor", "Константин Плотников"}},
            {{"character", "Андрей 'Князь' Князев"}, {"actor", "Влад Коноплёв"}},
            {{"character", "Александр Балунов"}, {"actor", "Егор Клинаев"}},
            {{"character", "Яков Цвиркунов"}, {"actor", "Иван Васильев"}},
            {{"character", "Мария 'Маша' Нефёдова"}, {"actor", "Вера Строкова"}},
            {{"character", "Наталья Горшенева"}, {"actor", "Агата Муцениеце"}}
        }},
        {"plot_summary", "Сериал о жизни и творчестве культовой российской панк-группы «Король и Шут», а также о личной драме ее участников. В сериале переплетаются реальные события и фантастические сюжеты песен группы."}
    };

    std::ofstream file("korol_i_shut.json");
    if (file.is_open()) {
        file << std::setw(4) << data << std::endl;
        file.close();
        std::cout << "Файл 'korol_i_shut.json' успешно создан." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }

    return 0;
}
