// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STURespawnComponent.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTURespawnComponent : public AActor
{
	GENERATED_BODY()

  public:
	ASTURespawnComponent();

	void Respawn(int32 RespawnTime);

  private:
	FTimerHandle RespawnTimerHandle;
	int32 RespawnCountDown = 0;

	void RespawnTimerUpdate();
};
