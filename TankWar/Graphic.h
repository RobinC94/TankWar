#pragma once
#include <graphics.h>
#include "Rect.h"

namespace CRB_TANK {

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	const int BATTLE_GROUND_X1 = 5;
	const int BATTLE_GROUND_Y1 = 5;
	const int BATTLE_GROUND_X2 = 800;
	const int BATTLE_GROUND_Y2 = (SCREEN_HEIGHT - BATTLE_GROUND_Y1);


	class Graphic
	{
	public:
		static void Create();
		static void Destroy();

		static void DrawBattleGround();

		static int GetScreenWidth();
		static int GetScreenHeight();

		static Rect GetBattleGround();

		static void ShowScore();
		static void ShowGameLevel(int nLevel);

		static void ShowGameOver();
	
	private:
		static Rect m_rectScreen;
		static Rect m_rectBattleGround;

		static char m_pArray[100];
	};

}

