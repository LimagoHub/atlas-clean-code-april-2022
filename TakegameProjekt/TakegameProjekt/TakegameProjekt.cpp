// TakegameProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "NimgameImpl.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ConsolenWriter.h"
/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main()
{
	ConsolenWriter writer;
    NimgameImpl game{writer};
	HumanPlayer fritz;
	ComputerPlayer hal;
	game.add_player(&fritz);
	game.add_player(&hal);
	GameClient client{ game };
	client.run();
}


