
#include <ansi.h>

inherit F_AUTOLOAD;  
inherit ITEM;

void create()
{
    set_name(HIY"��"NOR, ({ "gold card", "card", "ka"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("no_drop", "������������Ү��������ӵ���\n");
        set("no_give", "������������Ү��������������\n");
        set("no_get", "���Ǳ��˵����а�����֪������������\n");
		set("material", "steel");
	}
	setup();
}

void init()
 {
   add_action("do_look","look");
 }

   int do_look(string arg)  
 {
    if(arg!="card"&&arg!="gold card")
        return 0;
   tell_object(this_player(),"����һ�����Ľ𿨣�Һ������Ļ��ʾ����ʣ����Ϊ��\n"
    +MONEY_D->price_str(this_player()->query("balance"))+"��\n");
      return 1;
 }

int query_autoload() { return 1; }
