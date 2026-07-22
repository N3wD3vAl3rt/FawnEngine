#pragma once

#include <memory>

#include "Texture.h"
#include "Sprite.h"

class SpriteSheet
{
public:
    SpriteSheet();

    void SetTexture(std::shared_ptr<Texture> texture);

    Sprite GetSprite(
        int x,
        int y,
        int width,
        int height) const;

private:
    std::shared_ptr<Texture> texture;
};