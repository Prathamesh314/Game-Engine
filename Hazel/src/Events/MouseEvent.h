#pragma once

#include "Event.h"
#include "sstream"
#include <string>

namespace Hazel {
    class HAZEL_API MouseMovedEvent: public Event {
        public:
        MouseMovedEvent(float x, float y): m_MouseX(x),  m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: "<< m_MouseX<<", "<<m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
        EVENT_CLASS_TYPE(MouseMovedEvent);

        private:
            float m_MouseX, m_MouseY;
    };

    class HAZEL_API MouseScrolledEvent : public Event {
        public:
        MouseScrolledEvent(float xOffset, float yOffset): xOffset(m_OffsetX), yOffset(m_OffsetY) {}

        inline float GetXOffSet() const {return m_OffsetX;}
        inline float GetYOffSet() const {return m_OffsetY;}

        std::string ToString() const override {
            std::stringstream ss;
            ss<<"MouseScrolledEvent: "<<GetXOffSet()<<", "<<GetYOffSet();
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
        EVENT_CLASS_TYPE(MouseScrolledEvent);
        private:
            float m_OffsetX, m_OffsetY;
    };

    class HAZEL_API MouseButtonEvent: public Event {
        public:
            inline int GetMouseButton() const { return m_Button; }
            EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
        
            protected:
                MouseButtonEvent(int button) : m_Button(button){}
                int m_Button;
    };

    class HAZEL_API MouseButtonPressedEvent : public Event {
        public:
            MouseButtonPressedEvent(int button ): MouseButtonEvent(button) {}

            std::string ToString() const override {
                std::stringstream ss;
                ss<<"MouseButtonPressedEvent: "<<m_Button;
                return ss.str();
            }
            
            EVENT_CLASS_TYPE(MouseButtonPressedEvent);
    }

    class HAZEL_API MouseButtonReleasedEvent : public Event {
        public:
            MouseButtonReleasedEvent(int button ): MouseButtonEvent(button) {}

            std::string ToString() const override {
                std::stringstream ss;
                ss<<"MouseButtonReleasedEvent: "<<m_Button;
                return ss.str();
            }
            
            EVENT_CLASS_TYPE(MouseButtonReleasedEvent);
    }
}