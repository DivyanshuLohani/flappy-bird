#pragma once
#include <raylib.h>

class Bird
{
public:
    Bird();
    ~Bird();

    void Update();
    void Draw();
    Rectangle getRect() { return {m_position.x, m_position.y, (float)m_texture.width, (float)m_texture.height}; };
    void Reset();
    void Idle();

private:
    float m_velocity = 0.0f;
    float m_rotation = 0.0f;

    Texture2D m_texture;
    Vector2 m_position;
    Sound m_flySound;
};