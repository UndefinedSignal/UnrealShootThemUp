// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage");
	float DamageAmount = 10.0f;

	// Sets default values for this actor's properties
	ASTUBaseWeapon();

	virtual void StartFire();
	virtual void StopFire();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	float TraceMaxDistance = 1500.0f;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void MakeShot();
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;


	APlayerController *GetPlayerController() const;
	FVector GetMuzzleWorldLocation() const;
	


	void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);

	bool GetPlayerViewPoint(FVector &ViewLocation, FRotator &ViewRotation) const;
	
	void DealDamage(FHitResult &HitResult);



};
