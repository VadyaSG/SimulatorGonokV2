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

		std::cout << "����� ���������� � �������� ���������!" << std::endl
			<< "1. ����� ��� ��������� ����������" << std::endl
			<< "2. ����� ��� ���������� ����������" << std::endl
			<< "3. ����� ��� ���������� � ��������� ����������" << std::endl
			<< "�������� ��� �����: ";
		raceType = getChoise("", 1, 3);

		system("cls");

		std::cout << "������� ����� ���������: ";
		while (!(std::cin >> distance) || distance <= 0)
		{
			std::cout << "������: ������� ������������� ����� ��� ���������: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");

		std::cout << "��� ������ ����� ���������� ���������������� ������� ���� ����������.";

		int choice{};
		do
		{
			std::cout << "\n--- �������� ��������� ��� ����������� ---" << std::endl;
			std::cout << "1. �������-���������" << std::endl
			          << "2. �����" << std::endl
				      << "3. �������" << std::endl
				      << "4. �������" << std::endl
				      << "5. ����" << std::endl
				      << "6. �������-���������" << std::endl
				      << "7. �����-�������" << std::endl
				      << "0. ��������� �����������" << std::endl;

			choice = getChoise("��� �����: ", 0, 7);

			if (choice != 0)
			{
				std::unique_ptr<Transport>newPlayer = createPlayer(choice); 

				if (newPlayer)
				{
					if (playersName.count(newPlayer->getName()) > 0)
					{
						std::cout << "������: ������������ �������� '" << newPlayer->getName()
							      << "' ��� ����������������. �������� ������." << std::endl;
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
							std::cout << newPlayer->getName() << " ������� ���������������." << std::endl;
							playersName.insert(newPlayer->getName());
							createPlayers.push_back(std::move(newPlayer));

							std::cout << "\n--- ������������������ ��������� (" << createPlayers.size() << " ��) ---" << std::endl;
							for (const auto& p : createPlayers)
							{
								
								p->displayInfo();
								std::cout << std::endl;
							}
							
						}
						else
						{
							std::cout << "������: " << newPlayer->getName()
								      << " �� �������� ��� ���������� ���� �����. ���������� �����." << std::endl;
						}
					}

				}
				else
				{
					std::cout << "������: �� ������� ������� ������������ ��������. ���������� �����." << std::endl;
				}
			}
			else
			{
				choice = 0;
				if (createPlayers.size() < 2)
				{
					std::cout << "������: ���������������� " << createPlayers.size()
						      << " ��. ��� ����� ��������� ������� 2 ��. ���������� �����������." << std::endl;
					choice = -1;
				}
				else
				{
					std::cout << "����������� ���������. ���������� � �����!" << std::endl;
				}
			}
		} while (choice != 0 || createPlayers.size() < 2);

		system("cls");

		std::cout << "\n--- ������������������ ��������� (" << createPlayers.size() << " ��) ---" << std::endl;

		for (const auto& p : createPlayers)
		{
			p->displayInfo();
			std::cout << std::endl;
		}
		std::cout << "\n--- ���������� ����� �� ��������� " << distance << " �� ---" << std::endl;

		if (createPlayers.empty())
		{
			std::cout << "��� ���������� ��� �����. ��������� ���������." << std::endl;
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
				      << " - �����: " << results[i].first  << std::endl;
		}
		std::cout << "\n����������: " << results[0].second->getName()
			      << " �� �������� " << results[0].first << std::endl;

		std::cout << "\n----------------------------------------" << std::endl;
		std::cout << "�������� ��� ���� �����? (1 - ��, 0 - ���): ";

		int choice_run_again = getChoise("", 0, 1);
		if (choice_run_again == 0)
		{
			isProgramRun = false;

		}
		std::cout << "������� �� ������� � ���������� �����!" << std::endl;

	}
	return 0;
}

