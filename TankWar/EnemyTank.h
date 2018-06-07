#pragma once
#include "Tank.h"

#define MAX_STEP_TURN  20
#define MAX_STEP_SHOOT	15

namespace CRB_TANK {
	class EnemyTank : public Tank
	{
	public:
		EnemyTank()
		{
			RandomTank();
		}

		~EnemyTank() {}

		void Display();
		void Move();
		void Shoot(list<Object*>& lstBullets);

	protected:
		void CalculateSphere();
		void RandomTank();
		// 随机产生坦克方向 type： 1, 新方向必须与之前方向不同 2, 任意一个新方向
		void RandomDir(int type);
		
		int m_stepCnt;
	};
}
