// jiudai.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
         set_name("��ͷ��", ({"ren tou ma", "xo","jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                 set("long", "һƿ��ֵ�������ơ�\n");
                  set("unit", "ƿ");
                        set("value", 100000);
                  set("max_liquid", 1500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
                  "name": "���",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
