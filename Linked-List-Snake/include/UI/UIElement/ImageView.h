#pragma once
#include "UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			virtual void setTexture(sf::String texture_path);
			virtual void setScale(float width, float height);
			virtual void setPosition(sf::Vector2f position);
			virtual void setRotation(float rotation_angle);
			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged();
		};
	}
}