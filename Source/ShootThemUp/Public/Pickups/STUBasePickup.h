// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBasePickup : public AActor
{
	GENERATED_BODY()

  public:
	// Sets default values for this actor's properties
	ASTUBasePickup();

  protected:
	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	USphereComponent *CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	float RespawnTime = 5.0f;

	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor *OtherActor) override;

  public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  private:
	float RotationYaw = 0.0f;

	virtual bool GivePickupTo(APawn* Player);

	void PickupWasTaken();
	void Respawn();
	void GenerateRotationYaw();
};