#pragma once
#include <string>
#include <unordered_map>
#include <raylib.h>

class TextureLoader
{
public:
    static Texture2D loadTexture(std::string filename);
    static void deallocateTextures();

private:
    static std::unordered_map<std::string, Texture2D> umapTexturesLoaded;
};