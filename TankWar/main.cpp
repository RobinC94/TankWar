#include <iostream>
#include <conio.h>
#include <time.h>
#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Shape.h"
#include "Setting.h"

using namespace CRB_TANK;
using std::list;

MainTank mainTank;

// Bullet list
list<Object*> lstMainTankBullets;
list<Object*> lstBullets;

// Bomb List
list<Object*> lstBombs;

// Tank list
list<Tank*> lstTanks;

void CheckCrash()
{
	for(auto &it: lstMainTankBullets)
	{
		for (auto &itt : lstTanks)
		{
			if (Shape::CheckIntersect(it->GetSphere(), itt->GetSphere()))
			{
				itt->SetDisappear();
				it->SetDisappear();
			}
		}
	}

	for (auto &it : lstBullets)
	{
		if (Shape::CheckIntersect(it->GetSphere(), mainTank.GetSphere()))
		{
			Setting::Die();

			if (Setting::GetLife() > 0)
			{
				it->SetDisappear();
			}
			else
			{
				mainTank.SetDisappear();
			}
		}
	}
}

void Init()
{
	srand((unsigned)time(NULL));

	Graphic::Create();

	lstMainTankBullets.clear();
	lstBullets.clear();
	lstBombs.clear();
	lstTanks.clear();
}

void Dispose()
{
	for (auto it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete *it;
	}
	lstTanks.clear();

	for (auto it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		delete *it;
	}

	for (auto it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete *it;
	}
	lstBullets.clear();

	for (auto it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete *it;
	}
	lstBombs.clear();

	Graphic::Destroy();
}

int main() 
{
	Init();

	bool loop = true;
	bool skip = false;
	bool bGameOver = false;
	while (loop)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (skip && key != 13)
			{
				continue;
			}

			switch (key)
			{
				// Up
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
				// Down
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // 方向键高8位
				break;
				// Esc
			case 27:
				loop = false;
				break;
				// Space
			case 32:
				mainTank.Shoot(lstMainTankBullets);
				break;
				// Enter
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			if (bGameOver)
			{
				break;
			}

			// Draw Background
			cleardevice();
			Graphic::DrawBattleGround();

			CheckCrash();

			Graphic::ShowScore();

			// New Game Level
			if (Setting::m_bNewLevel)
			{
				Setting::m_bNewLevel = false;

				Setting::NewGameLevel();

				Graphic::ShowGameLevel(Setting::GetGameLevel());

				for (int i = 0; i < Setting::GetTankNum(); i++)
				{
					EnemyTank* p = new EnemyTank();
					lstTanks.push_back(p);
				}

				// 设置暂停，按Enter开始
				skip = true;
				continue;
			}

			if (mainTank.IsDisappear())
			{
				skip = true;
				bGameOver = true;

				Graphic::ShowGameOver();

				continue;
			}

			mainTank.Move();
			mainTank.Display();

			// Draw Tanks
			for (auto it = lstTanks.begin(); it != lstTanks.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					Setting::TankDamaged();

					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the tank
					delete *it;
					it = lstTanks.erase(it);
					continue;
				}

				(*it)->Display();

				if ((*it)->NeedShoot())
				{
					EnemyTank* p = (EnemyTank*)*it;
					p->Shoot(lstBullets);
				}
				it++;
			}

			/* Draw Bullets */
			for (auto it = lstMainTankBullets.begin(); it != lstMainTankBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete *it;
					it = lstMainTankBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			for (auto it = lstBullets.begin(); it != lstBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete *it;
					it = lstBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			/* Draw Bombs */
			for (auto it = lstBombs.begin(); it != lstBombs.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					delete *it;
					it = lstBombs.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			/* Draw Score */
			Graphic::ShowScore();
		}

		Sleep(100);
	}

	// Destroy
	Dispose();
	
	return 0;
}
