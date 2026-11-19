#include <MarioKartWii/Item/ItemManager.hpp>
#include <MarioKartWii/Item/Obj/Kumo.hpp>
#include <MarioKartWii/Kart/KartMovement.hpp>
#include <PulsarSystem.hpp>


namespace Pulsar {
namespace Race {
//Mega TC
void MegaTC(Kart::Movement& movement, int frames, int unk0, int unk1) {
    if(System::sInstance->IsContext(PULSAR_MENOD)) movement.ActivateMega();
    else movement.ApplyLightningEffect(frames, unk0, unk1);
}
kmCall(0x80580630, MegaTC);

}//namespace Race
}//namespace Pulsar