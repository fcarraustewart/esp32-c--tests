#include "System.hpp"

void Service::LoRa::Handle(const uint8_t arg[]){
    /**
     * Handle arg packet.
     */
    switch(arg[0])
    {
        default:
        {
            Logger::Log("[Service::%s]::%s():\t%x.\tNYI.", mName.c_str(), __func__, arg[0]);
            break;
        }
    };
}

/**
 * Build the static members on the RTOS::ActiveObject
 */
namespace Service
{
    using               _LoRa = RTOS::ActiveObject<Service::LoRa>;

    template <>
    const std::string   _LoRa::mName = std::string("LoRa");
    template <>
    uint8_t             _LoRa::mCountLoops = 0;
    template <>
    const uint8_t       _LoRa::mInputQueueItemLength = 16;
    template <>
    const uint8_t       _LoRa::mInputQueueItemSize = sizeof(uint16_t);
    template <>
    const size_t        _LoRa::mInputQueueSizeBytes = 
                                        RTOS::ActiveObject<Service::LoRa>::mInputQueueItemLength 
                                        * RTOS::ActiveObject<Service::LoRa>::mInputQueueItemSize;
    template <>
    uint8_t             _LoRa::mInputQueueAllocation[
                                        RTOS::ActiveObject<Service::LoRa>::mInputQueueSizeBytes
                                    ] = { 0 };
    template <>
    QueueHandle_t       _LoRa::mInputQueue = xQueueCreate(
                                        RTOS::ActiveObject<Service::LoRa>::mInputQueueItemLength,
                                        RTOS::ActiveObject<Service::LoRa>::mInputQueueItemSize
                                    );
    template <>
    TaskHandle_t        _LoRa::mHandle = 0;
    template <>
    uint8_t             _LoRa::mReceivedMsg[
                                        RTOS::ActiveObject<Service::LoRa>::mInputQueueItemSize
                                    ] = { 0 };
}
