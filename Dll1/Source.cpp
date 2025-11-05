#pragma warning (disable : 4251 )
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

		std::cout << "Äîáðî ïîæàëîâàòü â ãîíî÷íûé ñèìóëÿòîð!" << std::endl
			<< "1. Ãîíêà äëÿ íàçåìíîãî òðàíñïîðòà" << std::endl
			<< "2. Ãîíêà äëÿ âîçäóøíîãî òðàíñïîðòà" << std::endl
			<< "3. Ãîíêà äëÿ âîçäóøíîãî è íàçåìíîãî òðàíñïîðòà" << std::endl
			<< "Âûáåðèòå òèï ãîíêè: ";
		raceType = getChoise("", 1, 3);

		system("cls");

		std::cout << "Óêàæèòå äëèíó äèñòàíöèè: ";
		while (!(std::cin >> distance) || distance <= 0)
		{
			std::cout << "Îøèáêà: Ââåäèòå ïîëîæèòåëüíîå ÷èñëî äëÿ äèñòàíöèè: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");

		std::cout << "Äëÿ íà÷àëà ãîíêè íåîáõîäèìî çàðåãèñòðèðîâàòü ìèíèìóì äâóõ ó÷àñòíèêîâ.";

		int choice{};
		do
		{
			std::cout << "\n--- Âûáåðèòå òðàíñïîðò äëÿ ðåãèñòðàöèè ---" << std::endl;
			std::cout << "1. Áîòèíêè-âåçäåõîäû" << std::endl
			          << "2. Ìåòëà" << std::endl
				      << "3. Âåðáëþä" << std::endl
				      << "4. Êåíòàâð" << std::endl
				      << "5. Îðåë" << std::endl
				      << "6. Âåðáëþä-áûñòðîõîä" << std::endl
				      << "7. Êîâåð-ñàìîëåò" << std::endl
				      << "0. Çàâåðøèòü ðåãèñòðàöèþ" << std::endl;

			choice = getChoise("Âàø âûáîð: ", 0, 7);

			if (choice != 0)
			{
				std::unique_ptr<Transport>newPlayer = createPlayer(choice); 

				if (newPlayer)
				{
					if (playersName.count(newPlayer->getName()) > 0)
					{
						std::cout << "Îøèáêà: Òðàíñïîðòíîå ñðåäñòâî '" << newPlayer->getName()
							      << "' óæå çàðåãèñòðèðîâàíî. Âûáåðèòå äðóãîå." << std::endl;
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
							std::cout << newPlayer->getName() << " óñïåøíî çàðåãèñòðèðîâàí." << std::endl;
							playersName.insert(newPlayer->getName());
							createPlayers.push_back(std::move(newPlayer));

							std::cout << "\n--- Çàðåãèñòðèðîâàííûå ó÷àñòíèêè (" << createPlayers.size() << " ÒÑ) ---" << std::endl;
							for (const auto& p : createPlayers)
							{
								
								p->displayInfo();
								std::cout << std::endl;
							}
							
						}
						else
						{
							std::cout << "Îøèáêà: " << newPlayer->getName()
								      << " íå ïîäõîäèò äëÿ âûáðàííîãî òèïà ãîíêè. Ïîïðîáóéòå ñíîâà." << std::endl;
						}
					}

				}
				else
				{
					std::cout << "Îøèáêà: Íå óäàëîñü ñîçäàòü òðàíñïîðòíîå ñðåäñòâî. Ïîïðîáóéòå ñíîâà." << std::endl;
				}
			}
			else
			{
				choice = 0;
				if (createPlayers.size() < 2)
				{
					std::cout << "Îøèáêà: Çàðåãèñòðèðîâàíî " << createPlayers.size()
						      << " ÒÑ. Äëÿ ãîíêè òðåáóåòñÿ ìèíèìóì 2 ÒÑ. Ïðîäîëæèòå ðåãèñòðàöèþ." << std::endl;
					choice = -1;
				}
				else
				{
					std::cout << "Ðåãèñòðàöèÿ çàâåðøåíà. Ïðèñòóïàåì ê ãîíêå!" << std::endl;
				}
			}
		} while (choice != 0 || createPlayers.size() < 2);

		system("cls");

		std::cout << "\n--- Çàðåãèñòðèðîâàííûå ó÷àñòíèêè (" << createPlayers.size() << " ÒÑ) ---" << std::endl;

		for (const auto& p : createPlayers)
		{
			p->displayInfo();
			std::cout << std::endl;
		}
		std::cout << "\n--- Ðåçóëüòàòû ãîíêè íà äèñòàíöèþ " << distance << " êì ---" << std::endl;

		if (createPlayers.empty())
		{
			std::cout << "Íåò ó÷àñòíèêîâ äëÿ ãîíêè. Ïðîãðàììà çàâåðøåíà." << std::endl;
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
				      << " - âðåìÿ: " << results[i].first  << std::endl;
		}
		std::cout << "\nÏîáåäèòåëü: " << results[0].second->getName()
			      << " ñî âðåìåíåì " << results[0].first << std::endl;

		std::cout << "\n----------------------------------------" << std::endl;
		std::cout << "Ïðîâåñòè åùå îäíó ãîíêó? (1 - Äà, 0 - Íåò): ";

		int choice_run_again = getChoise("", 0, 1);
		if (choice_run_again == 0)
		{
			isProgramRun = false;

		}
		std::cout << "Ñïàñèáî çà ó÷àñòèå â ñèìóëÿòîðå ãîíîê!" << std::endl;

	}
	return 0;
}

