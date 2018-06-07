#include "Rect.h"

void CRB_TANK::Rect::Set(const Point pStart, const Point pEnd)
{
	m_startPoint = pStart;
	m_endPoint = pEnd;
}

void CRB_TANK::Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void CRB_TANK::Rect::SetStartPoint(const Point p)
{
	m_startPoint = p;
}

void CRB_TANK::Rect::SetEndPoint(const Point p)
{
	m_endPoint = p;
}

CRB_TANK::Point CRB_TANK::Rect::GetStartPoint() const
{
	return m_startPoint;
}

CRB_TANK::Point CRB_TANK::Rect::GetEndPoint() const
{
	return m_endPoint;
}

CRB_TANK::Point CRB_TANK::Rect::GetTRPoint() const
{
	Point p = m_startPoint;
	p.SetX(m_endPoint.GetX());

	return p;
}

CRB_TANK::Point CRB_TANK::Rect::GetBLPoint() const
{
	Point p = m_startPoint;
	p.SetY(m_endPoint.GetY());

	return p;
}

int CRB_TANK::Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int CRB_TANK::Rect::GetHeight()
{
	return m_endPoint.GetY() - m_startPoint.GetY();
}

void CRB_TANK::Rect::Check()
{
	if (m_startPoint.GetX() > m_endPoint.GetX() || m_startPoint.GetY() > m_endPoint.GetY())
	{
		Point p = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = p;
	}
}
