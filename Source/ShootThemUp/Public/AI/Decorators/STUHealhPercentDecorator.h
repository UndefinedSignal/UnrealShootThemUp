// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"
#include "STUHealhPercentDecorator.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUHealhPercentDecorator : public UBTDecorator
{
	GENERATED_BODY()

  public:
	USTUHealhPercentDecorator();

	protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI");
	  float HealthPercent = 0.6f;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;
};
