#include <kamek.hpp>
#include <MarioKartWii/Item/ItemPlayer.hpp>
#include <SlotExpansion/CupsConfig.hpp>
#include <PulsarSystem.hpp>
#include <Race/HackPack.hpp>

namespace Pulsar {
namespace Race {

//No Bullet Biil Icon by Gabriela. 
void NoBulletBillIcon(Item::PlayerRoulette *roulette, ItemId item) {
  if(!System::sInstance->IsContext(PULSAR_MEGATC)) roulette->unknown_0x24 = (u32) item;
}
kmCall(0x807a9b28, NoBulletBillIcon);

static void *GetCustomItemSlot(ArchiveMgr *archive, ArchiveSource type, const char *name, u32 *length){
    if (System::sInstance->IsContext(PULSAR_MEGATC)){
		name = "ItemSlot6.bin";
		if (System::sInstance->IsContext(PULSAR_MENOD)){
			name = "ItemSlot6C.bin";
		}
    }
	if (System::sInstance->IsContext(PULSAR_RANDO)){
		name = "ItemSlotR.bin";
		if (System::sInstance->IsContext(PULSAR_MEGATC)){
			name = "ItemSlot6R.bin";
			if (System::sInstance->IsContext(PULSAR_MENOD)){
				name = "ItemSlot6RC.bin";
			}
		}
    }
	//CTDN - replace the last lines with this
	/*
	if (System::sInstance->IsContext(PULSAR_MEGATC)){
		name = "ItemSlot6C.bin";
    }
	if (System::sInstance->IsContext(PULSAR_RANDO)){
		name = "ItemSlotR.bin";
		if (System::sInstance->IsContext(PULSAR_MEGATC)){
			name = "ItemSlot6RC.bin";
		}
    }
	*/
    return archive->GetFile(type, name, length);
}
kmCall(0x807bb128, GetCustomItemSlot);
kmCall(0x807bb030, GetCustomItemSlot);
kmCall(0x807bb200, GetCustomItemSlot);
kmCall(0x807bb53c, GetCustomItemSlot);
kmCall(0x807bbb58, GetCustomItemSlot);

//TODO i ALSO dont know why this doesnt work
//void HackPackXCodes() {
//	if(System::sInstance->IsContext(PULSAR_UMTS)) {
//		MegaFlipCar = 0x3B800001;
//		ColorMinimap = 0x60000000;
//		DisableBump = 0x480005C0;
//		NeverBurnOut = 0x00004800;
//		TripleBanana = 0x00000003;
//	}
//	System::CacheInvalidateAddress(MegaFlipCar);
//	System::CacheInvalidateAddress(ColorMinimap);
//	System::CacheInvalidateAddress(DisableBump);
//	System::CacheInvalidateAddress(NeverBurnOut);
//	System::CacheInvalidateAddress(TripleBanana);
//}
//static RaceLoadHook HackPackX(HackPackXCodes);

}// namespace Item
}// namespace OptPack