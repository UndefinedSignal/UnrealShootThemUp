// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeapon.generated.h"

class USkeletalMeshComponent;



UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTUBaseWeapon();

	FOnClipEmptySignature OnClipEmpty;

	virtual void StartFire();
	virtual void StopFire();

	void ChangeClip();
	bool CanReload() const;

	FAmmoData GetAmmoData() const
	{
		return CurrentAmmo;
	}

	FWeaponUIData GetUIData() const
	{
		return UIData;
	}

	bool TryToAddAmmo(int32 ClipsAmount);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	float TraceMaxDistance = 1500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon");
	FAmmoData DefaultAmmo{15, 10, false};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI");
	FWeaponUIData UIData;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void MakeShot();
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;


	APlayerController *GetPlayerController() const;
	FVector GetMuzzleWorldLocation() const;

	void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);

	bool GetPlayerViewPoint(FVector &ViewLocation, FRotator &ViewRotation) const;

	void DecreaseAmmo();
	bool IsAmmoEmpty() const;
	bool IsClipEmpty() const;
	bool IsAmmoFull() const;

	void LogAmmo();


private:
	FAmmoData CurrentAmmo;
	
};
