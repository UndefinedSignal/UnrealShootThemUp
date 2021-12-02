// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUHealthPickup.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUHealthPickup : public ASTUBasePickup
{
	GENERATED_BODY()
  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1", ClampMax = "100.0"));
	float HealthAmount = 69.0f;
  private:
	bool GivePickupTo(APawn *Player) override;
};
