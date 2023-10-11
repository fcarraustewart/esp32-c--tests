#ifndef MSGBROKER__H_H
#define MSGBROKER__H_H
#include "Services/BLE.hpp"
#include "Services/LoRa.hpp"
#include "Logger.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include <string>
// https://commschamp.github.io/comms_protocols_cpp/ see this for further development
namespace RTOS
{
    class MsgBroker
    {
    public:
        static const    uint16_t            cMaxPayloadLength = 10;
        using           payload_t = uint8_t[cMaxPayloadLength];
        
        enum class Event
        {
            BLEConnected,
            LoRaConnected,
        };
        struct __attribute__ ((packed)) Message
        {
            uint8_t     mSource;
            uint8_t     mDestination;
            Event       mEvent;
            uint16_t    mLength;
            payload_t   mPayload;

            //Message(Event& event, payload_t& p, uint16_t& l){}; Constructor?
        };
    public:
        
        //template<typename... TArgs>
        static void Create();

        void operator()(int& i) const {
            Logger::Log("float: %d",i);
        }

        void operator()(float& f) const {
            Logger::Log("float: %f",f);
        }

        void operator()(const std::string& s) const {
            Logger::Log("str: %s",s);
            ;
        }
    private:


    protected:

    /**
     *                  Member Variables:
     */
    public:

    protected:
    };

}

#endif
