// Shoot Them Up Game. TestUnit. All RIghts Recieved

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "STURoundStatisticsWidget.generated.h"

/**
 *
 */
class ASTUGameModeBase;
class ASTUPlayerState;

UCLASS()
class SHOOTTHEMUP_API USTURoundStatisticsWidget : public UUserWidget
{
	GENERATED_BODY()

  public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetPlayerKills() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetPlayerDeaths() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetCurrentRounNum() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetRoundsCounter() const;
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetRoundRemainingTime() const;

  private:
	ASTUGameModeBase *GetSTUGameMode() const;
	ASTUPlayerState *GetSTUPlayerState() const;
};
