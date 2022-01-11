// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_PickupCouldBeTaken.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API UEnvQueryTest_PickupCouldBeTaken : public UEnvQueryTest
{
	GENERATED_BODY()
	UEnvQueryTest_PickupCouldBeTaken(const FObjectInitializer& FObjectInitializer);

	protected:
	virtual void RunTest(FEnvQueryInstance &QueryInstance) const;
};
