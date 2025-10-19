#pragma once
#include "src/Core.h"

#include <string>
#include <functional>

namespace Hazel {
    enum class EventTypes {
        None = 0,
        // Window events
        WindowClose, WindowFocus, WindowResize, WindowMove, WindowLostFocus,
        // Mouse events
        MouseButtonClicked, MouseButtonReleased, MouseMoved, MouseScrolled,
        // Keyboard events
        KeyboardKeyPressed, KeyboardKeyReleased
    };

    enum EventCategories {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseEvent = BIT(4)
    };

    class HAZEL_API Event {
        friend class EventDispatcher;
    public:
        virtual EventTypes GetEventTypes() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName()};

    protected:
        bool m_Handled = false;

    };

    class EventDispatcher {}
};
