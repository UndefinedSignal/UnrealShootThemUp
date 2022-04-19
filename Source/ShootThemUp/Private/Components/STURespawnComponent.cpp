// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "Components/STURespawnComponent.h"
#include "STUGameModeBase.h"

// Sets default values
ASTURespawnComponent::ASTURespawnComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


}

void ASTURespawnComponent::Respawn(int32 RespawnTime)
{
	if (!GetWorld())
		return;

	RespawnCountDown = RespawnTime;
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ASTURespawnComponent::RespawnTimerUpdate, 1.0f,
										   true);

}

void ASTURespawnComponent::RespawnTimerUpdate()
{
	if (--RespawnCountDown == 0)
	{
		if (!GetWorld())
			return;
		GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);

		const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
		if (!GameMode)
			return;
		GameMode->RespawnRequest(Cast<AController>(GetOwner()));
	}
}