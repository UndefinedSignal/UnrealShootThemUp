// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUAmmoAmountDecorator.generated.h"

class ASTUBaseWeapon;

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUAmmoAmountDecorator : public UBTDecorator
{
	GENERATED_BODY()

	USTUAmmoAmountDecorator();

  protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI");
	TSubclassOf<ASTUBaseWeapon> WeaponType;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;
};
