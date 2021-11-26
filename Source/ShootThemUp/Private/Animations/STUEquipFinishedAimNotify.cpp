// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "Animations/STUEquipFinishedAimNotify.h"

void USTUEquipFinishedAimNotify::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation)
{
	OnNotified.Broadcast(MeshComp);

	Super::Notify(MeshComp, Animation);

}
