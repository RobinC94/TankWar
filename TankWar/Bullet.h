#pragma once
#include <list>
#include "Object.h"

using std::list;

namespace CRB_TANK {
	class Bullet : public Object
	{
	public:
		Bullet();
		Bullet(Point pos, Dir dir, COLORREF color);
		~Bullet();

		void Display();

		void Move();

		void Boom(list<Object*>& lstBombs);

		bool IsDisappear()
		{
			return m_bDisappear;
		}

		Rect GetSphere()
		{
			return m_rectSphere;
		}

		void SetDisappear()
		{
			m_bDisappear = true;
		}

	protected:
		void CalculateSphere();
	};
}
