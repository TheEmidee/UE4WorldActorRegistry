#pragma once

#include <CoreMinimal.h>
#include <GameplayTagContainer.h>
#include <Subsystems/WorldSubsystem.h>

#include "WARWorldActorRegistry.generated.h"

UCLASS()
class WORLDACTORREGISTRY_API UWARWorldActorRegistry : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION( BlueprintPure )
    AActor * GetActorWithTag( const FGameplayTag gameplay_tag ) const;

    UFUNCTION( BlueprintPure )
    AActor * GetActorsWithTag( const FGameplayTag gameplay_tag ) const;

    UFUNCTION( BlueprintCallable )
    bool AddActorToRegistry( AActor * actor, const FGameplayTag tag );

    UFUNCTION( BlueprintCallable )
    bool RemoveActorFromRegistry( AActor * actor, const FGameplayTag tag );

    UFUNCTION( BlueprintCallable )
    void Clear();

private:
    UPROPERTY()
    TMap< FGameplayTag, AActor * > Registry;
};
