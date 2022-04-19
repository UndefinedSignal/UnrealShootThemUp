// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController()
{
	RespawnComponent = CreateAbstractDefaultSubobject<USTURespawnComponent>("USTURespawnComponent");
}

void ASTUPlayerController::OnPossess(APawn *InPawn)
{
	Super::OnPossess(InPawn);

	OnNewPawn.Broadcast(InPawn);
}