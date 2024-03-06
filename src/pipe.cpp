#include "pipe.h"
#include "TextureLoader.h"

Pipe::Pipe(int posY, bool flipped, Texture2D pipTex)
    : m_posY(posY), m_texture(pipTex)
{
    m_posX = GetScreenWidth() + m_texture.width;
    m_rect.x = 0;
    m_rect.y = 0;
    m_rect.width = m_texture.width;
    if (flipped)
    {
        m_rect.height = m_texture.height * -1;
        m_posY -= m_texture.height;
    }
    else
    {
        m_rect.height = m_texture.height;
    }
}

void Pipe::Draw()
{
    DrawTextureRec(m_texture, m_rect, {(float)m_posX, (float)m_posY}, WHITE);
}

void Pipe::Update()
{
    if (m_active)
        m_posX -= 3;
    if (m_posX < -m_texture.width)
    {
        m_active = false;
    }
}