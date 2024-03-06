#pragma once
#include <raylib.h>

class Point
{
public:
    Point(int posY);
    void Update();
    void Draw();
    Rectangle getRect() { return {(float)m_posX, (float)m_posY, 100, 20}; }
    bool m_active;

private:
    int m_posY;
    int m_posX;
};