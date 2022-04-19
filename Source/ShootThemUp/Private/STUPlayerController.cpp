// Shoot Them Up Game. TestUnit. All RIghts Recieved

#include "STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController()
{
	RespawnComponent = CreateAbstractDefaultSubobject<ASTURespawnComponent>("ASTURespawnComponent");
}
