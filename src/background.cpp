#include "background.h"
#include <iostream>
#include <math.h>

Background::Background(const char *textureFile, int positionY, int speed) : m_positionY(positionY), m_speed(speed)
{
    m_texture = LoadTexture(textureFile);
    m_tiles = 2;
    // std::cout << "m_tiles: " << m_tiles << std::endl;
}

void Background::Draw()
{
    for (int i = 0; i < m_tiles; i++)
    {

        DrawTexture(m_texture, i * m_texture.width + m_scroll, m_positionY, WHITE);
    }
}

void Background::StickBottom()
{
    m_positionY = GetScreenHeight() - m_texture.height;
}

void Background::Update()
{
    m_scroll -= m_speed;
    if (abs(m_scroll) > m_texture.width)
        m_scroll = 0;
}

Background::~Background()
{
    UnloadTexture(m_texture);
}