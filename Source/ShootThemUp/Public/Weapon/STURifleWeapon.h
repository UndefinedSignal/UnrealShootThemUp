// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;
class UNiagaraComponent;
class UNiagaraSystem;

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

  public:
	ASTURifleWeapon();

	virtual void StartFire() override;
	virtual void StopFire() override;

  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float TimerBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage");
	float DamageAmount = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX");
	UNiagaraSystem *TraceFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX");
	FString TraceTargetName = "TraceTarget";

	virtual void BeginPlay() override;
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const override;

	UPROPERTY(VisibleAnywhere, Category = "VFX");
	USTUWeaponFXComponent *WeaponFXComponent;

  private:
	FTimerHandle ShotTimerHandle;

	UPROPERTY()
	UNiagaraComponent *MuzzleFXComponent;

	void DealDamage(FHitResult &HitResult);
	void InitMuzzleFX();
	void SetMuzzleFXVisibility(bool Visible);
	void SpawnTraceFX(const FVector &TraceStart, const FVector &TraceEnd);
};
