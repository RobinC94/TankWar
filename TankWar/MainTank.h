#pragma once
#include "Tank.h"

namespace CRB_TANK {

	class MainTank : public Tank
	{
	public:
		MainTank()
		{
			m_pos.Set(300, 300);

			this->CalculateSphere();

			m_color = YELLOW;
			m_dir = Dir::UP;
			m_step = 2;
		}

		~MainTank() {}

		// 设置行驶方向
		void SetDir(Dir dir);

		void Display();
		void Move();
		void Shoot(list<Object*>& lstBullets);
		void Boom(list<Object*>& lstBombs);

	protected:
		void CalculateSphere();
		// 绘制坦克主体
		void DrawTankBody();
	};
}

