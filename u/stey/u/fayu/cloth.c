#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit F_AUTOLOAD;  
inherit NECK;
void create()
  {
     set_name(blue"С��Ө���·�"NOR, ({ "yi fu" ,"cloth" }) );
set_weight(100);
set("long","С��Ө���·�,����������Ŷ!\n");
set("value", 0);
      set("material", "cloth");
set("no_drop", "��һ��,�����Ӱ�\n");
set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 5);
     setup();
  }
int query_autoload() { return 1; }
