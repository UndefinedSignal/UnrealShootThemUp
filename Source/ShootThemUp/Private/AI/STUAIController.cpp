// Shoot Them Up Game. TestUnit. All RIghts Recieved


#include "AI/STUAIController.h"
#include "AI/STUAICharacter.h"
#include "Components/STUAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ASTUAIController::ASTUAIController()
{
	STUAIPerceptionComponent = CreateAbstractDefaultSubobject<USTUAIPerceptionComponent>("STUPerceptionComponent");
	SetPerceptionComponent(*STUAIPerceptionComponent);
}

void ASTUAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const auto AimActor = GetFocusOnActor(); // STUAIPerceptionComponent->GetClosestEnemy();
	SetFocus(AimActor);
}

void ASTUAIController::OnPossess(APawn *InPawn)
{
	Super::OnPossess(InPawn);
	const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);
	if (STUCharacter)
	{
		RunBehaviorTree(STUCharacter->BehaviorTreeAsset);
	}
}

AActor *ASTUAIController::GetFocusOnActor() const
{
	if (!GetBlackboardComponent())
		return nullptr;
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}