// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage");
	float TimerBetweenShots = 0.1f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage");
	float BulletSpread = 1.5f;

	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const override;

private:
	FTimerHandle ShotTimerHandle;
};
