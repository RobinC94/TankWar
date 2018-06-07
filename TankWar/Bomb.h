#pragma once
#include "Object.h"
#include <list>

using std::list;

namespace CRB_TANK {
	enum BombType
	{
		LARGE,
		SMALL
	};

	class Bomb : public Object
	{
	public:
		Bomb();
		Bomb(Point pos, BombType type);
		~Bomb() {}

		void Display();

		void Move();

		void Boom(list<Object*>& lstBombs);

		bool IsDisappear();
		void SetDisappear() {}

		Rect GetSphere()
		{
			return m_rectSphere;
		}


	protected:
		void CalculateSphere();

		BombType m_type;
		int m_timer;
	};
}