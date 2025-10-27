#include"pch.h"
#include"HelpsElem.h"

int getChoise(const std::string name, int min , int max)
{
    int choice{};
    bool isValid = false;
    do {
        std::cout << name;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (choice >= min && choice <= max) {
            isValid = true;
        }
        else {
            std::cout << "Ошибка: Введите число от " << min << " до " << max << " включительно." << std::endl;
        }
    } while (!isValid);
    return choice;
}

std::unique_ptr<Transport> createPlayer(int choice)
{
    if (choice == 1) return std::make_unique<Boots>();
    if (choice == 2) return std::make_unique<Broom>();
    if (choice == 3) return std::make_unique<Camel>();
    if (choice == 4) return std::make_unique<Centaur>();
    if (choice == 5) return std::make_unique<Eagle>();
    if (choice == 6) return std::make_unique<FastCamel>();
    if (choice == 7) return std::make_unique<Carpet>();
    return nullptr;
}