#include "Graphic.h"
#include "Setting.h"

CRB_TANK::Rect CRB_TANK::Graphic::m_rectScreen;
CRB_TANK::Rect CRB_TANK::Graphic::m_rectBattleGround;
char CRB_TANK::Graphic::m_pArray[100];

void CRB_TANK::Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(DARKGRAY);

	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void CRB_TANK::Graphic::Destroy()
{
	closegraph();
}

void CRB_TANK::Graphic::DrawBattleGround()
{
	rectangle(m_rectBattleGround.GetStartPoint().GetX(), m_rectBattleGround.GetStartPoint().GetY(),
		m_rectBattleGround.GetEndPoint().GetX(), m_rectBattleGround.GetEndPoint().GetY());
}

int CRB_TANK::Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int CRB_TANK::Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

CRB_TANK::Rect CRB_TANK::Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}

const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;

void CRB_TANK::Graphic::ShowScore()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	//setfillcolor(m_color);
	//setcolor(m_color);

	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPSTR)m_pArray, _T("�� %d ��"), Setting::GetGameLevel());
	drawtext((LPSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetSumScore());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetTankLevel());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("��  ��  :  %d"), Setting::GetLife());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("������  :  %d"), Setting::GetTankNum());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("�����ٵ�����  :  %d"), Setting::GetTankSum());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void CRB_TANK::Graphic::ShowGameLevel(int nLevel)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // ��ȡ��ǰ��������

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	wsprintf((LPSTR)m_pArray, _T("�� %d ��"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("�� Enter ����ʼ"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void CRB_TANK::Graphic::ShowGameOver()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // ��ȡ��ǰ��������

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	wsprintf((LPSTR)m_pArray, _T("GAME OVER"));
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("�� Enter ���˳�"));
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}
