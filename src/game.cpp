#include "game.h"
#include <iostream>

Game::Game() : m_base("Graphics/base.png", 0, 3), m_bg("Graphics/background-day.png", 0, 3)
{
    m_base.StickBottom();
    m_pipeTex = LoadTexture("Graphics/pipe-green.png");
    m_gameOverTexture = LoadTexture("Graphics/gameover.png");
    m_scroeFont = LoadFontEx("Graphics/flappy-font.ttf", 32, 0, 128);

    m_pointSound = LoadSound("Audio/point.wav");
    m_dieSound = LoadSound("Audio/hit.wav");
}
Game::~Game()
{
}

void Game::DrawScore()
{
    const char *text = TextFormat("%i", m_score);
    Vector2 xPos = MeasureTextEx(m_scroeFont, text, 32, 0);
    DrawText(TextFormat("%i", m_score), (GetScreenWidth() - xPos.x) / 2, 50, 32, WHITE);
}

void Game::Draw()
{
    m_bg.Draw();
    m_bird.Draw();

    for (auto &pipe : m_pipes)
    {
        pipe.Draw();
    }

    m_base.Draw();
    DrawScore();

    if (m_gameOver)
    {
        DrawTexture(
            m_gameOverTexture,
            (GetScreenWidth() - m_gameOverTexture.width) / 2, (GetScreenHeight() - m_gameOverTexture.height) / 2,
            WHITE);
    }
}

void Game::Update()
{
    // Input
    if (IsKeyDown(KEY_W) && m_gameOver)
    {
        Reset();
    }

    // DEBUG
    if (IsKeyDown(KEY_Q))
    {
        m_score += 5;
    }

    if (m_gameOver)
        return;

    m_bg.Update();
    m_base.Update();

    if (!m_gameStarted)
    {
        if (IsKeyDown(KEY_W))
        {
            m_gameStarted = true;
            Reset();
            m_bird.Update();
        }
        m_bird.Idle();
        return;
    }
    m_bird.Update();

    // Update Pipes
    for (int i = 0; i < (int)m_pipes.size();)
    {
        if (m_pipes[i].m_active)
        {
            m_pipes[i].Update();
            i++;
        }
        else
        {
            m_pipes.erase(m_pipes.begin() + i);
        }
    }
    // Points
    for (int i = 0; i < (int)m_points.size();)
    {
        if (m_points[i].m_active)
        {
            m_points[i].Update();
            i++;
        }
        else
        {
            m_points.erase(m_points.begin() + i);
        }
    }

    // Spawn Pipes
    if (GetTime() - m_pipeInterval >= 1.5f)
    {
        m_pipeInterval = GetTime();
        int yPos = GetRandomValue(30, GetScreenHeight() - m_base.m_texture.height - 110);
        m_pipes.push_back(Pipe(yPos + 100, false, m_pipeTex)); // 30 = GAP
        m_pipes.push_back(Pipe(yPos, true, m_pipeTex));
        m_points.push_back(Point(yPos));
    }

    CheckCollisions();
}

void Game::CheckCollisions()
{
    Rectangle playerRect = m_bird.getRect();
    for (auto &pipe : m_pipes)
    {
        if (CheckCollisionRecs(playerRect, pipe.getRect()))
        {
            m_gameOver = true;
            PlaySound(m_dieSound);
        }
    }

    if (playerRect.y + playerRect.height > GetScreenHeight() - m_base.m_texture.height ||
        playerRect.y < 0)
    {
        m_gameOver = true;
        PlaySound(m_dieSound);
    }

    for (auto &point : m_points)
    {
        if (CheckCollisionRecs(playerRect, point.getRect()))
        {
            m_score += 1;
            point.m_active = false;
            PlaySound(m_pointSound);
        }
    }
}

void Game::Reset()
{
    m_gameOver = false;
    m_bird.Reset();
    m_points.clear();
    m_pipes.clear();
    m_pipeInterval = GetTime();
    m_score = 0;
}
