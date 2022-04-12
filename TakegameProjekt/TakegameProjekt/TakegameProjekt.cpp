// TakegameProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "NimgameImpl.h"
#include "GameClient.h"
/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main()
{
    NimgameImpl game;
	GameClient client{ game };
	client.run();
}

