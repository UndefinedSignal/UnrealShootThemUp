// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"

class USTUHealthComponent;
class USTUWeaponComponent;

USTRUCT(BlueprintType)
struct FSTURange
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utils");
	float Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utils");
	float Max;

	TRange<float> makeRange() const
	{
		return TRange<float>(Min, Max);
	}
};

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

  public:
	// Sets default values for this character's properties
	ASTUBaseCharacter(const FObjectInitializer &ObjInit);

  protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USTUHealthComponent *HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components");
	USTUWeaponComponent *WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation");
	UAnimMontage *DeathAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Damage");
	float LifeSpanOnDeath = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage");
	FSTURange DamageOnLanded = FSTURange{10.0f, 100.0f};
	UPROPERTY(EditDefaultsOnly, Category = "Damage");
	FSTURange LandedDamageVelocity = FSTURange{600.0f, 900.0f};

	UPROPERTY(EditDefaultsOnly, Category = "Material");
	FName MaterialColorName = "Paint Color";

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnDeath();
  public:
	virtual void Tick(float Delta) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual bool IsRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMovementDirection() const;

	void SetPlayerColor(const FLinearColor &Color);

  private:
	void OnHealthChanged(float Health, float HealthDelta);

	UFUNCTION()
	void OnGroundLaned(const FHitResult &HitResult);
};
