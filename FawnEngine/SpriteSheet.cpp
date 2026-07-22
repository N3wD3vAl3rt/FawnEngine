#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
}

void SpriteSheet::SetTexture(std::shared_ptr<Texture> newTexture)
{
    texture = newTexture;
}

Sprite SpriteSheet::GetSprite(
    int x,
    int y,
    int width,
    int height) const
{
    Sprite sprite(width, height);

    if (!texture)
    {
        return sprite;
    }

    const Image& image = texture->GetImage();

    for (int py = 0; py < height; py++)
    {
        for (int px = 0; px < width; px++)
        {
            sprite.SetPixel(
                px,
                py,
                image.GetPixel(x + px, y + py));
        }
    }

    return sprite;
}