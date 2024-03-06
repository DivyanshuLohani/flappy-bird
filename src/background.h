#pragma once
#include <raylib.h>

class Background
{
public:
    Background(const char *textureFile, int postition, int speed);
    ~Background();
    void Update();
    void Draw();
    void StickBottom();
    Texture2D m_texture;

private:
    int m_positionY;
    int m_tiles;
    int m_speed;
    int m_scroll = 0;
};