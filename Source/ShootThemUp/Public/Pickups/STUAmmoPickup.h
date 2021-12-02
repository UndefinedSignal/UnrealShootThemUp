// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUAmmoPickup.generated.h"

class ASTUBaseWeapon;
/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUAmmoPickup : public ASTUBasePickup
{
	GENERATED_BODY()

  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1", ClampMax = "10.0"));
	int32 ClipsAmount = 10;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pickup");
	TSubclassOf<ASTUBaseWeapon> WeaponType;
  private:
	bool GivePickupTo(APawn *Player) override;
};
