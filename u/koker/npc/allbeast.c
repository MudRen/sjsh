// all_beast.c

inherit NPC;

void create(int level,int damage,int armor)
{
	string temp;
	int flag,num;
	num=3;
	flag=random(num);
	switch(flag)
	{
	case 0:
		set_name("�����",({"goblin"}));
		temp=sprintf("���Ź�ͷ���Ĺ��\n");
		break;
	case 1:
		set_name("���������",({"super goblin"}));
		temp=sprintf("���Ź�ͷ���Ĺ��\n");
		break;
	case 2:
		set_name("���������",({"gold goblin"}));
		temp=sprintf("���Ź�ͷ���Ĺ��\n");
		break;
	default:
		set_name("����ħ��ʦ",({"magicman"}));
		temp=sprintf("��ħ���Ĺ��\n");
		break;
	}

	set("race", "Ұ��");
	set("age", 4);
	set("long", temp);
	set("attitude", "aggressive");
	
	set("str", 20+random(20));

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("level", level);
	
	

	set_temp("apply/damage", damage);
	set_temp("apply/armor", armor);

	setup();

	switch(flag)
	{
	case 0:
		break;
	case 1:
		carry_object("/u/wosshipg/axe")->wield();
		break;
	case 2:
		carry_object("/u/wosshipg/spear")->wield();
		break;
	case 3:
		carry_object("/obj/weapon/sword")->wield();
		break;
	case 4:
		carry_object("/u/wosshipg/staff")->wield();
		break;
	}

}
