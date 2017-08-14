#include "Ava.h"
#include "DataFactory.h"


// Sets default values
ADataFactory::ADataFactory()
{
	PrimaryActorTick.bCanEverTick = true;
	Items = SetupItems();

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

//Forward Declaration
TMap<Item, ItemData> ADataFactory::Items;

TMap<Item, ItemData> ADataFactory::SetupItems()
{
	// setup out item data container
	TMap<Item, ItemData> tItems;
	
	ItemData blank;
	blank.Add(ItemDataVariables::itemDescription, "");
	blank.Add(ItemDataVariables::itemEnumIdentifier, "BLANK");
	blank.Add(ItemDataVariables::itemMeshFilepath, "");
	blank.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/4.4");
	blank.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/4.4");
	blank.Add(ItemDataVariables::itemName, "");
	tItems.Add(Item::BLANK, blank);

	ItemData a; 
	a.Add(ItemDataVariables::itemDescription,"Endless Knot - The intertwining of lines in the eternal knot is said to symbolize how everything is connected. It can also represent how religion and secular affairs, as well as compassion and wisdom are united and connected to each other.");
	a.Add(ItemDataVariables::itemEnumIdentifier, "Scroll01");
	a.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll1.Scroll1");
	a.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/Knot.Knot");
	a.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/wheel_Hovered.wheel_Hovered");
	a.Add(ItemDataVariables::itemName, "Endless Knot Scroll");
	tItems.Add(Item::Scroll01, a);

	ItemData b; 
	b.Add(ItemDataVariables::itemDescription, "Lotus - The lotus has been used in many teachings of Buddhism to impart the true nature of all mankind. The roots of the lotus plant are stuck deep in the mud, but it still grows above murky water and blossoms into a beautiful, sweet-smelling flower. ");
	b.Add(ItemDataVariables::itemEnumIdentifier, "Scroll02");
	b.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll2.Scroll2");
	b.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/lotus.lotus");
	b.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/lotus_Hovered.lotus_Hovered");
	b.Add(ItemDataVariables::itemName, "Lotus Scroll");
	tItems.Add(Item::Scroll02, b);

	ItemData c;
	c.Add(ItemDataVariables::itemDescription, "Banner of Victory - This symbol represents how Buddha won over the demon Mara. This demon, in Buddhism, is synonymous to passion, lust and pride. The Banner of Victory is used to remind people that one must win over their own pride, lust and passions to be able to reach enlightenment.");
	c.Add(ItemDataVariables::itemEnumIdentifier, "Scroll03");
	c.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll3.Scroll3");
	c.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/victory_banner.victory_banner"); 
	c.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/victory_banner_Hovered.victory_banner_Hovered");
	c.Add(ItemDataVariables::itemName, "Banner of Victory Scroll");
	tItems.Add(Item::Scroll03, c);

	ItemData d;
	d.Add(ItemDataVariables::itemDescription, "Dharma Wheel - This wheel is also called the dharmachakra or the dhamma chakka and is often used to represent Buddha himself. It has also universally become the symbol for Buddhism. The dharma wheel has eight spokes, which represent Buddha’s Eightfold Path.");
	d.Add(ItemDataVariables::itemEnumIdentifier, "Scroll04");
	d.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll4.Scroll4");
	d.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/wheel.wheel");
	d.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/wheel_Hovered.wheel_Hovered");
	d.Add(ItemDataVariables::itemName, "Dharma Wheel Scroll");
	tItems.Add(Item::Scroll04, d);

	ItemData e;
	e.Add(ItemDataVariables::itemDescription, "Bumpa - A vase can be filled with many different things. The vase, in Buddhism, can mean the showering of health, wealth, prosperity and all the good things that come with enlightenment.");
	e.Add(ItemDataVariables::itemEnumIdentifier, "Scroll05");
	e.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll5.Scroll5");
	e.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/vase.vase");
	e.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/vase_Hovered.vase_Hovered");
	e.Add(ItemDataVariables::itemName, "Bumpa Scroll");
	tItems.Add(Item::Scroll05, e);

	ItemData f;
	f.Add(ItemDataVariables::itemDescription, "The Two Golden Fish - In older times, the two fish were drawn to symbolize the Ganges and the Yamuna rivers. It has, through interpretation, come to mean luck and fortune. It also means the courage and fearlessness to face the ocean of sufferings and to be able to swim freely like fish through water.");
	f.Add(ItemDataVariables::itemEnumIdentifier, "Scroll06");
	f.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll6.Scroll6");
	f.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/fish.fish");
	f.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/fish_Hovered.fish_Hovered");
	f.Add(ItemDataVariables::itemName, "Two Golden Fish Scroll");
	tItems.Add(Item::Scroll06, f);

	ItemData g;
	g.Add(ItemDataVariables::itemDescription, "Parasol - An umbrella can protect people from the different elements, like the sun or the rain. In this context, a parasol or umbrella can mean protection from suffering and harmful forces. It can also mean the enjoyment of the cool shade it provides.");
	g.Add(ItemDataVariables::itemEnumIdentifier, "Scroll07");
	g.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll7.Scroll7");
	g.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/parasol.parasol");
	g.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/parasol_Hovered.parasol_Hovered");
	g.Add(ItemDataVariables::itemName, "Parasol Scroll");
	tItems.Add(Item::Scroll07, g);

	ItemData h;
	h.Add(ItemDataVariables::itemDescription, "Conch Shell - This large shell has been used in many countries as a traditional battle horn. In Buddhism, the white Conch shell that spirals to the right can mean the deep and joyful sound of the Dharma teachings. It is representative of the awakening disciples receive when they hear these teachings. The Conch shell can also mean the rousing of people from ignorance.");
	h.Add(ItemDataVariables::itemEnumIdentifier, "Scroll08");
	h.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Scroll8.Scroll8");
	h.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/croch.croch");
	h.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/croch_Hovered.croch_Hovered");
	h.Add(ItemDataVariables::itemName, "Conch Shell Scroll");
	tItems.Add(Item::Scroll08, h);

	ItemData i;
	i.Add(ItemDataVariables::itemDescription, "A Precious gift from Avas previous life, it is extremely valued");
	i.Add(ItemDataVariables::itemEnumIdentifier, "Bracelet");
	i.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	i.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/bracelet.bracelet");
	i.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/bracelet_Hovered.bracelet_Hovered");
	i.Add(ItemDataVariables::itemName, "Ava's Bracelet");
	tItems.Add(Item::Bracelet, i);
	
	ItemData j; 
	j.Add(ItemDataVariables::itemDescription, "An item for the white room");
	j.Add(ItemDataVariables::itemEnumIdentifier, "Item01");
	j.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala1.Food_mandala1");
	j.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_red.food_mandala_red");
	j.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_red_Hovered.food_mandala_red_Hovered");
	j.Add(ItemDataVariables::itemName, "Food Mandala 1");
	tItems.Add(Item::Item01, j);

	ItemData k;
	k.Add(ItemDataVariables::itemDescription, "An item for the white room");
	k.Add(ItemDataVariables::itemEnumIdentifier, "Item02");
	k.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala2.Food_mandala2");
	k.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_white.food_mandala_white");
	k.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_white_Hovered.food_mandala_white_Hovered");
	k.Add(ItemDataVariables::itemName, "Food Mandala 2");
	tItems.Add(Item::Item02, k);

	ItemData l;
	l.Add(ItemDataVariables::itemDescription, "An item for the white room");
	l.Add(ItemDataVariables::itemEnumIdentifier, "Item03");
	l.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Food_mandala3.Food_mandala3");
	l.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/UI/food_mandala_yellow.food_mandala_yellow");
	l.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/UI/food_mandala_yellow_Hovered.food_mandala_yellow_Hovered");
	l.Add(ItemDataVariables::itemName, "Food Mandala 3");
	tItems.Add(Item::Item03, l);

	ItemData m;
	m.Add(ItemDataVariables::itemDescription, "A Vajra bell for belling");
	m.Add(ItemDataVariables::itemEnumIdentifier, "Trash01");
	m.Add(ItemDataVariables::itemMeshFilepath, "/Game/Ava/Modelling/Interactives/Vajra.Vajra");
	m.Add(ItemDataVariables::itemSpriteFilepath, "/Game/Ava/Modelling/Interactives/vajra.vajra");
	m.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/Ava/Modelling/Interactives/vajra_Hovered.vajra_Hovered");
	m.Add(ItemDataVariables::itemName, "Vajra Bell");
	tItems.Add(Item::Trash01, m);

	ItemData n;
	n.Add(ItemDataVariables::itemDescription, "An item for the white room");
	n.Add(ItemDataVariables::itemEnumIdentifier, "Trash02");
	n.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	n.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash2.Trash2");
	n.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	n.Add(ItemDataVariables::itemName, "Trash 2");
	tItems.Add(Item::Trash02, n);

	ItemData o;
	o.Add(ItemDataVariables::itemDescription, "An item for the white room");
	o.Add(ItemDataVariables::itemEnumIdentifier, "Trash03");
	o.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	o.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash3.Trash3");
	o.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	o.Add(ItemDataVariables::itemName, "Trash 3");
	tItems.Add(Item::Trash03, o);

	ItemData p;
	p.Add(ItemDataVariables::itemDescription, "An item of no use, but is very pretty");
	p.Add(ItemDataVariables::itemEnumIdentifier, "Trash04");
	p.Add(ItemDataVariables::itemMeshFilepath, "/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus");
	p.Add(ItemDataVariables::itemSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Trash4.Trash4");
	p.Add(ItemDataVariables::itemSelectedSpriteFilepath, "/Game/TemporaryContent/InventoryTemp/Scroll1Hovered.Scroll1Hovered");
	p.Add(ItemDataVariables::itemName, "Trash 4");
	tItems.Add(Item::Trash04, p);

	return tItems;
}
FString ADataFactory::AccessTMapItems(Item Item_type, ItemDataVariables Item_variable)
{
	ItemData e = Items[Item_type];
	return e[Item_variable];
}
UStaticMesh * ADataFactory::Get3DRepresentationForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	if (Item_type != Item::BLANK)
	{

		UStaticMesh* mesh = Cast <UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, e[ItemDataVariables::itemMeshFilepath].GetCharArray().GetData()));
		return mesh;
	}
	else
	{
		return nullptr;
	}
}
UTexture2D * ADataFactory::GetIconForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	if (Item_type != Item::BLANK)
	{
		UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSpriteFilepath].GetCharArray().GetData()));
		return Texture;
	}
	else
	{
		return nullptr;
	}
}

UTexture2D * ADataFactory::GetIconSelectedForItem(Item Item_type)
{
	ItemData e = Items[Item_type];
	if (Item_type != Item::BLANK)
	{
		UTexture2D* Texture = Cast <UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, e[ItemDataVariables::itemSelectedSpriteFilepath].GetCharArray().GetData()));
		return Texture;
	}
	else
	{
		return nullptr;
	}
}
Item ADataFactory::GetItemType(const FString & enumType, const FString & enumName)
{
	UEnum *Ingr = FindObject<UEnum>(ANY_PACKAGE, *enumType, true);

	return (Item)Ingr->FindEnumIndex(FName(*enumName));
}

FString ADataFactory::getItemDescription(Item ItemToSpawn)
{
	ItemData e = Items[ItemToSpawn];
	return e[ItemDataVariables::itemDescription];
}
