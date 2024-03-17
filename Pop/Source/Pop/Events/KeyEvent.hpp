#pragma once

#include "Pop/Events/Event.hpp"
#include "Pop/Core/Code/KeyCode.hpp"

namespace Pop::Event
{
	class KeyEvent : public Event
	{
		// Attributes
	protected:
		Core::KeyCode keyCode;

		// Methods
	public:
		Core::KeyCode GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const Core::KeyCode p_keycode)
			: keyCode(p_keycode)
		{
		}
	};

	class KeyPressedEvent : public KeyEvent
	{
		// Attributes
	private:
		bool isRepeat;

		// Methods
	public:
		KeyPressedEvent(const Core::KeyCode p_keycode, bool p_isRepeat = false)
			: KeyEvent(p_keycode), isRepeat(p_isRepeat)
		{
		}

		bool IsRepeat() const { return isRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (repeat = " << isRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
		// Methods
	public:
		KeyReleasedEvent(const Core::KeyCode p_keycode)
			: KeyEvent(p_keycode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
		// Methods
	public:
		KeyTypedEvent(const Core::KeyCode p_keycode)
			: KeyEvent(p_keycode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}