// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"
#include "Perception/AISense_Sight.h"

AActor *USTUAIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor *> PercieveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PercieveActors);
	if (PercieveActors.Num() == 0)
		return nullptr;
	
	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller)
		return nullptr;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
		return nullptr;

	float BestDistance = MAX_FLT;
	AActor *BestPawn = nullptr;

	for (const auto PercieveActor : PercieveActors)
	{
		const auto HealtComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PercieveActor);
		if (HealtComponent && !HealtComponent->IsDead()) // TODO check teammates
		{
			const auto CurrentDistance = (PercieveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
			if (CurrentDistance < BestDistance)
			{
				BestDistance = CurrentDistance;
				BestPawn = PercieveActor;
			}
		}
	}
	return BestPawn;
}