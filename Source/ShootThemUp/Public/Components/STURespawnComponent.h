// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STURespawnComponent.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTURespawnComponent : public UActorComponent
{
	GENERATED_BODY()

  public:
	USTURespawnComponent();

	void Respawn(int32 RespawnTime);
	int32 GetRespawnCountDown() const
	{
		return RespawnCountDown;
	}
	bool IsRespawnInProgress() const;

  private:
	FTimerHandle RespawnTimerHandle;
	int32 RespawnCountDown = 0;

	void RespawnTimerUpdate();
};
