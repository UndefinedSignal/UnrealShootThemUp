// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "STUGameModeBase.h"
#include "STUBaseCharacter.h"
#include "STUPlayerController.h"
#include "UI/STUGameHUD.h"

ASTUGameModeBase::ASTUGameModeBase()
{
	DefaultPawnClass = ASTUBaseCharacter::StaticClass();
	PlayerControllerClass = ASTUPlayerController::StaticClass();
	HUDClass = ASTUGameHUD::StaticClass();
}
