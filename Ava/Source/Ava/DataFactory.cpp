// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "DataFactory.h"


// Sets default values
ADataFactory::ADataFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Items = SetupItems();
	Statues = SetupStatues();

}

// Called when the game starts or when spawned
void ADataFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataFactory::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TMap<Item, ItemData> ADataFactory::SetupItems()
{
	// setup out item data container
	TMap<Item, ItemData> tItems;

	ItemData a;
	a.Add(ItemDataVariables::itemDescription,"Endless Knot - The intertwining of lines in the eternal knot is said to symbolize how everything is connected. It can also represent how religion and secular affairs, as well as compassion and wisdom are united and connected to each other.");
	a.Add(ItemDataVariables::itemEnumIdentifier, "Scroll01");
	a.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	a.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	a.Add(ItemDataVariables::itemName, "Endless Knot Scroll");
	tItems.Add(Item::Scroll01, a);

	ItemData b;
	b.Add(ItemDataVariables::itemDescription, "Lotus - The lotus has been used in many teachings of Buddhism to impart the true nature of all mankind. The roots of the lotus plant are stuck deep in the mud, but it still grows above murky water and blossoms into a beautiful, sweet-smelling flower. ");
	b.Add(ItemDataVariables::itemEnumIdentifier, "Scroll02");
	b.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	b.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	b.Add(ItemDataVariables::itemName, "Lotus Scroll");
	tItems.Add(Item::Scroll02, b);

	ItemData c;
	c.Add(ItemDataVariables::itemDescription, "Banner of Victory - This symbol represents how Buddha won over the demon Mara. This demon, in Buddhism, is synonymous to passion, lust and pride. The Banner of Victory is used to remind people that one must win over their own pride, lust and passions to be able to reach enlightenment.");
	c.Add(ItemDataVariables::itemEnumIdentifier, "Scroll03");
	c.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	c.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	c.Add(ItemDataVariables::itemName, "Banner of Victory Scroll");
	tItems.Add(Item::Scroll03, c);

	ItemData d;
	d.Add(ItemDataVariables::itemDescription, "Dharma Wheel - This wheel is also called the dharmachakra or the dhamma chakka and is often used to represent Buddha himself. It has also universally become the symbol for Buddhism. The dharma wheel has eight spokes, which represent Buddha’s Eightfold Path.");
	d.Add(ItemDataVariables::itemEnumIdentifier, "Scroll04");
	d.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	d.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	d.Add(ItemDataVariables::itemName, "Dharma Wheel Scroll");
	tItems.Add(Item::Scroll04, d);

	ItemData e;
	e.Add(ItemDataVariables::itemDescription, "Bumpa - A vase can be filled with many different things. The vase, in Buddhism, can mean the showering of health, wealth, prosperity and all the good things that come with enlightenment.");
	e.Add(ItemDataVariables::itemEnumIdentifier, "Scroll05");
	e.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	e.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	e.Add(ItemDataVariables::itemName, "Bumpa Scroll");
	tItems.Add(Item::Scroll05, e);

	ItemData f;
	f.Add(ItemDataVariables::itemDescription, "The Two Golden Fish - In older times, the two fish were drawn to symbolize the Ganges and the Yamuna rivers. It has, through interpretation, come to mean luck and fortune. It also means the courage and fearlessness to face the ocean of sufferings and to be able to swim freely like fish through water.");
	f.Add(ItemDataVariables::itemEnumIdentifier, "Scroll06");
	f.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	f.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	f.Add(ItemDataVariables::itemName, "Two Golden Fish Scroll");
	tItems.Add(Item::Scroll06, f);

	ItemData g;
	g.Add(ItemDataVariables::itemDescription, "Parasol - An umbrella can protect people from the different elements, like the sun or the rain. In this context, a parasol or umbrella can mean protection from suffering and harmful forces. It can also mean the enjoyment of the cool shade it provides.");
	g.Add(ItemDataVariables::itemEnumIdentifier, "Scroll07");
	g.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	g.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	g.Add(ItemDataVariables::itemName, "Parasol Scroll");
	tItems.Add(Item::Scroll07, g);

	ItemData h;
	h.Add(ItemDataVariables::itemDescription, "Conch Shell - This large shell has been used in many countries as a traditional battle horn. In Buddhism, the white Conch shell that spirals to the right can mean the deep and joyful sound of the Dharma teachings. It is representative of the awakening disciples receive when they hear these teachings. The Conch shell can also mean the rousing of people from ignorance.");
	h.Add(ItemDataVariables::itemEnumIdentifier, "Scroll08");
	h.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe");
	h.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	h.Add(ItemDataVariables::itemName, "Conch Shell Scroll");
	tItems.Add(Item::Scroll08, h);

	ItemData i;
	i.Add(ItemDataVariables::itemDescription, "A Precious gift from Avas previous life, it is extremely valued");
	i.Add(ItemDataVariables::itemEnumIdentifier, "Bracelet");
	i.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	i.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/ScrollSprite.ScrollSprite");
	i.Add(ItemDataVariables::itemName, "Ava's Bracelet");
	tItems.Add(Item::Bracelet, i);

	return tItems;
}
//Forward Declaration
TMap<Item, ItemData> ADataFactory::Items;


TMap<Statue, StatueData> ADataFactory::SetupStatues()
{
	// setup out statue data container
	TMap<Statue, StatueData> tStatues;

	StatueData a;
	a.Add(StatueDataVariables::statueName, "Green Statue ");
	a.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	a.Add(StatueDataVariables::statueEnumIdentifier, "StatueGreen");
	tStatues.Add(Statue::StatueGreen,a);

	StatueData b;
	b.Add(StatueDataVariables::statueName, "Blue Statue ");
	b.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	b.Add(StatueDataVariables::statueEnumIdentifier, "StatueBlue");
	tStatues.Add(Statue::StatueBlue, b);

	StatueData c;
	c.Add(StatueDataVariables::statueName, "White Statue ");
	c.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	c.Add(StatueDataVariables::statueEnumIdentifier, "StatueWhite");
	tStatues.Add(Statue::StatueWhite, c);

	StatueData d;
	d.Add(StatueDataVariables::statueName, "Red Statue ");
	d.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	d.Add(StatueDataVariables::statueEnumIdentifier, "StatueRed");
	tStatues.Add(Statue::StatueRed, d);

	StatueData e;
	e.Add(StatueDataVariables::statueName, "Yellow Statue ");
	e.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	e.Add(StatueDataVariables::statueEnumIdentifier, "StatueYellow");
	tStatues.Add(Statue::StatueYellow, e);


	StatueData f;
	f.Add(StatueDataVariables::statueName, "Black Statue ");
	f.Add(StatueDataVariables::statueMeshFilepath, "/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02");
	f.Add(StatueDataVariables::statueEnumIdentifier, "StatueBlack");
	tStatues.Add(Statue::StatueBlack, f);

	return tStatues;
}
TMap<Statue, StatueData> ADataFactory::Statues;
