// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

  public:
	ASTURifleWeapon();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float TimerBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float BulletSpread = 1.5f;

	virtual void StartFire() override;
	virtual void StopFire() override;

  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float DamageAmount = 10.0f;

	virtual void BeginPlay() override;
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const override;

	UPROPERTY(VisibleAnywhere, Category = "VFX");
	USTUWeaponFXComponent *WeaponFXComponent;

  private:
	FTimerHandle ShotTimerHandle;

	void DealDamage(FHitResult &HitResult);
};
