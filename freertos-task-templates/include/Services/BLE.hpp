#ifndef SERVICE_BLE__H_H
#define SERVICE_BLE__H_H
#include "ActiveObject.hpp"
/**
 * Customize the static methods of an RTOS::ActiveObject
 */
namespace Service
{
    class BLE : public RTOS::ActiveObject<BLE>
    {
    public:
        static void Initialize(){};
        static void Handle(const uint8_t arg[]);
        static void End(){
        };

        BLE() : RTOS::ActiveObject<BLE>(){};
    private:
    };

}
#endif
