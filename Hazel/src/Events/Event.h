#pragma once
#include "src/Core.h"

#include <string>
#include <functional>

namespace Hazel {
    /*
        Events in Hazel are currently blockig , meaning when an event occurs it immediately gets dispatched
        and must be dealt with right then an there. For the future, a better strategy might be off to buffer
        events in an event bus and process them during the "event" part of the update stage.
    */
    enum class EventTypes {
        None = 0,
        // Window events
        WindowClose, WindowFocus, WindowResize, WindowMove, WindowLostFocus,
        // Mouse events
        MouseButtonClicked, MouseButtonReleased, MouseMoved, MouseScrolled,
        // Keyboard events
        KeyboardKeyPressed, KeyboardKeyReleased,
        // App Events
        AppUpdate, AppRender, AppTick
    };

    enum EventCategories {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseEvent = BIT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventTypes GetStaticType() { return EventTypes::type; }\
                                    virtual EventTypes GetEventTypes() const override { return GetStaticType(); }\
                                    virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

    class HAZEL_API Event {
        friend class EventDispatcher;
    public:
        virtual EventTypes GetEventTypes() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategories category){
            return GetCategoryFlags() & category;
        }

    protected:
        bool m_Handled = false;

    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

        public: 
            EventDispatcher(Event &event): m_Event(event) {}

            template<typename T>
            bool Dispatch(EventFn<T> func) {
                if(m_Event.GetEventTypes() == T::GetStaticType()) {
                    m_Event.m_Handled = func(*(T*)&m_Event);
                    return true;
                }
            }
        
        private:
            Event& m_Event;
    };
};
