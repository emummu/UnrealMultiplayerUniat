// Fill out your copyright notice in the Description page of Project Settings.


#include "Ipv2/Public/Interactions/LaunchPad.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ALaunchPad::ALaunchPad()
{
	Overlapcomp = CreateDefaultSubobject<UBoxComponent>("OverlapComp");
	Overlapcomp->SetBoxExtent(FVector(75,75,50));
	RootComponent= Overlapcomp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetupAttachment(RootComponent);

	Overlapcomp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::ALaunchPad::OverlapLaunchPad);

	LaunchStreng= 1500;
	LaunchPitchAngle = 35.0f;
}

void ALaunchPad::OverlapLaunchPad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator  LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchPitchAngle;

	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStreng;

	ACharacter* MyCharacter = Cast<ACharacter>(OtherActor);
	if(MyCharacter)
	{
	MyCharacter->LaunchCharacter(LaunchVelocity, true, true);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LaunchFX ,GetActorLocation());
		
	}

	
}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


