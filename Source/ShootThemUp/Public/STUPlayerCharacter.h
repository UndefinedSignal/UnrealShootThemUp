// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "STUBaseCharacter.h"
#include "STUPlayerCharacter.generated.h"

/**
 *
 */
class UCameraComponent;
class USpringArmComponent;
class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerCharacter : public ASTUBaseCharacter
{
	GENERATED_BODY()

  public:
	ASTUPlayerCharacter(const FObjectInitializer &ObjInit);

  protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USpringArmComponent *SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	UCameraComponent *CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USphereComponent *CameraCollisionComponent;

	virtual void OnDeath() override;
	virtual void BeginPlay() override;

  public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	virtual bool IsRunning() const override;

  private:
	bool WantsToRun = false;
	bool IsMovingForward = false;

	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void OnStartRunning();
	void OnStoptRunning();

	UFUNCTION()
	void OnCameraCollisionBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
									   UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									   const FHitResult &SweepResult);

	UFUNCTION()
	void OnCameraCollisionEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
									 UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

	void CheckCameraOverlap();
};