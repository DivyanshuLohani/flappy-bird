#include "point.h"

Point::Point(int posY) : m_active(true), m_posY(posY)
{
    m_posX = GetScreenWidth() + 50;
}

void Point::Update()
{
    if (m_active)
        m_posX -= 3;
    if (m_posX < -100)
    {
        m_active = false;
    }
}

void Point::Draw()
{
    DrawRectangle(m_posX, m_posY, 50, 100, {0, 0, 0, 255});
}