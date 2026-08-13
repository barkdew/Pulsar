#include <kamek.hpp>

namespace Pulsar {
namespace Race {

//Edit 2026-04-22: Disable codes that may conflict with Wiimmfi or are not needed due to Wiimmfi. For now.
//Edit 2026-04-23: Re-enable gameplay changing codes because we have to disable WWs anyway

//Mushroom Glitch
//kmWrite8(0x807BA077, 0x00000000);

//Rexcore Countdown
kmWrite32(0x805A225C, 0x38800001);

//Edit 2026-04-23: Change timer limit to 5:40
//Extend race online
kmWrite32(0x8053F3B8,0x3C600005);
kmWrite32(0x8053F3BC,0x38833020);
kmWrite32(0x8053F478,0x4800000C); //6 Minute DC Disables

//Anti Online Penalized by B_squo
kmWrite32(0x80549218, 0x38600000);
kmWrite32(0x8054921c, 0x4e800020);

//Edit 2026-04-22: Disable ww bubble skip
//WW Bubble Skip [Ro]
//kmWrite8(0x80609647, 0x0000003C);
//kmWrite8(0x8060964F, 0x0000001E);

//Edit 2026-04-22: Add this for Countdown
//Skip Mode Select Option Online (Always VS) [Ro]
//CTDN - enable this
//kmWrite32(0x8064BD88, 0x3800008F);
//kmWrite32(0x8064BE64, 0x3800008F);
//kmWrite32(0x80609AAC, 0x3800008B);

//Remove Chadderz Button
kmWrite16(0x8064B982, 0x00000005);
kmWrite32(0x8064BA10, 0x60000000);
kmWrite32(0x8064BA38, 0x60000000);
kmWrite32(0x8064BA50, 0x60000000);
kmWrite32(0x8064BA5C, 0x60000000);
kmWrite16(0x8064BC12, 0x00000001);
kmWrite16(0x8064BC3E, 0x00000484);
kmWrite16(0x8064BC4E, 0x000010D7);
kmWrite16(0x8064BCB6, 0x00000484);
kmWrite16(0x8064BCC2, 0x000010D7);

//Floating Flibs [Stealth Steeler]
//kmWrite32(0x808a5770, 0x00000000);
//kmWrite32(0x808a5774, 0x00000000);

//No Bullet Bill Cancel When Touching Bottom of Rainbow Road [Ro]
kmWrite32(0x8059BE30, 0x60000000);

//Fix these fuckin boxes [Unnamed]
asmFunc ItemRespawn() {
loc_0x0:
  li r12, 0x45
  stw r12, 184(r27)
  stw r0, 176(r27)

}
kmCall(0x80828EDC, ItemRespawn);

//3 sec TC
kmWrite32(0x80580618, 0x388000B4);
kmWrite32(0x80580674, 0x388000B4);

//Enhanced Pause Menu [Ro]
kmWrite32(0x8062c658, 0x38800019);
kmWrite32(0x8062c79c, 0x38800019);
kmWrite32(0x80633a98, 0x38600019);
kmWrite32(0x8062c8e0, 0x38800019);
kmWrite32(0x80633970, 0x38600019);
kmWrite32(0x8083d618, 0x60000000);

extern "C" void sInstance__8Racedata(void*);
extern "C" void sInstance__10SectionMgr(void*);
asmFunc EnhancedPauseMenu1() {
  ASM(
  lwz r3, sInstance__10SectionMgr@l (r6);
  lwz r12, sInstance__8Racedata@l (r6);
  lwz r0, 0x1760 (r12);
  cmpwi r0, 2;
  beq end;

  cmpwi r4, 0x49;
  beq decreaseRaceNum;

  cmpwi r4, 0x4A;
  bne end;

  li r4, 0x4B;

  cmpwi r0, 1;
  beq decreaseRaceNum;

  li r4, 0x4C;

  decreaseRaceNum:
  lwz r6, 0x98 (r3);
  lwz r31, 0x60 (r6);
  subi r31, r31, 1;
  stw r31, 0x60 (r6);

  li r31, 5;
  stw r31, 0x1764 (r12);

  end:
  mr r31, r5;
  blr;
  )
}
kmCall(0x806024d8, EnhancedPauseMenu1);

extern "C" void sInstance__8Racedata(void*);
asmFunc EnhancedPauseMenu2() {
  ASM(
  lis r3, sInstance__8Racedata@ha;
  lwz r3, sInstance__8Racedata@l (r3);
  lwz r4, 0x1760 (r3);
  cmpwi r4, 2;
  beq end;
  li r4, 0x1;
  stw r4, 0xD18 (r3);
  stw r4, 0xE08 (r3);
  stw r4, 0xEF8 (r3);

  end:
  li        r3, 0x6C4;
  blr;
  )
}
kmCall(0x80623df4, EnhancedPauseMenu2);

kmWrite32(0x80859068, 0x48000808);
kmWrite32(0x80858e38, 0x48000040);

}//namespace Race
}//namespace Pulsar