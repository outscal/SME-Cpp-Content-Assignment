#include "UI/UIElement/AnimatedImageView.h"

namespace UI
{
    namespace UIElement
    {
        AnimatedImageView::AnimatedImageView() = default;

        AnimatedImageView::~AnimatedImageView() = default;

        void AnimatedImageView::initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
        {
            ImageView::initialize(texture_path, image_width, image_height, position);
        }

        void AnimatedImageView::registerCallbackFuntion(CallbackFunction animation_end_callback)
        {
            callback_function = animation_end_callback;
        }

        void AnimatedImageView::update()
        {
            ImageView::update();

            if (ui_state == UIState::VISIBLE)
            {
                updateElapsedDuration();
                handleAnimationProgress();
                updateAnimation();
            }
        }

        void AnimatedImageView::render()
        {
            ImageView::render();
        }

        void AnimatedImageView::playAnimation(AnimationType type, float duration, CallbackFunction animation_end_callback)
        {
            ImageView::show();
            reset();
            setAnimationType(type);
            setAnimationDuration(duration);
            registerCallbackFuntion(animation_end_callback);
        }

        void AnimatedImageView::updateElapsedDuration()
        {
            float deltaTime = clock.restart().asSeconds();
            elapsed_duration += deltaTime;
        }

        void AnimatedImageView::handleAnimationProgress()
        {
            if (elapsed_duration >= animation_duration && callback_function)
            {
                callback_function();
            }
        }

        void AnimatedImageView::updateAnimation()
        {
            switch (animation_type)
            {
            case AnimationType::FADE_IN:
                fadeIn();
                break;
            case AnimationType::FADE_OUT:
                fadeOut();
                break;
            }
        }

        void AnimatedImageView::setAnimationDuration(float duration)
        {
            animation_duration = duration;
        }

        void AnimatedImageView::setAnimationType(AnimationType type)
        {
            animation_type = type;
        }

        void AnimatedImageView::fadeIn()
        {
            float alpha = std::min(1.0f, elapsed_duration / animation_duration);
            image_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
        }

        void AnimatedImageView::fadeOut()
        {
            float alpha = std::max(0.0f, 1.0f - (elapsed_duration / animation_duration));
            image_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
        }

        void AnimatedImageView::reset()
        {
            animation_duration = default_animation_duration;
            animation_type = AnimationType::FADE_IN;
            clock.restart();
            elapsed_duration = 0.0f;
        }
    }
}