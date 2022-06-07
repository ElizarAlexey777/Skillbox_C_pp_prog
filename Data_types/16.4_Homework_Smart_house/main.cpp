#include <iostream>
#include <sstream>


int state = 0;


enum switches
{
    TOTAL_POWER        = 1 << 0,
    SOCKET_POWER       = 1 << 1,
    LIGHT_INSIDE       = 1 << 2,
    LIGHT_OUTSIDE      = 1 << 3,
    HEATERS            = 1 << 4,
    WATER_PIPE_HEATING = 1 << 5,
    CONDITIONER        = 1 << 6
};


bool convertMovement (std::string movement)
{
    return movement == "yes";
}


bool convertLight (std::string light)
{
    return light == "on";
}


void checkLightInHouse (bool lightOn)
{
    if ((lightOn) && ((state & LIGHT_INSIDE) != LIGHT_INSIDE))
    {
        state |= LIGHT_INSIDE;
        std::cout << "\tLight in house is ON";
    }
    else
    if ((state & LIGHT_INSIDE) == LIGHT_INSIDE)
    {
        state &= ~LIGHT_INSIDE;
        std::cout << "\tLight in house is OFF" << std::endl;
    }
}


void checkTemperatureLight (int time)
{
    int start_time = 16;
    int end_time = 20;
    int high_temperature = 5000;
    int low_temperature = 2700;

    std::cout << "\tIn house light temperature is ";
    if (time < start_time)
        std::cout << high_temperature << 'K' << std::endl;
    else
    if (time < end_time)
        std::cout << high_temperature - ((high_temperature - low_temperature) /
                                         (end_time - start_time) * (time - start_time)) << 'K' << std::endl;
    else
        std::cout << low_temperature << 'K' << std::endl;
}


void checkTemperatureOut (int temperature)
{
    if ((temperature < 0) & ((state & WATER_PIPE_HEATING) != WATER_PIPE_HEATING))
    {
        state |= WATER_PIPE_HEATING;
        std::cout << "\tWater heating is ON" << std::endl;
    }
    else
    if ((temperature > 5) & ((state & WATER_PIPE_HEATING) == WATER_PIPE_HEATING))
    {
        state &= ~WATER_PIPE_HEATING;
        std::cout << "\tWater heating is OFF" << std::endl;
    }
}


void checkTemperatureIn (int temperature)
{
    if ((temperature < 22) & ((state & HEATERS) != HEATERS))
    {
        state |= HEATERS;
        std::cout << "\tHouse heating is ON" << std::endl;
    }
    else
    if ((temperature >= 25) & ((state & HEATERS) == HEATERS))
    {
        state &= ~HEATERS;
        std::cout << "\tHouse heating is OFF" << std::endl;
    }
}


void checkConditioner (int temperature)
{
    if ((temperature >= 30) & ((state & CONDITIONER) != CONDITIONER))
    {
        state |= CONDITIONER;
        std::cout << "\tConditioner is ON" << std::endl;
    }
    else
    if ((temperature <= 25) & ((state & CONDITIONER) == CONDITIONER))
    {
        state &= ~CONDITIONER;
        std::cout << "\tConditioner is OFF" << std::endl;
    }
}


void checkLightOnGarden (int time, bool movement)
{
    if (((time < 5 || time > 16) && movement) &
        ((state & LIGHT_OUTSIDE) != LIGHT_OUTSIDE))
    {
        state |= LIGHT_OUTSIDE;
        std::cout << "\tLight on garden is ON" << std::endl;
    }
    else
    if (((time >= 5 && time <= 16) || !movement) &
        ((state & LIGHT_OUTSIDE) == LIGHT_OUTSIDE))
    {
        state &= ~LIGHT_OUTSIDE;
        std::cout << "\tLight on garden is OFF" << std::endl;
    }
}


void time (int i)
{
    std::cout << "\n\t~~~ Current time is ";
    if (i < 10)
        std::cout << "0" << i;
    else
        std::cout << i;
    std::cout << ":00 ~~~" << std::endl;
}


int main() {
    std::cout << "Smart House" << std::endl;
    std::cout << std::endl;

    const int total_time = 48;

    int temp_in, temp_out;
    bool movement, light_on;

    for (int i = 0; i < total_time; ++i)
    {
        time (i);

        std::cout << "Input temperature outside house, inside house, " << std::endl;
        std::cout << "have outside movement (yes/no), light in house (on/off): ";
        std::string temp;
        getline(std::cin, temp);

        std::stringstream buffer_stream;
        buffer_stream << temp;

        std::string movement_str, light_on_str;
        buffer_stream >> temp_out >> temp_in >> movement_str >> light_on_str;

        light_on = convertLight(light_on_str);
        movement = convertMovement(movement_str);

        checkTemperatureOut(temp_out);
        checkTemperatureIn(temp_in);
        checkLightOnGarden(i % 24, movement);
        checkConditioner(temp_in);
        checkLightInHouse(light_on);
        if (light_on)
            checkTemperatureLight(i % 24);
    }
}