#include "RubyPCH.h"
#include "MouseEvent.h"

std::string Ruby::MouseMovedEvent::ToString() const
{
    std::stringstream ss("");
    ss << GetEventName() << " " << "x = " << xPos << " y = " << yPos;
    
    return ss.str() ;
}
