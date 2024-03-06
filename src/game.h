#pragma once
#include <raylib.h>
#include <vector>
#include "bird.h"
#include "background.h"
#include "pipe.h"
#include "point.h"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void DrawScore();
    void Update();
    void CheckCollisions();

private:
    void Reset();

    Bird m_bird;
    Background m_base;
    Background m_bg;
    std::vector<Pipe> m_pipes;
    std::vector<Point> m_points;
    Texture2D m_pipeTex;
    float m_pipeInterval = 0;
    bool m_gameOver = false;
    bool m_gameStarted = false;
    Texture2D m_gameOverTexture;

    int m_score = 0;
    Font m_scroeFont;

    Sound m_pointSound;
    Sound m_dieSound;
};