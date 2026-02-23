#pragma once
#include "sstream"
#include "Event.h"
#include <sstream>
#include <string>

namespace Hazel {
    class WindowResizeEvent : public Event {
        public:
        WindowResizeEvent(unsigned int widht, unsigned int height): m_Width(widht), m_Height(height){}

        inline unsigned int GetWidth() const {return m_Width;}
        inline unsigned int GetHeight() const {return m_Height;}
        EVENT_CLASS_CATEGORY(EventCategoryApplication);

        std::string ToString() const override{
            std::stringstream ss;
            ss << "WindowResizeEvent: "<< m_Width << ", " << m_Height;
            return ss.str();
        }
        private:
            unsigned int m_Width, m_Height;
    };
}