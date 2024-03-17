#pragma once

#include "Pop/Events/Event.hpp"
#include "Pop/Core/Code/MouseCode.hpp"

namespace Pop::Event
{
	class MouseMovedEvent : public Event
	{
		// Attributes
	private:
		float mouseX, mouseY;

		// Methods
	public:
		MouseMovedEvent(const float p_x, const float p_y)
			: mouseX(p_x)
			, mouseY(p_y)
		{
		}

		float GetX() const { return mouseX; }
		float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseScrolledEvent : public Event
	{
		// Attributes
	private:
		float xOffset, yOffset;

		// Methods
	public:
		MouseScrolledEvent(const float p_xOffset, const float p_yOffset)
			: xOffset(p_xOffset), yOffset(p_yOffset)
		{
		}

		float GetXOffset() const { return xOffset; }
		float GetYOffset() const { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MouseButtonEvent : public Event
	{
		// Attributes
	protected:
		Core::MouseCode button;

		// Methods
	public:
		Core::MouseCode GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(const Core::MouseCode p_button)
			: button(p_button)
		{
		}

	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		// Methods
	public:
		MouseButtonPressedEvent(const Core::MouseCode p_button)
			: MouseButtonEvent(p_button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		// Methods
	public:
		MouseButtonReleasedEvent(const Core::MouseCode p_button)
			: MouseButtonEvent(p_button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}