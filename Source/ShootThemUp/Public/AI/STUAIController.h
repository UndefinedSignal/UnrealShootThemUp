// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "STUAIController.generated.h"

class USTUAIPerceptionComponent;
class ASTURespawnComponent;

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUAIController : public AAIController
{
	GENERATED_BODY()

  public:
	ASTUAIController();

  protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI");
	USTUAIPerceptionComponent *STUAIPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI");
	ASTURespawnComponent *RespawnComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI");
	FName FocusOnKeyName = "EnemyActor";

	virtual void OnPossess(APawn *InPawn) override;
	virtual void Tick(float DeltaTime) override;

  private:
	AActor *GetFocusOnActor() const;
};
