#include "System.hpp"

std::vector<std::variant<_REGISTERED_SERVICES>> System::mSystemServicesRegistered = {REGISTERED_SERVICES};
RTOS::MsgBroker System::mMsgBroker = RTOS::MsgBroker();

