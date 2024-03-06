#include "bird.h"
#include <math.h>

Bird::Bird()
{
    m_texture = LoadTexture("Graphics/bluebird-midflap.png");
    m_flySound = LoadSound("Audio/wing.wav");
    Reset();
}

Bird::~Bird()
{
    UnloadTexture(m_texture);
}

void Bird::Draw()
{
    Vector2 halfTexture = {(float)m_texture.width / 2, (float)m_texture.height / 2};
    DrawTexturePro(
        m_texture,
        {0, 0, (float)m_texture.width, (float)m_texture.height},
        {m_position.x + halfTexture.x,
         m_position.y + halfTexture.y,
         (float)m_texture.width,
         (float)m_texture.height},
        halfTexture,
        m_rotation,
        WHITE);
}

void Bird::Reset()
{
    m_position = {(float)(GetScreenWidth() - m_texture.width) / 2,
                  (float)(GetScreenHeight() - m_texture.height) / 2};
    m_rotation = 0.0f;
}

void Bird::Idle()
{
    m_position.y += 0.5f * sin(GetTime() * 10.0f);
}

void Bird::Update()
{
    m_position.y += m_velocity;
    if (IsKeyPressed(KEY_W))
    {
        m_velocity = -7.0f;
        m_rotation = -30.0f;
        PlaySound(m_flySound);
    }
    else
    {
        m_velocity += 0.5f;
        if (m_rotation < 90.0f)
        {
            m_rotation += 1.5f;
        }
    };
}