#include "TextureLoader.h"

std::unordered_map<std::string, Texture2D> TextureLoader::umapTexturesLoaded;

Texture2D TextureLoader::loadTexture(std::string filename)
{

    auto found = umapTexturesLoaded.find(filename);

    if (found != umapTexturesLoaded.end())
    {
        // The texture was already loaded so return it.
        return found->second;
    }
    else
    {
        // Setup the relative filepath to the images folder using the input filename.
        std::string filepath = "Graphics/" + filename;

        umapTexturesLoaded[filename] = LoadTexture(filepath.c_str());
        return umapTexturesLoaded[filename];
    }
}

void TextureLoader::deallocateTextures()
{
    // Destroy all the textures
    while (umapTexturesLoaded.empty() == false)
    {
        auto it = umapTexturesLoaded.begin();
        UnloadTexture(it->second);

        umapTexturesLoaded.erase(it);
    }
}