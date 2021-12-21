// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"
#include "STUNextLocationTask.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUNextLocationTask : public UBTTaskNode
{
	GENERATED_BODY()

	USTUNextLocationTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

  protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI");
	float Radius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI");
	FBlackboardKeySelector AimLocationKey;
};