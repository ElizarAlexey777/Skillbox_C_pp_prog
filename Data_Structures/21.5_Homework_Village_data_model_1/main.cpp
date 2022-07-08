#include <iostream>
#include <string>
#include <vector>

enum type_room {
    BEDROOM = 1,
    KITCHEN = 2,
    BATHROOM = 3,
    NURSERY = 4,
    LIVING_ROOM = 5,
};

struct rooms {
    int room_area;
    int room_type;
};

struct floors {
    int floor_height;
    int quantity_of_rooms;
    std::vector<rooms> room;
};

struct in_house {
    int house_area;
    int q_floors;
    bool bake;
    std::vector<floors> floor;
};

struct oth_builds{
    std::string names;
    int area_build;
    bool stove = false;
};

struct areas_buildings {
    std::vector<in_house> houses;
    std::vector<oth_builds> builds;
};

void house(int & sum_area, int number_plots, areas_buildings & area_building) {
    int total_houses = 0;
    in_house home;
    for (int cur_num_build = 0; cur_num_build < number_plots; cur_num_build++){
        std::cout << "What is the area of the house?" << std::endl;
        std::cin >> home.house_area;
        sum_area += home.house_area;
        std::cout << "How many floors are there in the house?" << std::endl;
        std::cin >> home.q_floors;
        std::cout << "Is there a stove in the house? (1 / 0)";
        std::cin >> home.bake;
        for (int cur_num_floor = 0; cur_num_floor < home.q_floors; cur_num_floor++){
            floors additional_floor;
            std::cout << "What is the height of the floor " << cur_num_floor + 1 << "?\n";
            std::cin >> additional_floor.floor_height;
            std::cout << "How many rooms are on the floor " << cur_num_floor + 1 << "?\n";
            std::cin >> additional_floor.quantity_of_rooms;
            for (int cur_num_room = 0; cur_num_room < additional_floor.quantity_of_rooms; cur_num_room++){
                rooms r_a;
                std::cout << "What is the area of the room #" << cur_num_room + 1 << "?" << std::endl;
                std::cin >> r_a.room_area;
                total_houses += r_a.room_area * additional_floor.floor_height;
                std::cout << "What type of room?" << std::endl;
                std::cout << "1) bedroom\n2) kitchen\n3) bathroom\n4) nursery\n5) living room" << std::endl;
                std::cin >> r_a.room_type;
                additional_floor.room.push_back(r_a);
            }
            home.floor.push_back(additional_floor);
        }
        area_building.houses.push_back(home);
    }
    if (total_houses == home.house_area) {
        std::cout << "The area of the house and the total area of the rooms are equal" << std::endl;
    }
    else std::cout << "The area of the house and the total area of the rooms are not equal" << std::endl;
}

void other_buildings(areas_buildings & all, const int & number_plots, int & sum_area, const std::string & name_building, bool stove_bath = false){
    oth_builds other;
    other.names = name_building;
    std::cout << "What is the size of the " << name_building << "?\n";
    std::cin >> other.area_build;
    sum_area += other.area_build;
    if (stove_bath) {
        std::cout << "Is there a stove in the bath? (1 / 0)" << std::endl;
        std::cin >> other.stove;
    }
    all.builds.push_back(other);
}

void plot_info(int & sum_area, int number_plots, areas_buildings & area_building){
    bool answer;
    house(sum_area, number_plots, area_building);
    std::cout << "Is there a garage on the site " << number_plots + 1 << "? (1 / 0)" << std::endl;
    std::cin >> answer;
    if (answer) other_buildings(area_building, number_plots, sum_area, "garage");
    std::cout << "Is there a barn on the site " << number_plots + 1 << "? (1 / 0)" << std::endl;
    std::cin >> answer;
    if (answer) other_buildings(area_building, number_plots, sum_area, "barn");
    std::cout << "Is there a bath on the site " << number_plots + 1 << "? (1 / 0)" << std::endl;
    std::cin >> answer;
    if (answer) other_buildings(area_building, number_plots, sum_area, "bath",true);
}


int main() {
    std::cout << "Village data model" << std::endl;
    std::cout << std::endl;
    std::vector<areas_buildings> all;

    int all_area, number_plots;

    std::cout << "What is the area of the village?" << std::endl;
    std::cin >> all_area;

    std::cout << "Enter the total number of plots in the village:" << std::endl;
    std::cin >> number_plots;

    int sum_area = 0;

    for (int i = 0; i < number_plots; i++){
        areas_buildings area_building;
        plot_info(sum_area, number_plots, area_building);
        all.push_back(area_building);
    }
    std::cout << "The area of buildings is " << 100 * (static_cast<float>(sum_area)/all_area) << "% of the area of the village" << std::endl;
}