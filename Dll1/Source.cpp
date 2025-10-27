#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<algorithm>
#include<cmath>
#include<memory>
#include<set>

#include"Transport.h"
#include"Ground.h"
#include "Flying.h"
#include "Camel.h"
#include "FastCamel.h"
#include"Centaur.h"
#include"Boots.h"
#include"Carpet.h"
#include"Eagle.h"
#include"Broom.h"
#include"HelpsElem.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	bool isProgramRun{ true };
	while (isProgramRun)
	{
		std::vector<std::unique_ptr<Transport>>createPlayers;
		std::set<std::string>playersName;

		int raceType{};
		double distance{};

		system("cls");

		std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl
			<< "1. Гонка для наземного транспорта" << std::endl
			<< "2. Гонка для воздушного транспорта" << std::endl
			<< "3. Гонка для воздушного и наземного транспорта" << std::endl
			<< "Выберите тип гонки: ";
		raceType = getChoise("", 1, 3);

		system("cls");

		std::cout << "Укажите длину дистанции: ";
		while (!(std::cin >> distance) || distance <= 0)
		{
			std::cout << "Ошибка: Введите положительное число для дистанции: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");

		std::cout << "Для начала гонки необходимо зарегистрировать минимум двух участников.";

		int choice{};
		do
		{
			std::cout << "\n--- Выберите транспорт для регистрации ---" << std::endl;
			std::cout << "1. Ботинки-вездеходы" << std::endl
			          << "2. Метла" << std::endl
				      << "3. Верблюд" << std::endl
				      << "4. Кентавр" << std::endl
				      << "5. Орел" << std::endl
				      << "6. Верблюд-быстроход" << std::endl
				      << "7. Ковер-самолет" << std::endl
				      << "0. Завершить регистрацию" << std::endl;

			choice = getChoise("Ваш выбор: ", 0, 7);

			if (choice != 0)
			{
				std::unique_ptr<Transport>newPlayer = createPlayer(choice); 

				if (newPlayer)
				{
					if (playersName.count(newPlayer->getName()) > 0)
					{
						std::cout << "Ошибка: Транспортное средство '" << newPlayer->getName()
							      << "' уже зарегистрировано. Выберите другое." << std::endl;
					}
					else
					{
						bool isValidRace = false;
						switch (raceType)
						{
						case 1:
							isValidRace = (dynamic_cast<Ground*>(newPlayer.get())) != nullptr;
							break;
						case 2:
							isValidRace = (dynamic_cast<Flying*>(newPlayer.get())) != nullptr;
							break;
						case 3:
							isValidRace = true;
							break;
						}
						
						system("cls");

						if (isValidRace)
						{
							std::cout << newPlayer->getName() << " успешно зарегистрирован." << std::endl;
							playersName.insert(newPlayer->getName());
							createPlayers.push_back(std::move(newPlayer));

							std::cout << "\n--- Зарегистрированные участники (" << createPlayers.size() << " ТС) ---" << std::endl;
							for (const auto& p : createPlayers)
							{
								
								p->displayInfo();
								std::cout << std::endl;
							}
							
						}
						else
						{
							std::cout << "Ошибка: " << newPlayer->getName()
								      << " не подходит для выбранного типа гонки. Попробуйте снова." << std::endl;
						}
					}

				}
				else
				{
					std::cout << "Ошибка: Не удалось создать транспортное средство. Попробуйте снова." << std::endl;
				}
			}
			else
			{
				choice = 0;
				if (createPlayers.size() < 2)
				{
					std::cout << "Ошибка: Зарегистрировано " << createPlayers.size()
						      << " ТС. Для гонки требуется минимум 2 ТС. Продолжите регистрацию." << std::endl;
					choice = -1;
				}
				else
				{
					std::cout << "Регистрация завершена. Приступаем к гонке!" << std::endl;
				}
			}
		} while (choice != 0 || createPlayers.size() < 2);

		system("cls");

		std::cout << "\n--- Зарегистрированные участники (" << createPlayers.size() << " ТС) ---" << std::endl;

		for (const auto& p : createPlayers)
		{
			p->displayInfo();
			std::cout << std::endl;
		}
		std::cout << "\n--- Результаты гонки на дистанцию " << distance << " км ---" << std::endl;

		if (createPlayers.empty())
		{
			std::cout << "Нет участников для гонки. Программа завершена." << std::endl;
			isProgramRun = false;
			break;
		}
		std::vector<std::pair<double, const Transport*>> results;
		for (const auto& p : createPlayers)
		{
			double time = p->calculateTime(distance);
			results.push_back({ time,p.get() });
		}

		std::sort(results.begin(), results.end(), [](const auto& a, const auto& b)
		{
			return a.first < b.first;
		});

		for (size_t i = 0; i < results.size(); ++i)
		{
			std::cout << i + 1 << ". " << results[i].second->getName()
				      << " - время: " << results[i].first  << std::endl;
		}
		std::cout << "\nПобедитель: " << results[0].second->getName()
			      << " со временем " << results[0].first << std::endl;

		std::cout << "\n----------------------------------------" << std::endl;
		std::cout << "Провести еще одну гонку? (1 - Да, 0 - Нет): ";

		int choice_run_again = getChoise("", 0, 1);
		if (choice_run_again == 0)
		{
			isProgramRun = false;

		}
		std::cout << "Спасибо за участие в симуляторе гонок!" << std::endl;

	}
	return 0;
}

