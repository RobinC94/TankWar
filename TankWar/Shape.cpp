#include "Shape.h"

bool CRB_TANK::Shape::CheckPointInRect(const Point & point, const Rect & rect)
{
	if (point.GetX() < rect.GetStartPoint().GetX() || point.GetX() > rect.GetEndPoint().GetX() ||
		point.GetY() < rect.GetStartPoint().GetY() || point.GetY() > rect.GetEndPoint().GetY())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CRB_TANK::Shape::CheckIntersect(const Rect & rectA, const Rect & rectB)
{
	if (CheckPointInRect(rectA.GetStartPoint(), rectB) ||
		CheckPointInRect(rectA.GetEndPoint(), rectB) ||
		CheckPointInRect(rectA.GetTRPoint(), rectB) ||
		CheckPointInRect(rectA.GetBLPoint(), rectB))
	{
		return true;
	}
	else
	{
		return false;
	}
}
