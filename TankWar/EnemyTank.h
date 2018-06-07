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
		// �������̹�˷��� type�� 1, �·��������֮ǰ����ͬ 2, ����һ���·���
		void RandomDir(int type);
		
		int m_stepCnt;
	};
}
