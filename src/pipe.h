#pragma once
#include <raylib.h>

class Pipe
{
public:
    Pipe(int posY, bool flipped, Texture2D pipeTex);
    // ~Pipe() { UnloadTexture(m_texture); };
    void Draw();
    void Update();
    bool m_active = true;
    Rectangle getRect() const { return {(float)m_posX, (float)m_posY, (float)m_texture.width, (float)m_texture.height}; }

private:
    int m_posX = 0;
    int m_posY = 0;
    Texture2D m_texture;
    Rectangle m_rect;
};