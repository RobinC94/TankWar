#pragma once
#include "Object.h"
#include "Bomb.h"
#include <list>

using std::list;


namespace CRB_TANK {

	class Tank : public Object
	{
	public:
		Tank()
		{
			m_pos.Set(300, 300);

			this->CalculateSphere();

			m_color = YELLOW;
			m_dir = Dir::UP;
			m_step = 4;

			m_bDisappear = false;
			m_bNeedShoot = false;
		}

		~Tank() {}

		void Display()
		{
			// Display
		}

		void Move()
		{
			// Move
		}

		void Boom(list<Object*>& lstBombs)
		{
			lstBombs.push_back(new Bomb(m_pos, LARGE));
		}

		// Éä»÷
		void Shoot(list<Object*>& lstBullets)
		{
			// Shoot
		}

		void SetDisappear()
		{
			m_bDisappear = true;
		}

		bool IsDisappear()
		{
			return m_bDisappear;
		}

		Rect GetSphere()
		{
			return m_rectSphere;
		}

		bool NeedShoot()
		{
			return m_bNeedShoot;
		}

	protected:
		void CalculateSphere()
		{
			// Calculate Sphere
		}

		bool m_bNeedShoot;
	};
}

