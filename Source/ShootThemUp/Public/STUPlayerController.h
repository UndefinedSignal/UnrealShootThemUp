// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUPlayerController.generated.h"

/**
 *
 */

class USTURespawnComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()
  public:
	ASTUPlayerController();
  protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI");
	USTURespawnComponent *RespawnComponent;

	virtual void OnPossess(APawn *InPawn) override;
};


