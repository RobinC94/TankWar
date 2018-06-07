#pragma once
#include "Rect.h"

namespace CRB_TANK
{
	class Shape
	{
	public:
		static bool CheckPointInRect(const Point& point, const Rect& rect);
		static bool CheckIntersect(const Rect& rectA, const Rect& rectB);
	};
}