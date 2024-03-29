#pragma once

#include "Pop/Core/Core.hpp"

#include <string>
#include <functional>
#include <sstream>

namespace Pop::Event
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
		// Attributes
	public:
		bool handled = false;

		// Methods
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		// Attributes
	private:
		Event& event;

		// Methods
	public:
		EventDispatcher(Event& p_event)
			: event(p_event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& p_func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.handled |= p_func(static_cast<T&>(event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& p_os, const Event& p_event)
	{
		return p_os << p_event.ToString();
	}
}