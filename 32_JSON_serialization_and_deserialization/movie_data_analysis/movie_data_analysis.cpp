#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <iomanip>
#include <filesystem>

using json = nlohmann::json;
namespace fs = std::filesystem;

void create_json_file() {
    json films = {
        {"Король и Шут", {
            {"country", "Россия"},
            {"release_date", "2023-03-02"},
            {"production_company", "Kinoslovo"},
            {"director", "Рустам Мосафир"},
            {"producers", {"Евгений Бедарев", "Александр Цекало"}},
            {"screenwriters", {"Дмитрий Ларин", "Елена Ванина"}},
            {"cast", {
                {{"character", "Михаил 'Горшок' Горшенёв"}, {"actor", "Константин Плотников"}},
                {{"character", "Андрей 'Князь' Князев"}, {"actor", "Влад Коноплёв"}},
                {{"character", "Александр Балунов"}, {"actor", "Егор Клинаев"}}
            }},
            {"plot_summary", "Сериал о жизни и творчестве культовой российской панк-группы «Король и Шут»."}
        }},
        {"Оффлайн", {
            {"country", "Россия"},
            {"release_date", "2022-04-15"},
            {"production_company", "Kion"},
            {"director", "Сергей Сенцов"},
            {"producers", {"Екатерина Островская", "Пётр Ануров"}},
            {"screenwriters", {"Юлия Купавцева", "Иван Дымов"}},
            {"cast", {
                {{"character", "Сергей Горелов"}, {"actor", "Евгений Кулик"}},
                {{"character", "Олег"}, {"actor", "Глеб Калюжный"}},
                {{"character", "Катя"}, {"actor", "Анастасия Калашникова"}}
            }},
            {"plot_summary", "История о том, как отключение интернета меняет жизнь людей."}
        }},
        {"Оффлайн 2", {
            {"country", "Россия"},
            {"release_date", "2023-04-22"},
            {"production_company", "Kion"},
            {"director", "Сергей Сенцов"},
            {"producers", {"Екатерина Островская", "Пётр Ануров"}},
            {"screenwriters", {"Юлия Купавцева", "Иван Дымов"}},
            {"cast", {
                {{"character", "Сергей Горелов"}, {"actor", "Евгений Кулик"}},
                {{"character", "Олег"}, {"actor", "Глеб Калюжный"}},
                {{"character", "Катя"}, {"actor", "Анастасия Калашникова"}}
            }},
            {"plot_summary", "Продолжение истории о жизни без интернета."}
        }},
        {"Вызов", {
            {"country", "Россия"},
            {"release_date", "2023-10-12"},
            {"production_company", "Централ Партнершип"},
            {"director", "Клим Шипенко"},
            {"producers", {"Тимур Бекмамбетов", "Василий Сигарев"}},
            {"screenwriters", {"Екатерина Краснер", "Олег Маловичко"}},
            {"cast", {
                {{"character", "Евгения Михайлова"}, {"actor", "Юлия Пересильд"}},
                {{"character", "Дмитрий Николаев"}, {"actor", "Владимир Машков"}},
                {{"character", "Алексей"}, {"actor", "Олег Новицкий"}}
            }},
            {"plot_summary", "История о первой женщине-космонавте, снимающей фильм на МКС."}
        }},
        {"Лед 3", {
            {"country", "Россия"},
            {"release_date", "2024-01-01"},
            {"production_company", "Art Pictures Studio"},
            {"director", "Жора Крыжовников"},
            {"producers", {"Фёдор Бондарчук", "Дмитрий Рудовский"}},
            {"screenwriters", {"Андрей Золотарев", "Олег Маловичко"}},
            {"cast", {
                {{"character", "Надежда Горина"}, {"actor", "Анна Савранская"}},
                {{"character", "Александр Горин"}, {"actor", "Александр Петров"}},
                {{"character", "Сергей Орлов"}, {"actor", "Степан Белозёров"}}
            }},
            {"plot_summary", "История о жизни и спортивной карьере фигуристки."}
        }}
    };

    std::ofstream file("films.json");
    if (file.is_open()) {
        file << std::setw(4) << films << std::endl;
        file.close();
        std::cout << "Файл 'films.json' успешно создан" << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи" << std::endl;
    }
}

void search_actor_in_json() {
    std::ifstream file("films.json");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return;
    }

    json films;
    file >> films;
    file.close();

    std::string actor_name;
    std::cout << "Введите имя или фамилию актера для поиска: ";
    getline(std::cin, actor_name);

    std::vector<std::string> found_films;

    for (const auto& [title, film] : films.items()) {
        for (const auto& cast_member : film["cast"]) {
            if (cast_member["actor"].get<std::string>().find(actor_name) != std::string::npos) {
                found_films.push_back(title + " - " + cast_member["character"].get<std::string>());
            }
        }
    }

    if (found_films.empty()) {
        std::cout << "Актер не найден в базе данных" << std::endl;
    } else {
        std::cout << "Актер снялся в следующих фильмах:" << std::endl;
        for (const auto& entry : found_films) {
            std::cout << entry << std::endl;
        }
    }
}

int main() {
    if (!fs::exists("films.json")) {
        create_json_file();
    } else {
        std::cout << "Файл 'films.json' уже существует" << std::endl;
    }

    search_actor_in_json();

    return 0;
}
